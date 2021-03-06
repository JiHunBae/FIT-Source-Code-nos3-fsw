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
 * Filename: os-shared-coveragetest.h
 *
 * Purpose: Common header file for all "shared" layer coverage test modules
 */

#ifndef _OS_SHARED_COVERAGETEST_H_
#define _OS_SHARED_COVERAGETEST_H_

/*
 * Includes
 */

#include <utassert.h>
#include <uttest.h>
#include <utstubs.h>
#include <osapi.h>
#include <os-impl.h>

/*
 * Macro to call a function and check its int32 return code
 */
#define OSAPI_TEST_FUNCTION_RC(func,exp)        \
{                                               \
    int32 rcexp = exp;                          \
    int32 rcact = func;                         \
    UtAssert_True(rcact == rcexp, "%s (%ld) == %s (%ld)",   \
        #func, (long)rcact, #exp, (long)rcexp);             \
}

/*
 * Macro to add a test case to the list of tests to execute
 */
#define ADD_TEST(test) UtTest_Add((Test_ ## test),Osapi_Task_Setup,Osapi_TearDown, #test)

/*
 * Setup function prior to every test
 */
void Osapi_Task_Setup(void);

/*
 * Teardown function after every test
 */
void Osapi_TearDown(void);

#endif

