//
//  QuickSort.cpp
//  partial_florarie
//
//  Created by Raul Constantin on 25.11.2024.
//

#include <iostream>

#include "QuickSort.h"


float partition(vector<Floare> &vec, int st, int dr) {

    // Selecting last element as the pivot
    float pivot = vec[dr].pret;

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (st - 1);

    for (int j = st; j <= dr - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j].pret >= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[dr]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<Floare> &vec, int st, int dr) {

    // Base case: This part will be executed till the starting
    // index st is lesser than the ending index dr
    if (st < dr) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pvt = partition(vec, st, dr);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, st, pvt - 1);
        quickSort(vec, pvt + 1, dr);
    }
}
