#ifndef _SORTING_
#define _SORTING_
#include "ptypes.h"

/** 
 * \brief BUBBLE SORT O(n^2) 
 *        Optimized version of bubble sort 
 * \param[in] array
 * \param[in] length
 * \return A sorted array
 * */
void bubbleSort(int32_t array[], uint16_t length);

/** 
 * \brief MERGE SORT O(nlog(n))
 *        Merge algorithm that uses divide and conquer
 * \pre
 * \post
 * \param[in] array
 * \param[in] length
 * \retval A sorted array
 * */
void mergeSort(int32_t array[], uint16_t length);

#endif