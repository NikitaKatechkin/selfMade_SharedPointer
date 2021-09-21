#include "ServiceTools.h"

void ServiceTools::RandNumArrayFill(int *arr, int arr_size)
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = std::rand();
    }
}

void ServiceTools::PrintArray(int *arr, int arr_size)
{
    std::cout << "Array contains following elements: ";
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << arr[i] << ";";
    }
    std::cout << std::endl;
}

void ServiceTools::SwapPair(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
