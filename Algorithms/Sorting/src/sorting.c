#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

#define DEBUG_SORT
/*#define DEBUG_MSORT*/

#ifdef DEBUG_SORT
static void printArray(int32_t array[], uint16_t length);
static void printArrayln(int32_t array[], uint16_t length);
#endif

static void swapInteger(int32_t *a, int32_t *b);
static void mergeArrays(int32_t arr1[], uint16_t len1, int32_t arr2[], uint16_t len2);

static void mergeArrays(int32_t arr1[], uint16_t len1, int32_t arr2[], uint16_t len2)
{
    uint16_t i = 0;
    uint16_t j = 0;
#ifdef DEBUG_MSORT
    printf("BOTTOM\n");
    printArray(arr1, len1);
    printf("   ");
    printArray(arr2, len2);
    printf("\n");
#endif
    while (i < len1 && j < len2)
    {
        if (arr1[i] <= arr2[j])
        {
            i++;
        }
        if (arr1[i] > arr2[j])
        {
            swapInteger(&arr1[i], &arr2[j]);
            j++;
        }
        if (i < len1 && j == len2)
        {
            i++;
        }
        if (j < len2 && i == len1)
        {
            j++;
        }
    }
#ifdef DEBUG_MSORT
    printf("MERGED\n");
    printArray(arr1, len1);
    printf(" + ");
    printArray(arr2, len2);
    printf("\n");
#endif
}

void mergeSort(int32_t array[], uint16_t length)
{
    uint16_t half_len = length / 2;
#ifdef DEBUG_MSORT
    printf("ENTERS\n");
    printArray(array, length);
#endif
    if(length > 2)
    {
        mergeSort(array, half_len);
        mergeSort(array + half_len, length - half_len);
    }
    mergeArrays(array, half_len, array + half_len, length - half_len);
}

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
    int32_t array1[5] = {3, 2, 1, 3, 2};
    int32_t array2[6] = {1, 2, 3, 3, 2, 1};
    int32_t array3[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    printf("bubbleSort:\n");
    printArrayln(array1, 5);
    bubbleSort(array1, 5);
    printArrayln(array1, 5);
    printf("mergeSort:\n");
    printArrayln(array2, 6);
    mergeSort(array2, 6);
    printArrayln(array2, 6);
    printf("mergeSort:\n");
    printArrayln(array2, 5);
    mergeSort(array2, 5);
    printArrayln(array2, 5);
    printf("mergeSort:\n");
    printArrayln(array3, 8);
    mergeSort(array3, 8);
    printArrayln(array3, 8);

    return 0;
}
#endif

static void swapInteger(int32_t *a, int32_t *b)
{
    int32_t t = *a;
    *a = *b;
    *b = t;
}

#ifdef DEBUG_SORT
static void printArray(int32_t array[], uint16_t length)
{
    uint8_t i;
    printf("[");
    if(length == 0 || array == NULL)
        printf("EMPTY]");
    else
    {
        for (i = 0; i < length - 1u; i++)
            printf("%d, ", array[i]);
        printf("%d]", array[i]);
    }
}

static void printArrayln(int32_t array[], uint16_t length)
{
    uint8_t i;
    printf("[");
    if (length == 0 || array == NULL)
        printf("EMPTY]\n");
    else
    {
        for (i = 0; i < length - 1u; i++)
            printf("%d, ", array[i]);
        printf("%d]\n", array[i]);
    }
}
#endif