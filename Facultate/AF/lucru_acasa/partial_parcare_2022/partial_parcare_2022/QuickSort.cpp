#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Structura Parcare
struct Parcare {
    int row, col;
    std::string stare; // Poate fi "ocupat" sau "liber"
};

// Comparator pentru string-uri (folosit pentru câmpul "stare")
bool comparatorString(const std::string& x, const std::string& y) {
    // "ocupat" vine înainte de "liber"
    return x < y; // Comparare lexicografică
}

// Funcția de partitionare pentru QuickSort
int partitionare(std::vector<Parcare>& v, int st, int dr, bool Comparator(const std::string&, const std::string&)) {
    int i = st - 1;
    std::string pivot = v[dr].stare; // Pivot pe baza câmpului "stare"
    for (int j = st; j < dr; j++) {
        if (Comparator(v[j].stare, pivot)) { // Compara string-urile folosind comparatorul
            i++;
            std::swap(v[i], v[j]);
        }
    }
    i++;
    std::swap(v[i], v[dr]);
    return i;
}

// QuickSort pentru vector de structuri Parcare
void quicksort(std::vector<Parcare>& v, int st, int dr, bool Comparator(const std::string&, const std::string&)) {
    if (st < dr) {
        int m = partitionare(v, st, dr, Comparator);
        quicksort(v, st, m - 1, Comparator);
        quicksort(v, m + 1, dr, Comparator);
    }
}

