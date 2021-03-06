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

/*================================================================================*
** File:  ut_osfile_test_platforms.h
** Owner: Tam Ngo
** Date:  September 2013
**================================================================================*/

#ifndef _UT_OSFILE_TEST_PLATFORMS_H_
#define _UT_OSFILE_TEST_PLATFORMS_H_

/*--------------------------------------------------------------------------------*
** Includes
**--------------------------------------------------------------------------------*/

#ifdef _LINUX_OS_
#endif  /* _LINUX_OS_ */

#ifdef OSP_ARINC653
#include "apex_api.h"
#endif  /* OSP_ARINC653 */

/*--------------------------------------------------------------------------------*
** Macros
**--------------------------------------------------------------------------------*/

/*--------------------------------------------*/
#ifdef _LINUX_OS_
/*--------------------------------------------*/

#define UT_OS_OUTPUT_TO_FILE_SUCCESS_COND_MACRO \
    strncmp(g_readBuff, "UT_os_outputtofile_test", 7) == 0

/*--------------------------------------------------------------------------------*/

#define UT_OS_COMPARE_COND_FOR_NOMINAL_GETFDINFO_MACRO              \
if ((OS_FDGetInfo(g_fDescs[0], &fdProps) != OS_FS_SUCCESS) ||       \
    (fdProps.IsValid != true) ||                                    \
    (strncmp(fdProps.Path, g_fNames[0], strlen(g_fNames[0])) != 0))

/*--------------------------------------------*/
#endif  /* _LINUX_OS_ */
/*--------------------------------------------*/

/*--------------------------------------------*/
#ifdef _VXWORKS_OS_
/*--------------------------------------------*/

#define UT_OS_OUTPUT_TO_FILE_SUCCESS_COND_MACRO \
    strncmp(&g_readBuff[1], cmd, strlen(cmd)) == 0

/*--------------------------------------------------------------------------------*/

#define UT_OS_COMPARE_COND_FOR_NOMINAL_GETFDINFO_MACRO              \
if ((OS_FDGetInfo(g_fDescs[0], &fdProps) != OS_FS_SUCCESS) ||       \
    (fdProps.IsValid != true) ||                                    \
    (strncmp(fdProps.Path, g_fNames[0], strlen(g_fNames[0])) != 0))

/*--------------------------------------------*/
#endif  /* _VXWORKS_OS_ */
/*--------------------------------------------*/

/*--------------------------------------------*/
#if defined(OSP_ARINC653) || defined(_RTEMS_OS_)
/*--------------------------------------------*/

#define UT_OS_OUTPUT_TO_FILE_SUCCESS_COND_MACRO  1

/*--------------------------------------------------------------------------------*/

#define UT_OS_COMPARE_COND_FOR_NOMINAL_GETFDINFO_MACRO         \
if ((OS_FDGetInfo(g_fDescs[0], &fdProps) != OS_FS_SUCCESS) ||  \
    (fdProps.IsValid != true) ||                               \
    (strncmp(fdProps.Path, fileName, strlen(fileName)) != 0))

/*--------------------------------------------*/
#endif  /* OSP_ARINC653 */
/*--------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Data types
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** External global variables
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Global variables
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Function prototypes
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/

#endif  /* _UT_OSFILE_TEST_PLATFORMS_H_ */

/*================================================================================*
** End of File: ut_osfile_test_platforms.h
**================================================================================*/
