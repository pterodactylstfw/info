//
//  QuickSort.h
//  retete_problema_partial2
//
//  Created by Raul Constantin on 15.11.2024.
//

#ifndef QuickSort_h
#define QuickSort_h

#include <vector>
struct Piesa{
    std::string culoare;
    int numar;
};


// Function to perform QuickSort on a vector
void quickSort(std::vector<Piesa>& arr, int low, int high, bool verificator, int &ct);

#endif /* QuickSort_h */
