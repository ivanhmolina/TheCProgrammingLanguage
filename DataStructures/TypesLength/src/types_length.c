#include <stdio.h>
#include "ptypes.h"

#ifdef BITS
#define LENGTH_TYPE 8L
#else
#define LENGTH_TYPE 1L
#endif

int main()
{
#ifdef BITS
    unsigned char *ltype = "bits";
#else
    unsigned char *ltype = "bytes";
#endif
    printf("This is a uint8_t  : %2u %s\n", sizeof(uint8_t) * LENGTH_TYPE, ltype);
    printf("This is a uint16_t : %2u %s\n", sizeof(uint16_t) * LENGTH_TYPE, ltype);
    printf("This is a uint32_t : %2u %s\n", sizeof(uint32_t) * LENGTH_TYPE, ltype);
    printf("This is a uint64_t : %2u %s\n", sizeof(uint64_t) * LENGTH_TYPE, ltype);
    printf("This is a int8_t   : %2u %s\n", sizeof(int8_t) * LENGTH_TYPE, ltype);
    printf("This is a int_16t  : %2u %s\n", sizeof(int_16t) * LENGTH_TYPE, ltype);
    printf("This is a int32_t  : %2u %s\n", sizeof(int32_t) * LENGTH_TYPE, ltype);
    printf("This is a int64_t  : %2u %s\n", sizeof(int64_t) * LENGTH_TYPE, ltype);
    printf("This is a bool_t   : %2u %s\n", sizeof(bool_t) * LENGTH_TYPE, ltype);
}