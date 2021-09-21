#include "Searchings.h"

int main()
{
    const int ARRAY_SIZE = 26;
    int test_array[ARRAY_SIZE];

    ServiceTools::RandNumArrayFill(test_array, ARRAY_SIZE);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    Sortings::BubbleSort(test_array, ARRAY_SIZE);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    ServiceTools::RandNumArrayFill(test_array, ARRAY_SIZE);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    Sortings::InsertionSort(test_array, ARRAY_SIZE);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    ServiceTools::RandNumArrayFill(test_array, ARRAY_SIZE);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    Sortings::MergeSort(test_array, 0, ARRAY_SIZE - 1);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    ServiceTools::RandNumArrayFill(test_array, ARRAY_SIZE);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    Sortings::QuickSort(test_array, 0, ARRAY_SIZE - 1);
    ServiceTools::PrintArray(test_array, ARRAY_SIZE);

    std:: cout << Searchings::JumpSearch(test_array, ARRAY_SIZE, 4, test_array[25]) << std::endl;
    //ServiceTools::PrintArray(Searchings::getLast3FibonacciNums(25), 3);
    //Sortings::MergeArrayParts(test_array, 0, (ARRAY_SIZE - 1) / 2 + 0, ARRAY_SIZE - 1);
}
