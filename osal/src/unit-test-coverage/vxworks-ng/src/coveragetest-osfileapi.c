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

#include "os-vxworks-coveragetest.h"

#include <overrides/stdlib.h>
#include <overrides/taskLib.h>
#include <overrides/shellLib.h>

#include "ut-osfileapi.h"


void Test_OS_VxWorks_StreamAPI_Impl_Init(void)
{
    /*
     * Test Case For:
     * int32 OS_Works_StreamAPI_Impl_Init(void)
     */
    OSAPI_TEST_FUNCTION_RC(OS_VxWorks_StreamAPI_Impl_Init(), OS_SUCCESS);
}


void Test_OS_ShellOutputToFile_Impl(void)
{
    /*
     * Test Case For:
     * int32 OS_ShellOutputToFile_Impl(uint32 file_id, const char *Cmd)
     */
    int32 expected = OS_SUCCESS;
    int32 actual;

    /*
     * The ShellOutputToFile will loop until the
     * taskNameToId() function returns ERROR, so this
     * must be set to avoid getting into an endless loop.
     */
    UT_SetDeferredRetcode(UT_KEY(OCS_taskNameToId), 2, -1);

    actual = OS_ShellOutputToFile_Impl(0, "TestCmd");

    UtAssert_True(actual == expected, "OS_ShellOutputToFile_Impl() (%ld) == OS_SUCCESS", (long)actual);
    UtAssert_True(UT_GetStubCount(UT_KEY(OCS_shellGenericInit)) == 1, "shellGenericInit() called");
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

/* Osapi_AddTestCase_Tasks
 *
 * Purpose:
 *   Registers the test cases to execute with the unit test tool
 */
void OS_Application_Startup(void)
{
    ADD_TEST(OS_VxWorks_StreamAPI_Impl_Init);
    ADD_TEST(OS_ShellOutputToFile_Impl);
}



