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

#include <overrides/time.h>

/* JPHFIX: FIXME: This should be in a header somehow, not here */
extern int32 OS_GetLocalTime_Impl(OS_time_t *time_struct);
extern int32 OS_SetLocalTime_Impl(const OS_time_t *time_struct);

#define OSAPI_TEST_FUNCTION_RC(func,exp)   \
{                                               \
    int32 rcexp = exp;                          \
    int32 rcact = func;                    \
    UtAssert_True(rcact == rcexp, "%s (%ld) == %s (%ld)", \
        #func, (long)rcact, #exp, (long)rcexp);      \
}


void Test_OS_GetLocalTime_Impl(void)
{
    /*
     * Test Case For:
     * int32 OS_GetLocalTime_Impl(OS_time_t *time_struct)
     */
    OS_time_t timeval;
    timeval.seconds = 1;
    timeval.microsecs = 1;
    OSAPI_TEST_FUNCTION_RC(OS_GetLocalTime_Impl(&timeval), OS_SUCCESS);

    UT_SetForceFail(UT_KEY(OCS_clock_gettime), -1);
    OSAPI_TEST_FUNCTION_RC(OS_GetLocalTime_Impl(&timeval), OS_ERROR);
}

void Test_OS_SetLocalTime_Impl(void)
{
    /*
     * Test Case For:
     * int32 OS_SetLocalTime_Impl(const OS_time_t *time_struct)
     */
    OS_time_t timeval;
    timeval.seconds = 1;
    timeval.microsecs = 1;
    OSAPI_TEST_FUNCTION_RC(OS_SetLocalTime_Impl(&timeval), OS_SUCCESS);

    UT_SetForceFail(UT_KEY(OCS_clock_settime), -1);
    OSAPI_TEST_FUNCTION_RC(OS_SetLocalTime_Impl(&timeval), OS_ERROR);
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


#define ADD_TEST(test) UtTest_Add((Test_ ## test), Osapi_Task_Setup, Osapi_TearDown, #test)

/* Osapi_AddTestCase_Tasks
 *
 * Purpose:
 *   Registers the test cases to execute with the unit test tool
 */
void OS_Application_Startup(void)
{
    ADD_TEST(OS_GetLocalTime_Impl);
    ADD_TEST(OS_SetLocalTime_Impl);
}


