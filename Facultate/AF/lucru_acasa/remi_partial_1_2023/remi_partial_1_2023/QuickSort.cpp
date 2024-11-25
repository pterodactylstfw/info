#include "QuickSort.h"
#include <iostream>
// Helper function to partition the array
int partition(std::vector<Piesa>& arr, int low, int high, int &ct) {
    int pivot = arr[high].numar; // Pivot element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j].numar <= pivot) {
            ++i;
            ct++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(std::vector<Piesa>& arr, int low, int high, bool verificator, int &ct) {
    if(verificator == true) {
        std::cout<<"Vectorul este acum ordonat corespunzator";
        return;
    }
    else
    if (low < high) {
        int pi = partition(arr, low, high,ct); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1,verificator,ct);
        quickSort(arr, pi + 1, high,verificator,ct);
    }
}
