//
//  QuickSort.h
//  retete_problema_partial2
//
//  Created by Raul Constantin on 15.11.2024.
//

#ifndef QuickSort_h
#define QuickSort_h

#include <vector>
struct Ingredient{
    unsigned ID, calorii;
    std::string nume;
};

struct Reteta{
    std::vector<Ingredient> ingr;
    unsigned ID_reteta, calorii = 0, pret, nrIngr;
};
// Function to perform QuickSort on a vector
void quickSort(std::vector<Reteta>& arr, int low, int high, bool verificator);

#endif /* QuickSort_h */
