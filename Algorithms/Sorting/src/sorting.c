#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

#define DEBUG_SORT

static void swapInteger(int32_t *a, int32_t *b);
static void printArray(int32_t array[], uint16_t length);

void bubbleSort(int32_t array[], uint16_t length)
{
    bool_t swapped;
    do
    {
        swapped = FALSE;
        for (uint16_t i = 1; i < length; i++)
        {
            if(array[i-1] > array[i])
            {
                swapInteger(array+i-1, array+i);
                swapped = TRUE;
            }
        }
        length--;
    }
    while (swapped);
}

#ifdef DEBUG_SORT
int main(int argc, char const *argv[])
{
    const uint8_t length = 5;
    int32_t array[5] = {1, 2, 3, 3, 2};
    bubbleSort(array, length);
    printArray(array, length);
    
    return 0;
}
#endif

static void swapInteger(int32_t *a, int32_t *b)
{
    int32_t t = *a;
    *a = *b;
    *b = t;
}

static void printArray(int32_t array[], uint16_t length)
{
    uint8_t i;
    printf("[");
    for (i = 0; i < length - 1u; i++)
        printf("%d, ", array[i]);
    printf("%d]\n", array[i]);
}