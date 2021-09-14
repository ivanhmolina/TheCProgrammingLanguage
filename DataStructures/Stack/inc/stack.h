#ifndef _STACK_
#define _STACK_

#include "ptypes.h"

typedef union ELEMENT_u
{
    int64_t i64;
    int32_t i32;
    int16_t i16;
    int8_t  i8;
    void    *ptr;
} ELEMENT_t;

typedef struct STACK_NODE_s *STACK_PTR_t;

typedef struct STACK_NODE_s
{
    ELEMENT_t value;
    STACK_PTR_t next;
    TYPES_T utype;
} STACK_NODE_t;

void push(ELEMENT_t value, TYPES_T vtype);
ELEMENT_t pop();
ELEMENT_t peek();
bool_t isEmpty();

#endif