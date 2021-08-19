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

/* OSAL coverage stub replacement for stdarg.h */
#ifndef _OSAL_STUB_STDARG_H_
#define _OSAL_STUB_STDARG_H_

/* ----------------------------------------- */
/* constants normally defined in stdarg.h */
/* ----------------------------------------- */

/* ----------------------------------------- */
/* types normally defined in stdarg.h */
/* ----------------------------------------- */

typedef void*         OCS_va_list;

/* ----------------------------------------- */
/* prototypes normally declared in stdarg.h */
/* ----------------------------------------- */

#define OCS_va_start(ap, last)  ap = &last
#define OCS_va_end(ap)



#endif /* _OSAL_STUB_STDARG_H_ */

