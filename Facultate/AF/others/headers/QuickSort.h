//
//  QuickSort.h
//  partial1_2024
//
//  Created by Raul Constantin on 29.11.2024.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <iostream>

bool comparatorCrescator(int x, int y);

bool comparatorDescrescator(int x, int y);

int partitionare(std::vector<int>& v, int st, int dr, bool Comparator(int, int));

void quicksort(std::vector<int>& v, int st, int dr);



#endif /* QuickSort_h */
