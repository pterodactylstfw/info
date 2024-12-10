//
//  QuickSort.h
//  partial1_2024
//
//  Created by Raul Constantin on 29.11.2024.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <iostream>

struct Parcare
{
    int row, col;
    std::string stare;
};


bool comparatorCrescator(int x, int y);

bool comparatorDescrescator(int x, int y);

bool comparatorParcare(Parcare x, Parcare y);

int partitionare(std::vector<int>& v, int st, int dr, bool Comparator(std::string, std::string));

void quicksort(std::vector<int>& v, int st, int dr);



#endif /* QuickSort_h */
