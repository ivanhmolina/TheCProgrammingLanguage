#ifndef _P_TYPES_
#define _P_TYPES_

typedef enum TYPES_E {UNIT8, UINT16, UINT32, UINT64, INT8, INT16, INT32, INT64, BOOL, STRING, FLOAT, DOUBLE} TYPES_T;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t; 
typedef unsigned long long int uint64_t;

typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;
typedef signed long long int int64_t;

typedef enum bool_e{FALSE, TRUE} bool_t;

#endif