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

/* OSAL coverage stub replacement for symLib.h */
#ifndef _OSAL_STUB_SYMLIB_H_
#define _OSAL_STUB_SYMLIB_H_

/* ----------------------------------------- */
/* constants normally defined in symLib.h */
/* ----------------------------------------- */
#define OCS_LOAD_ALL_SYMBOLS        0x1A00

/* ----------------------------------------- */
/* types normally defined in symLib.h */
/* ----------------------------------------- */
typedef int OCS_STATUS;
typedef int OCS_SYM_TYPE;
typedef int (*OCS_FUNCPTR)();


#ifdef jphfix // determine if these are needed
typedef struct OCS_symbol           /* SYMBOL - entry in symbol table */
{
    int     nameHNode;      /* hash node (must come first) */
    char        *name;          /* pointer to symbol name */
    void        *value;         /* symbol value */
    int      symRef;         /* moduleId of module, or predefined SYMREF. */
    int      group;          /* symbol group */
    int    type;           /* symbol type */
} OCS_SYMBOL;

typedef struct OCS_symtab /* SYMTAB - symbol table */
{
    int handle; /* object maintanance */
    int nameHashId; /* hash table for names */
    int symMutex; /* symbol table mutual exclusion sem */
    int symPartId; /* memory partition id for symbols */
    unsigned char sameNameOk; /* symbol table name clash policy */
    int nsymbols; /* current number of symbols in table */
} OCS_SYMTAB;

#else
typedef void OCS_SYMTAB;
typedef void OCS_SYMBOL;
#endif


typedef OCS_SYMTAB * OCS_SYMTAB_ID;
typedef OCS_SYMBOL * OCS_SYMBOL_ID;

/*
 * The "BOOL" and "UINT16" types are indirectly part of the symEach() API
 */
typedef int OCS_BOOL;
typedef unsigned short OCS_UINT16;


/* ----------------------------------------- */
/* prototypes normally declared in symLib.h */
/* ----------------------------------------- */

extern OCS_SYMTAB_ID OCS_sysSymTbl;


extern OCS_STATUS OCS_symFindByName(OCS_SYMTAB_ID symTblId, char * name, char ** pValue, OCS_SYM_TYPE * pType);
extern OCS_SYMBOL * OCS_symEach(OCS_SYMTAB_ID symTblId, OCS_FUNCPTR routine, int routineArg);


#endif /* _OSAL_STUB_SYMLIB_H_ */

