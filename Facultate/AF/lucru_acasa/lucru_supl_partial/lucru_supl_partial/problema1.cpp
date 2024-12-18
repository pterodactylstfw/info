#include <iostream>
#include <vector>

std::vector<int> citire() {
    int dim;
    std::cin >> dim;
    std::vector<int> v(dim);
    for (int i = 0; i < dim; i++) {
        std::cin >> v[i];
    }
    return v;
}

void afisare(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}

bool comparatorCrescator(int x, int y) {
    return x < y;
}

bool comparatorDescrescator(int x, int y) {
    return x > y;
}

void quicksort(std::vector<int>& v, int st, int dr, bool comparator(int, int)) {
    if (st < dr) {
        int piv = v[(st + dr) / 2];
        int i = st, j = dr;
        while (i <= j) {
            while (comparator(v[i], piv))i++;
            while (comparator(piv, v[j]))j--;
            if (i <= j) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
            }
        }
        quicksort(v, st, j, comparator);
        quicksort(v, i, dr, comparator);
    }
}

int main() {
    std::vector<int> v = citire();
    quicksort(v, 0, v.size() - 1, comparatorCrescator);
    afisare(v);
}
