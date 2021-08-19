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

/* pull in the OSAL configuration */
#include "stub-map-to-real.h"
#include "osconfig.h"
#include "ut-osapi-filesys.h"

/*
 * Now include all extra logic required to stub-out subsequent calls to
 * library functions and replace with our own
 */
#include "osapi-filesys.c"

/*
 * Stub objects to satisfy linking requirements -
 */
OS_common_record_t OS_stub_filesys_table[OS_MAX_FILE_SYSTEMS];
OS_common_record_t OS_stub_stream_table[OS_MAX_NUM_OPEN_FILES];
OS_common_record_t * const OS_global_filesys_table  = OS_stub_filesys_table;
OS_common_record_t * const OS_global_stream_table   = OS_stub_stream_table;

OS_SharedGlobalVars_t OS_SharedGlobalVars =
      {
            .Initialized = false
      };

/*
 * Provide a wrapper so the UT can invoke OS_FileSys_FindVirtMountPoint()
 */
bool Osapi_Internal_FileSys_FindVirtMountPoint(void *ref, uint32 local_id, const OS_common_record_t *obj)
{
    return OS_FileSys_FindVirtMountPoint(ref, local_id, obj);
}

/*
 * Provide a wrapper so the UT can invoke OS_FileSys_InitLocalFromVolTable()
 */
int32 Osapi_Internal_FileSys_InitLocalFromVolTable(OS_filesys_internal_record_t *local, const OS_VolumeInfo_t *Vol)
{
    return OS_FileSys_InitLocalFromVolTable(local, Vol);
}

