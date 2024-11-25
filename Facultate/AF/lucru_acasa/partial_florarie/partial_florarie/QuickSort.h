//
//  QuickSort.h
//  partial_florarie
//
//  Created by Raul Constantin on 25.11.2024.
//
#ifndef QuickSort_h
#define QuickSort_h

#include <vector>

using namespace std;

struct Floare{
    std::string nume, culoare;
    float pret;
};

float partition(std::vector<Floare>& arr, int stanga, int dreapta);

// Funcția quicksort
void quickSort(std::vector<Floare> &arr, int stanga, int dreapta);

#endif
