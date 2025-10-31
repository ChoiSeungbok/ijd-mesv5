/*******************************************************************************

    System      : MESplus
    Module      : COMCore
    File Name   : COMCore_memory.h
    Description : Common Macro definition of COMCore Library

    MES Version : 5.1.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2010/11/1   SK Jin         Create

    Copyright(C) 1998-2010 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _COMCORE_MEMORY_H
#define _COMCORE_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mem_alloc_link
{
    void                    *p_mem;
    char                    *s_func_name;
    char                    *s_key_name;
    char                    c_type;
    char                    c_new;
    struct mem_alloc_link   *p_next_node;
} MEM_ALLOC_LINK;

extern void COM_init_memory_check();
extern void *COM_malloc(size_t size, const char *s_func_name, const char *s_key_name);
extern void *COM_calloc(size_t count, size_t size, const char *s_func_name, const char *s_key_name);
extern void *COM_realloc(void *p_src, size_t size, const char *s_func_name, const char *s_key_name);
extern void COM_free(void *p);
extern MEM_ALLOC_LINK  *COM_get_mem_alloc_head();
extern int COM_get_mem_alloc_count();
extern void COM_set_mem_check_flag(char c_flag);
extern char COM_get_mem_check_flag();
extern void COM_free_mem_alloc_link();

#endif  /* _COMCORE_MEMORY_H */
