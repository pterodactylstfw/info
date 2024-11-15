//
//  cautari.h
//  Lab_7
//
//  Created by Raul Constantin on 06.11.2024.
//

#ifndef cautari_h
#define cautari_h

#include <vector>

/*
 comparator - metoda folosita pentru a compara 2 obiecte si de a returna:
            true, daca ele sunt in ord corecta
            false, altfel
 */

bool comparator_cresc(int a, int b);


bool comparator_descresc(int a, int b);

int partitionare(std::vector<int> &vect, int st, int dr, bool comparator(int, int));

void quicksort(std::vector<int> &vect, int st, int dr, bool comparator(int, int));

#endif /* cautari_h */
