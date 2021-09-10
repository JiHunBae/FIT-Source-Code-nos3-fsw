/*
**  GSC-18128-1, "Core Flight Executive Version 6.7"
**
**  Copyright (c) 2006-2019 United States Government as represented by
**  the Administrator of the National Aeronautics and Space Administration.
**  All Rights Reserved.
**
**  Licensed under the Apache License, Version 2.0 (the "License");
**  you may not use this file except in compliance with the License.
**  You may obtain a copy of the License at
**
**    http://www.apache.org/licenses/LICENSE-2.0
**
**  Unless required by applicable law or agreed to in writing, software
**  distributed under the License is distributed on an "AS IS" BASIS,
**  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**  See the License for the specific language governing permissions and
**  limitations under the License.
*/

/************************************************************************************************
** File:  cfe_psp_watchdog.c
**
** Purpose:
**   This file contains glue routines between the cFE and the OS Board Support Package ( BSP ).
**   The functions here allow the cFE to interface functions that are board and OS specific
**   and usually dont fit well in the OS abstraction layer.
**
** History:
**   2009/07/20  A. Cudmore    | Initial version,
**
*************************************************************************************************/
// Watchdog implementation define
#define _GNU_SOURCE

/*
**  Include Files
*/


/*
** cFE includes
*/
#include "common_types.h"
#include "osapi.h"

/*
**  System Include Files
*/
#include <stdio.h>
#include <stdlib.h>

// Watchdog implementation include
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sched.h>
#include "../../../../cfe/fsw/cfe-core/src/inc/cfe_es.h"

/*
** Types and prototypes for this module
*/
#include "cfe_psp.h"
#include "cfe_psp_config.h"

/*
** Global data
*/

/*
** The watchdog time in milliseconds
*/
uint32 CFE_PSP_WatchdogValue = CFE_PSP_WATCHDOG_MAX;
uint32 CFE_PSP_WatchdogTimer;

pthread_t pthread;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
char WatchdogThreadName[20] = "Watchdog Timer";

void CFE_PSP_WatchdogExec(void);

/*  Function:  CFE_PSP_WatchdogInit()
**
**  Purpose:
**    To setup the timer resolution and/or other settings custom to this platform.
**
**  Arguments:
**
**  Return:
*/
void CFE_PSP_WatchdogInit(void)
{

   /*
   ** Just set it to a value right now
   ** The pc-linux desktop platform does not actually implement a watchdog
   ** timeout ( but could with a signal )
   */
   CFE_PSP_WatchdogValue = CFE_PSP_WATCHDOG_MAX;

}


/******************************************************************************
**  Function:  CFE_PSP_WatchdogEnable()
**
**  Purpose:
**    Enable the watchdog timer
**
**  Arguments:
**
**  Return:
*/
void CFE_PSP_WatchdogEnable(void)
{
   pthread_attr_t attr;
   struct sched_param param;
   cpu_set_t mask;

   pthread_attr_init(&attr);
   
   if(pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED) != 0) {
      CFE_ES_WriteToSysLog("pthread_attr_setintheritsched error in CFE_PSP_WatchdogEnable\n");
   }
   // Set priority
   pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
   param.sched_priority = 85; // higher than any cFS task
   pthread_attr_setschedparam(&attr, &param);
   
   // Set core affinity
   CPU_ZERO(&mask);
   CPU_SET(0, &mask);
   if(pthread_attr_setaffinity_np(&attr, sizeof(mask), &mask) != 0) {
      CFE_ES_WriteToSysLog("pthread_attr_setaffinity_np error in CFE_PSP_WatchdogEnable\n");
   }
   pthread_attr_getschedparam(&attr, &param);
   printf("Test >> Watchdog priority : %d\n", param.sched_priority);

   pthread_create(&pthread, &attr, CFE_PSP_WatchdogExec, NULL);
}


/******************************************************************************
**  Function:  CFE_PSP_WatchdogDisable()
**
**  Purpose:
**    Disable the watchdog timer
**
**  Arguments:
**
**  Return:
*/
void CFE_PSP_WatchdogDisable(void)
{
   pthread_cancel(pthread);
}

/******************************************************************************
**  Function:  CFE_PSP_WatchdogService()
**
**  Purpose:
**    Load the watchdog timer with a count that corresponds to the millisecond
**    time given in the parameter.
**
**  Arguments:
**    None.
**
**  Return:
**    None
**
**  Notes:
**
*/
void CFE_PSP_WatchdogService(void)
{
   pthread_mutex_lock(&mutex);
   CFE_PSP_WatchdogTimer = CFE_PSP_WatchdogValue / 1000; // 1 Timer -> 1 sec
   pthread_mutex_unlock(&mutex);

   return;
}

/******************************************************************************
**  Function:  CFE_PSP_WatchdogGet
**
**  Purpose:
**    Get the current watchdog value. 
**
**  Arguments:
**    none 
**
**  Return:
**    the current watchdog value 
**
**  Notes:
**
*/
uint32 CFE_PSP_WatchdogGet(void)
{
   // return(CFE_PSP_WatchdogValue);
   return CFE_PSP_WatchdogTimer;
}


/******************************************************************************
**  Function:  CFE_PSP_WatchdogSet
**
**  Purpose:
**    Get the current watchdog value. 
**
**  Arguments:
**    The new watchdog value 
**
**  Return:
**    nothing 
**
**  Notes:
**
*/
void CFE_PSP_WatchdogSet(uint32 WatchdogValue)
{
   CFE_PSP_WatchdogValue = WatchdogValue; // millisceonds

   return;
}

// Watchdog timer implementation (user implementation)
/******************************************************************************
**  Function:  CFE_PSP_WatchdogExec
**
**  Purpose:
**    Start Watchdog timer
**
**  Arguments:
**    none
**
**  Return:
**    nothing 
**
**  Notes:
**    If the 
*/
void CFE_PSP_WatchdogExec(void) {
   printf("[%s] Watchdog thread executed!\n", WatchdogThreadName);
   while(true) {
      if(CFE_PSP_WatchdogTimer == 0) {
         CFE_ES_WriteToSysLog("[Watchdog] Reset trying!");
         CFE_PSP_Restart(CFE_PSP_RST_TYPE_PROCESSOR);
         CFE_ES_WriteToSysLog("[Watchdog] Reset function executed!\n");
         sleep(300);
      }
      
      pthread_mutex_lock(&mutex);
      CFE_ES_WriteToSysLog("[Watchdog] Count down, Timer : %d -> %d\n",
                           CFE_PSP_WatchdogTimer, CFE_PSP_WatchdogTimer - 1);
      CFE_PSP_WatchdogTimer--;
      pthread_mutex_unlock(&mutex);
      sleep(1);
      
   } 
}