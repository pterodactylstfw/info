#include "QuickSort.h"
#include <iostream>
// Helper function to partition the array
int partition(std::vector<Reteta>& arr, int low, int high) {
    int pivot = arr[high].calorii; // Pivot element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j].calorii >= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(std::vector<Reteta>& arr, int low, int high, bool verificator) {
    if(verificator == true) {
        std::cout<<"Vectorul e ordonat descrescator";
        return;
    }
    else
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1,verificator);
        quickSort(arr, pi + 1, high,verificator);
    }
}
