#include <iostream>


bool comparatorCrescator(int x, int y) {
    return x < y;
}

bool comparatorDescrescator(int x, int y) {
    return x > y;
}

int partitionare(std::vector<int>& v, int st, int dr, bool Comparator(int, int)) {
    int i = st - 1, pivot = v[dr];
    for (int j = st; j < dr; j++) {
        if (Comparator(v[j], pivot)) { // aici folosim comparatorul daca este cazul
            i++;
            std::swap(v[i], v[j]);
        }
    }
    i++;
    std::swap(v[i], v[dr]);
    return i;
}

void quicksort(std::vector<int>& v, int st, int dr) {
    if (st < dr) {
        int m = partitionare(v, st, dr, comparatorCrescator);
        quicksort(v, st, m - 1);
        quicksort(v, m + 1, dr);
    }
}


