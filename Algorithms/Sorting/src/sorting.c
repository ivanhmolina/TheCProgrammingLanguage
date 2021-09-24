#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

static void swapInteger(int32_t *a, int32_t *b);

static void swapInteger(int32_t *a, int32_t *b)
{
    int32_t t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int32_t array[], uint16_t length)
{
    bool_t swapped = FALSE;
    for (uint16_t i = 0; i < length; i++)
    {
        for (uint16_t j = 0; j < length-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swapInteger(array+j, array+j+1);
                swapped = TRUE;
            }
        }
        if(swapped = FALSE)
            break;
    }
}

#ifdef DEBUG_SORT
int main(int argc, char const *argv[])
{
    int32_t array[5] = {1, 2, 3, 3, 2};
    bubbleSort(array, 5);
    printf("array = ");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    
    return 0;
}
#endif
