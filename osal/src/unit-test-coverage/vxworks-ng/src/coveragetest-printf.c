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

/*
 * Filename: osapi_testcase_common.c
 *
 * Purpose: This file contains unit test cases for items in the "osfileapi-common" file
 *
 * Notes:
 *
 */


/*
 * Includes
 */

#include <utassert.h>
#include <uttest.h>
#include <utstubs.h>

#include <osapi.h>
#include <os-impl.h>

#include <overrides/unistd.h>
#include <overrides/semLib.h>
#include <overrides/taskLib.h>
#include <overrides/stdio.h>

char TestConsoleBuffer[256];

void Test_OS_ConsoleWakeup_Impl(void)
{
    /*
     * Test Case For:
     * void OS_ConsoleWakeup_Impl(const char *string)
     */

    /* no return code - check for coverage */
    OS_ConsoleWakeup_Impl(0);
    UtAssert_True(UT_GetStubCount(UT_KEY(OCS_semGive)) == 1, "semGive() called");
}

void Test_OS_ConsoleCreate_Impl(void)
{
    OS_ConsoleCreate_Impl(0);
    UtAssert_True(UT_GetStubCount(UT_KEY(OCS_taskSpawn)) == 1, "taskSpawn() called");
}

void Test_OS_ConsoleOutput_Impl(void)
{
    strcpy(TestConsoleBuffer, "ABCD");
    OS_console_table[0].WritePos = 4;

    OS_ConsoleOutput_Impl(0);
    UtAssert_True(UT_GetStubCount(UT_KEY(OCS_putchar)) == 4, "putchar() called");
}


/* ------------------- End of test cases --------------------------------------*/

/* Osapi_Task_Setup
 *
 * Purpose:
 *   Called by the unit test tool to set up the app prior to each test
 */
void Osapi_Task_Setup(void)
{
    UT_ResetState(0);
    OS_console_table[0].BufBase = TestConsoleBuffer;
    OS_console_table[0].BufSize = sizeof(TestConsoleBuffer);
    OS_console_table[0].ReadPos = 0;
    OS_console_table[0].WritePos = 0;
}

/*
 * Osapi_TearDown
 *
 * Purpose:
 *   Called by the unit test tool to tear down the app after each test
 */
void Osapi_TearDown(void)
{

}


#define ADD_TEST(test) UtTest_Add((Test_ ## test), Osapi_Task_Setup, Osapi_TearDown, #test)

/* Osapi_AddTestCase_Tasks
 *
 * Purpose:
 *   Registers the test cases to execute with the unit test tool
 */
void OS_Application_Startup(void)
{
    ADD_TEST(OS_ConsoleCreate_Impl);
    ADD_TEST(OS_ConsoleOutput_Impl);
    ADD_TEST(OS_ConsoleWakeup_Impl);
}


