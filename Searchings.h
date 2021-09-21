#ifndef SEARCHINGS_H_INCLUDED
#define SEARCHINGS_H_INCLUDED

#include "Sortings.h"

namespace Searchings
{
    int BinarySearch(int *arr, int start_index, int end_index, int search_value);

    int* getLast3FibonacciNums(int num);
    int getFibonacciOffset(int num);
    int FibonacciSearch(int *arr, int start_index, int end_index, int search_value);

    int InterpolationSearch(int *arr, int start_index, int end_index, int search_value);

    int JumpSearch(int *arr, int arr_size, int step, int search_value);
}

#endif // SEARCHINGS_H_INCLUDED
