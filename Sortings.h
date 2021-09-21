#ifndef SORTINGS_H_INCLUDED
#define SORTINGS_H_INCLUDED

#include "ServiceTools.h"

namespace Sortings
{
    void BubbleSort(int *arr, int arr_size);
    void InsertionSort(int *arr, int arr_size);

    void MergeArrayParts(int *arr, int left, int mid, int right);
    void MergeSort(int *arr, int start_index, int end_index);

    int PartArray(int *arr, int start_index, int end_index);
    void QuickSort(int *arr, int start_index, int end_index);
}

#endif // SORTINGS_H_INCLUDED
