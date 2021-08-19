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

/*
 * Now include all extra logic required to stub-out subsequent calls to
 * library functions and replace with our own
 */
#include "osapi.c"

/* Stub objects to satisfy linking requirements -
 */
OS_common_record_t OS_stub_task_table[OS_MAX_TASKS];
OS_common_record_t * const OS_global_task_table   = OS_stub_task_table;
OS_common_record_t OS_stub_queue_table[OS_MAX_QUEUES];
OS_common_record_t * const OS_global_queue_table   = OS_stub_queue_table;

OS_queue_internal_record_t OS_queue_table[OS_MAX_QUEUES];
OS_task_internal_record_t OS_task_table[OS_MAX_TASKS];

OS_SharedGlobalVars_t OS_SharedGlobalVars =
      {
            .Initialized = false
      };

