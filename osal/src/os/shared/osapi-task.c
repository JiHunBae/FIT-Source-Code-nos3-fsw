/*
 *  NASA Docket No. GSC-18,370-1, and identified as "Operating System Abstraction Layer"
 *
 *  Copyright (c) 2019 United States Government as represented by
 *  the Administrator of the National Aeronautics and Space Administration.
 *  All Rights Reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/**
 * \file   osapi-task.c
 * \author joseph.p.hickey@nasa.gov
 *
 * Purpose:
 *         This file  contains some of the OS APIs abstraction layer code
 *         that is shared/common across all OS-specific implementations.
 *
 *         This code only uses very basic C library calls that are expected
 *         to be available on every sane C-language compiler.  For everything else,
 *         a platform-specific implementation function is used.
 *
 */

/****************************************************************************************
                                    INCLUDE FILES
 ***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
 * User defined include files
 */
#include "common_types.h"
#include "os-impl.h"


/*
 * Sanity checks on the user-supplied configuration
 * The relevent OS_MAX limit should be defined and greater than zero
 */
#if !defined(OS_MAX_TASKS) || (OS_MAX_TASKS <= 0)
#error "osconfig.h must define OS_MAX_TASKS to a valid value"
#endif


enum
{
   LOCAL_NUM_OBJECTS = OS_MAX_TASKS,
   LOCAL_OBJID_TYPE = OS_OBJECT_TYPE_OS_TASK
};

OS_task_internal_record_t    OS_task_table          [LOCAL_NUM_OBJECTS];


// Test >> 
int max_cnt = 100;
int cnt = -1;
char *strs[100] = {"Test task1", "Test task2", "Test task3", "Test task4", "Test task5", "Test task6", "Test task7", "Test task8", "Test task9", "Test task10", "Test task11", "Test task12", "Test task13", "Test task14", "Test task15", "Test task16", "Test task17", "Test task18", "Test task19", "Test task20", "Test task21", "Test task22", "Test task23", "Test task24", "Test task25", "Test task26", "Test task27", "Test task28", "Test task29", "Test task30", "Test task31", "Test task32", "Test task33", "Test task34", "Test task35", "Test task36", "Test task37", "Test task38", "Test task39", "Test task40", "Test task41", "Test task42", "Test task43", "Test task44", "Test task45", "Test task46", "Test task47", "Test task48", "Test task49", "Test task50", "Test task51", "Test task52", "Test task53", "Test task54", "Test task55", "Test task56", "Test task57", "Test task58", "Test task59", "Test task60", "Test task61", "Test task62", "Test task63", "Test task64", "Test task65", "Test task66", "Test task67", "Test task68", "Test task69", "Test task70", "Test task71", "Test task72", "Test task73", "Test task74", "Test task75", "Test task76", "Test task77", "Test task78", "Test task79", "Test task80", "Test task81", "Test task82", "Test task83", "Test task84", "Test task85", "Test task86", "Test task87", "Test task88", "Test task89", "Test task90", "Test task91", "Test task92", "Test task93", "Test task94", "Test task95", "Test task96", "Test task97", "Test task98", "Test task99", "Test task100",};

/*----------------------------------------------------------------
 *
 * Function: OS_TaskPrepare
 *
 *  Purpose: Local helper routine, not part of OSAL API.
 *           Helper function for registering new tasks in the global database.
 *           This maps the given task_id back to the array entry (OS_task_internal_record_t)
 *           so that the caller can call the real entry point.
 *
 *           In the process, this also verifies that the task_id is valid and
 *           it matches the expected entry, and this calls the implementation's
 *           "Register" function to make sure that the appropriate thread-specific
 *           variables are set - this guarantees that GetTaskId will work.
 *
 *
 *-----------------------------------------------------------------*/
static int32 OS_TaskPrepare(uint32 task_id, osal_task_entry *entrypt)
{
   int32 return_code;
   uint32 local_id;

   return_code = OS_ObjectIdToArrayIndex(OS_OBJECT_TYPE_OS_TASK, task_id, &local_id);
   if (return_code == OS_SUCCESS)
   {
      /*
       * Take our own task table lock.
       *
       * This ensures that the parent thread's OS_TaskCreate() call is fully completed,
       * and that nobody can call OS_TaskDelete() and possibly overwrite this data.
       */
      OS_Lock_Global_Impl(OS_OBJECT_TYPE_OS_TASK);

      /*
       * Verify that we still appear to own the table entry
       */
      if (OS_global_task_table[local_id].active_id != task_id)
      {
          return_code = OS_ERR_INVALID_ID;
      }
      else
      {
          return_code = OS_TaskMatch_Impl(local_id);
          *entrypt = OS_task_table[local_id].entry_function_pointer;
      }

      OS_Unlock_Global_Impl(OS_OBJECT_TYPE_OS_TASK);
   }

   if (return_code == OS_SUCCESS)
   {
      OS_TaskRegister_Impl(task_id);
   }
   else
   {
      *entrypt = NULL;
   }

   return return_code;
} /* end OS_TaskPrepare */

/*----------------------------------------------------------------
 *
 * Function: OS_TaskEntryPoint
 *
 *  Purpose: Local helper routine, not part of OSAL API.
 *           The entry point for all OSAL tasks
 *           This function is called from the OS-specific layers after a task is spawned
 *           and is the first thing to run under the context of the task itself.
 *           This will register the task appropriately in the global data structures and
 *           call the user's intended entry point function.
 *
 *-----------------------------------------------------------------*/
void OS_TaskEntryPoint(uint32 task_id)
{
    osal_task_entry task_entry;

   if (OS_TaskPrepare(task_id, &task_entry) == OS_SUCCESS)
   {
      if (task_entry != NULL)
      {
          (*task_entry)();
      }
   }

   /* If the function returns, treat as a normal exit and do the proper cleanup */
   OS_TaskExit();
} /* end OS_TaskEntryPoint */

/*
 *********************************************************************************
 *          TASK API
 *********************************************************************************
 */

/*----------------------------------------------------------------
 *
 * Function: OS_TaskAPI_Init
 *
 *  Purpose: Local helper routine, not part of OSAL API.
 *           Init function for OS-independent layer
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskAPI_Init(void)
{
   memset(OS_task_table, 0, sizeof(OS_task_table));
   return OS_SUCCESS;
} /* end OS_TaskAPI_Init */


                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskCreate
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskCreate (uint32 *task_id, const char *task_name, osal_task_entry function_pointer,
                      uint32 *stack_pointer, uint32 stack_size, uint32 priority, uint32 flags)
{
   OS_common_record_t *record;
   int32             return_code;
   uint32            local_id;

   /* Check for bad priority */
   if (priority > OS_MAX_TASK_PRIORITY)
   {
       return OS_ERR_INVALID_PRIORITY;
   }

   /* Check for NULL pointers */
   if (task_name == NULL || task_id == NULL || function_pointer == NULL)
   {
      return OS_INVALID_POINTER;
   }

   /* we don't want to allow names too long*/
   /* if truncated, two names might be the same */
   if (strlen(task_name) >= OS_MAX_API_NAME)
   {
      return OS_ERR_NAME_TOO_LONG;
   }
   
   /* Note - the common ObjectIdAllocate routine will lock the object type and leave it locked. */
   return_code = OS_ObjectIdAllocateNew(LOCAL_OBJID_TYPE, task_name, &local_id, &record);
   
   if(return_code == OS_SUCCESS)
   {
      /* Save all the data to our own internal task table */
      memset(&OS_task_table[local_id], 0, sizeof(OS_task_internal_record_t));

      strncpy(OS_task_table[local_id].task_name, task_name, OS_MAX_API_NAME);
      record->name_entry = OS_task_table[local_id].task_name;
      OS_task_table[local_id].stack_size = stack_size;
      OS_task_table[local_id].priority = priority;
      OS_task_table[local_id].entry_function_pointer = function_pointer;
      OS_task_table[local_id].stack_pointer = stack_pointer;
      /* Now call the OS-specific implementation.  This reads info from the task table. */
      return_code = OS_TaskCreate_Impl(local_id, flags);

      /* Check result, finalize record, and unlock global table. */
      return_code = OS_ObjectIdFinalizeNew(return_code, record, task_id);
   }

   return return_code;
} /* end OS_TaskCreate */


                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskDelete
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskDelete (uint32 task_id)
{
   OS_common_record_t *record;
   int32             return_code;
   uint32            local_id;
   osal_task_entry   delete_hook;

   delete_hook = NULL;
   return_code = OS_ObjectIdGetById(OS_LOCK_MODE_EXCLUSIVE, LOCAL_OBJID_TYPE, task_id, &local_id, &record);
   if (return_code == OS_SUCCESS)
   {
      /* Save the delete hook, as we do not want to call it while locked */
      delete_hook = OS_task_table[local_id].delete_hook_pointer;

      return_code = OS_TaskDelete_Impl(local_id);

      /* Free the entry in the master table now while still locked */
      if (return_code == OS_SUCCESS)
      {
         /* Only need to clear the ID as zero is the "unused" flag */
         record->active_id = 0;
      }
      else
      {
         delete_hook = NULL;
      }

      OS_Unlock_Global_Impl(LOCAL_OBJID_TYPE);
   }

   /*
   ** Call the thread Delete hook if there is one.
   */
   if (delete_hook != NULL)
   {
      delete_hook();
   }

   return return_code;
} /* end OS_TaskDelete */

                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskExit
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
void OS_TaskExit()
{
   OS_common_record_t *record;
   uint32 task_id;
   uint32 local_id;

   task_id = OS_TaskGetId_Impl();
   if (OS_ObjectIdGetById(OS_LOCK_MODE_GLOBAL, LOCAL_OBJID_TYPE, task_id, &local_id, &record) == OS_SUCCESS)
   {
      /* Only need to clear the ID as zero is the "unused" flag */
      record->active_id = 0;
      OS_Unlock_Global_Impl(LOCAL_OBJID_TYPE);
   }

   /* call the implementation */
   OS_TaskExit_Impl();

   /* Impl function never returns */
} /* end OS_TaskExit */

                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskDelay
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskDelay(uint32 millisecond)
{
   /* just call the implementation */
   return OS_TaskDelay_Impl(millisecond);
} /* end OS_TaskDelay */

                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskSetPriority
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskSetPriority (uint32 task_id, uint32 new_priority)
{
   OS_common_record_t *record;
   int32             return_code;
   uint32            local_id;
   
   if (new_priority > OS_MAX_TASK_PRIORITY)
   {
      return_code = OS_ERR_INVALID_PRIORITY;
   }
   else
   {
      return_code = OS_ObjectIdGetById(OS_LOCK_MODE_GLOBAL,LOCAL_OBJID_TYPE, task_id, &local_id, &record);
      if (return_code == OS_SUCCESS)
      {
         return_code = OS_TaskSetPriority_Impl(local_id, new_priority);
         OS_printf("Test >> local_id = %d\n");
         if (return_code == OS_SUCCESS)
         {
            /* Use the abstracted priority, not the OS one */
            /* Change the priority in the table as well */
            OS_task_table[local_id].priority = new_priority;
         }

         /* Unlock the global from OS_ObjectIdGetAndLock() */
         OS_Unlock_Global_Impl(LOCAL_OBJID_TYPE);
      }
   }
   
   return return_code;
} /* end OS_TaskSetPriority */


                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskRegister
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskRegister (void)
{
    OS_common_record_t *record;
    uint32 local_id;

    /*
     * Just to retain compatibility (really, only the unit test cares)
     * this will return NON success when called from a non-task context
     */
    return OS_ObjectIdGetById(OS_LOCK_MODE_NONE, LOCAL_OBJID_TYPE, OS_TaskGetId_Impl(), &local_id, &record);
} /* end OS_TaskRegister */

                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskGetId
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
uint32 OS_TaskGetId (void)
{
   OS_common_record_t *record;
   uint32 local_id;
   uint32 task_id;

   task_id = OS_TaskGetId_Impl();

   /* Confirm the task master table entry matches the expected.
    * If not it means we have some stale/leftover value */
   if (OS_ObjectIdGetById(OS_LOCK_MODE_NONE, LOCAL_OBJID_TYPE, task_id, &local_id, &record) != OS_SUCCESS)
   {
      task_id = 0;
   }

   return(task_id);
} /* end OS_TaskGetId */

                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskGetIdByName
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskGetIdByName (uint32 *task_id, const char *task_name)
{
   int32 return_code;

   if (task_id == NULL || task_name == NULL)
   {
       return OS_INVALID_POINTER;
   }

   return_code = OS_ObjectIdFindByName(LOCAL_OBJID_TYPE, task_name, task_id);

   return return_code;

} /* end OS_TaskGetIdByName */

                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskGetInfo
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskGetInfo (uint32 task_id, OS_task_prop_t *task_prop)
{
   OS_common_record_t *record;
   int32             return_code;
   uint32            local_id;

   /* Check parameters */
   if (task_prop == NULL)
   {
      return OS_INVALID_POINTER;
   }

   memset(task_prop,0,sizeof(OS_task_prop_t));

   return_code = OS_ObjectIdGetById(OS_LOCK_MODE_GLOBAL,LOCAL_OBJID_TYPE, task_id, &local_id, &record);
   if (return_code == OS_SUCCESS)
   {
      if (record->name_entry != NULL)
      {
          strncpy(task_prop->name, record->name_entry, sizeof(task_prop->name)-1);
          task_prop->name[sizeof(task_prop->name)-1] = 0;
      }
      task_prop->creator =    record->creator;
      task_prop->stack_size = OS_task_table[local_id].stack_size;
      task_prop->priority =   OS_task_table[local_id].priority;

      return_code = OS_TaskGetInfo_Impl(local_id, task_prop);

      OS_Unlock_Global_Impl(LOCAL_OBJID_TYPE);
   }

   return return_code;

} /* end OS_TaskGetInfo */

                        
/*----------------------------------------------------------------
 *
 * Function: OS_TaskInstallDeleteHandler
 *
 *  Purpose: Implemented per public OSAL API
 *           See description in API and header file for detail
 *
 *-----------------------------------------------------------------*/
int32 OS_TaskInstallDeleteHandler(osal_task_entry function_pointer)
{
   OS_common_record_t *record;
   int32 return_code;
   uint32 local_id;
   uint32 task_id;

   task_id = OS_TaskGetId_Impl();
   return_code = OS_ObjectIdGetById(OS_LOCK_MODE_GLOBAL, LOCAL_OBJID_TYPE, task_id, &local_id, &record);
   if (return_code == OS_SUCCESS)
   {
      /*
      ** Install the pointer
      */
      OS_task_table[local_id].delete_hook_pointer = function_pointer;

      OS_Unlock_Global_Impl(LOCAL_OBJID_TYPE);
   }

   return return_code;
} /* end OS_TaskInstallDeleteHandler */
