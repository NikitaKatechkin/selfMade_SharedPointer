#include "Sortings.h"

void Sortings::BubbleSort(int *arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        for(int j = 0; j < (arr_size - 1 - i); j++)
        {
            if (arr[j] > arr[j+1])
            {
                ServiceTools::SwapPair(&arr[j], &arr[j+1]);
            }
        }
    }
}

void Sortings::InsertionSort(int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = i + 1; j < arr_size; j++)
        {
            if (arr[i] > arr[j])
            {
                ServiceTools::SwapPair(&arr[i], &arr[j]);
            }
        }
    }
}

void Sortings::MergeArrayParts(int *arr, int left, int mid, int right)
{
    const int leftSubArraySize = mid - left + 1;
    const int rightSubArraySize = right - mid;

    int leftSubArray[leftSubArraySize];
    int rightSubArray[rightSubArraySize];

    for (int i = 0; i < leftSubArraySize; i++)
        leftSubArray[i] = arr[i + left];
    //ServiceTools::PrintArray(leftSubArray, leftSubArraySize);

    for (int i = 0; i < rightSubArraySize; i++)
        rightSubArray[i] = arr[mid + i + 1];
    //ServiceTools::PrintArray(rightSubArray, rightSubArraySize);

    int mergeElementIndexLeftSubArray = 0;
    int mergeElementIndexRightSubArray = 0;

    int insertElementArrCounter = left;

    while ((mergeElementIndexLeftSubArray < leftSubArraySize) &&
           (mergeElementIndexRightSubArray < rightSubArraySize))
    {
        if (leftSubArray[mergeElementIndexLeftSubArray] <= rightSubArray[mergeElementIndexRightSubArray])
        {
            arr[insertElementArrCounter] = leftSubArray[mergeElementIndexLeftSubArray];
            mergeElementIndexLeftSubArray++;
        }
        else
        {
            arr[insertElementArrCounter] = rightSubArray[mergeElementIndexRightSubArray];
            mergeElementIndexRightSubArray++;
        }
        insertElementArrCounter++;
    }

    while (mergeElementIndexLeftSubArray < leftSubArraySize)
    {
        arr[insertElementArrCounter] = leftSubArray[mergeElementIndexLeftSubArray];
        mergeElementIndexLeftSubArray++;
        insertElementArrCounter++;
    }

    while (mergeElementIndexRightSubArray < rightSubArraySize)
    {
        arr[insertElementArrCounter] = rightSubArray[mergeElementIndexRightSubArray];
        mergeElementIndexRightSubArray++;
        insertElementArrCounter++;
    }
}

void Sortings::MergeSort(int *arr, int start_index, int end_index)
{
    if (start_index >= end_index)
        return;

    int mid = (end_index - start_index) / 2 + start_index;
    MergeSort(arr, start_index, mid);
    MergeSort(arr, mid + 1, end_index);
    MergeArrayParts(arr, start_index, mid, end_index);
}

int Sortings::PartArray(int *arr, int start_index, int end_index)
{
    int pivot = arr[end_index];

    int switchIndex = start_index - 1;
    for (int i = start_index; i < end_index; i++)
    {
        if (pivot > arr[i])
        {
            switchIndex++;
            ServiceTools::SwapPair(&arr[switchIndex], &arr[i]);
        }
    }
    ServiceTools::SwapPair(&arr[end_index], &arr[switchIndex + 1]);
    return (switchIndex + 1);
}

void Sortings::QuickSort(int *arr, int start_index, int end_index)
{
    if (start_index >= end_index)
        return;

    int mid = PartArray(arr, start_index, end_index);
    QuickSort(arr, start_index, mid - 1);
    QuickSort(arr, mid + 1, end_index);
}


