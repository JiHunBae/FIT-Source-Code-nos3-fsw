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
#include "../../../../cfe/fsw/cfe-core/src/inc/cfe_es.h" // relative path

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

pthread_t p_thread;
pthread_mutex_t mutex;
char WatchdogThreadName[20] = "Watchdog Timer";

void CFE_PSP_WatchdogExec(char *);

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
   pthread_create(&p_thread, NULL, CFE_PSP_WatchdogExec, (char *)WatchdogThreadName);
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
   pthread_cancel(p_thread);
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
   CFE_ES_WriteToSysLog("[Watchdog] Timer reset!\n");
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
    CFE_PSP_WatchdogValue = WatchdogValue; // milliseconds

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
void CFE_PSP_WatchdogExec(char* ThreadName) {
   printf("[%s] Watchdog thread executed!\n", ThreadName);
   while(true) {
      if(CFE_PSP_WatchdogTimer == 0) {
         CFE_ES_WriteToSysLog("[Watchdog] Reset!");
         sleep(3);
         kill(getpid(), SIGHUP);
      }
      pthread_mutex_lock(&mutex);
      CFE_ES_WriteToSysLog("[Watchdog] Count down, Timer : %d -> %d\n",
                           CFE_PSP_WatchdogTimer, CFE_PSP_WatchdogTimer - 1);
      CFE_PSP_WatchdogTimer--;
      pthread_mutex_unlock(&mutex);
      sleep(1);
   }
}