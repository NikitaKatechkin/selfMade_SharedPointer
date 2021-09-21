#include "Searchings.h"

int Searchings::BinarySearch(int *arr, int start_index, int end_index, int search_value)
{
    if (end_index < 1)
        return -1;

    int mid = (end_index - start_index) / 2 + start_index;

    if (arr[mid] == search_value)
        return mid;

    if (search_value < arr[mid])
        return BinarySearch(arr, start_index, (mid - 1), search_value);

    return BinarySearch(arr, mid + 1, end_index, search_value);
}

int* Searchings::getLast3FibonacciNums(int num)
{
    int *last3Nums = new int[3];
    last3Nums[0] = 1;
    last3Nums[1] = 1;
    last3Nums[2] = 2;

    while (last3Nums[2] < num)
    {
        for (int i = 0; i < 2; i++)
        {
            last3Nums[i] = last3Nums[i + 1];
        }
        last3Nums[2] = last3Nums[0] + last3Nums[1];
    }

    return last3Nums;
}

int Searchings::getFibonacciOffset(int num)
{
    return getLast3FibonacciNums(num)[0];
}

int Searchings::FibonacciSearch(int *arr, int start_index, int end_index, int search_value)
{
    if (end_index - start_index < 1)
        return arr[start_index] == search_value ? start_index: -1;

    int mid = getFibonacciOffset(end_index - start_index + 1);

    if (arr[start_index + mid] == search_value)
        return (start_index + mid);

    if (search_value < arr[start_index + mid])
        return FibonacciSearch(arr, start_index, (start_index + mid - 1), search_value);

    return FibonacciSearch(arr, start_index + mid + 1, end_index, search_value);
}

int Searchings::InterpolationSearch(int *arr, int start_index, int end_index, int search_value)
{
    if (end_index - start_index < 1)
        return arr[start_index] == search_value ? start_index: -1;

    int mid = start_index + (search_value - arr[start_index]) * (double)((start_index - end_index) / (arr[end_index] - arr[start_index]));

    if (arr[mid] == search_value)
        return (mid);

    if (search_value < arr[mid])
        return InterpolationSearch(arr, start_index, mid - 1, search_value);

    return InterpolationSearch(arr, mid + 1, end_index, search_value);
}

int Searchings::JumpSearch(int *arr, int arr_size, int step, int search_value)
{
    int i;
    for(i = 0; i < arr_size; i+=step)
    {
        if (arr[i] > search_value) { break; }
        if (arr[i] == search_value) { return i; }
    }
    for (i = i; i > i - step; i--)
    {
        if (arr[i] == search_value) { return i; }
    }

    return -1;
}
