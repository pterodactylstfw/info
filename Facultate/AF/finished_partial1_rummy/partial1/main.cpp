#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

ifstream fin("input.in");

struct piese {
    unsigned numar;
    string culoare;
};

// Function to validate the number
int validate_number(int x) {
    return x > 0 && x < 14; // Returns true if x is between 1 and 13
}

// Function to validate the color
int validate_color(string cul) {
    return (cul == "albastru" || cul == "negru" || cul == "galben" || cul == "verde") ? 1 : 0; // Returns true for valid colors
}

// Function to check if the input is valid
int valid(int x, string cul) {
    return validate_number(x) == 1 && validate_color(cul) == 1; // Both must be true
}

// Function to count occurrences of a piece in the vector
int countOccurrences(const vector<piese>& psJuc, const piese& tmp) {
    int count = 0;
    for (const auto& p : psJuc) {
        if (p.numar == tmp.numar && p.culoare == tmp.culoare) {
            count++;
        }
    }
    return count; // Returns the number of occurrences
}

// Function to read data from the input file
void read(vector<piese>& psJuc) {
    for (int i = 0; i < 14; i++) {
        piese tmp;
        fin >> tmp.numar >> tmp.culoare;
        
        // Check validity and occurrences
        while (valid(tmp.numar, tmp.culoare) == 0 || countOccurrences(psJuc, tmp) >= 2) {
            if (countOccurrences(psJuc, tmp) >= 2) {
                cout << "Datele cu ID " << i + 1 << " sunt invalide. Aceasta combinatie a fost introdusa de 2 ori. Reintroduceti date conforme: ";
            } else {
                cout << "Datele cu ID " << i + 1 << " sunt invalide. Reintroduceti date conforme: ";
            }
            cin >> tmp.numar >> tmp.culoare;
        }
        
        psJuc.push_back(tmp); // Add the valid object to the vector
    }
    cout << "Succes in citirea datelor!" << '\n';
}

// Function to find and display the longest formation
void findLongestFormation(const vector<piese>& psJuc, const piese& newPiece) {
    vector<piese> formation; // To hold the current formation

    // Check for formations based on number
    for (const auto& p : psJuc) {
        if (p.numar == newPiece.numar) {
            formation.push_back(p);
        }
    }
    formation.push_back(newPiece); // Add the new piece

    if (formation.size() >= 3) {
        cout << "Formație pe baza numarului (" << newPiece.numar << "): ";
        for (const auto& p : formation) {
            cout << p.numar << " " << p.culoare << " | ";
        }
        cout << endl;
    }

    // Clear formation for color check
    formation.clear();

    // Check for formations based on color
    for (const auto& p : psJuc) {
        if (p.culoare == newPiece.culoare) {
            formation.push_back(p);
        }
    }
    formation.push_back(newPiece); // Add the new piece

    if (formation.size() >= 3) {
        cout << "Formație pe baza culorii (" << newPiece.culoare << "): ";
        for (const auto& p : formation) {
            cout << p.numar << " " << p.culoare << " | ";
        }
        cout << endl;
    }
}

int isSorted(const vector<piese>& psJuc) {
    for (unsigned i = 0; i < psJuc.size() - 1; i++) {
        if (psJuc[i].numar > psJuc[i + 1].numar) return 0;
    }
    return 1;
}

int partition(vector<piese>& arr, int low, int high) {
    unsigned pivot = arr[high].numar; // Alege ultimul element ca pivot
    int i = (low - 1); // Index al celui mai mic element
    
    for (int j = low; j <= high - 1; j++) {
        // Dacă elementul curent este mai mic sau egal cu pivotul
        if (arr[j].numar <= pivot) {
            i++; // Incrementeaza indexul celui mai mic element
            if (i != j) { // Numara doar dacă există o schimbare efectivă
                swap(arr[i], arr[j]); // Schimba elementele
            }
        }
    }
    if (i + 1 != high) { // Numara schimbarea pivotului
        swap(arr[i + 1], arr[high]); // Pune pivotul la locul corect
    }
    return (i + 1); // Returneaza indexul pivotului
}

// Functia QuickSort
void quickSort(vector<piese>& arr, int low, int high) {
    if (low < high) {
        // Partitia si obtinerea indexului pivotului
        int pi = partition(arr, low, high);
        
        // Sortarea subvectorului stang si drept
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to count position changes
int countPositionChanges(const vector<piese>& psJuc, const vector<piese>& original) {
    int changes = 0;
    for (size_t i = 0; i < psJuc.size(); ++i) {
        if (psJuc[i].numar != original[i].numar || psJuc[i].culoare != original[i].culoare) {
            changes++;
        }
    }
    return changes; // Returns the number of position changes
}

void sorting(vector<piese>& psJuc, const vector<piese>& original) {
    if (isSorted(psJuc) == 0) {
        quickSort(psJuc, 0, psJuc.size() - 1);
        cout << "A fost modificata pozitia a " << countPositionChanges(psJuc, original) << " piese" << '\n';
    } else {
        cout << "Piesele erau sortate deja!" << '\n';
    }
}

void formatie(const vector<piese>& psJuc) {
    for (int i = 0; i < psJuc.size() - 2; i++)
        if (psJuc[i].numar == psJuc[i + 1].numar && psJuc[i].numar == psJuc[i + 2].numar)
            cout << psJuc[i].numar << " " << psJuc[i].culoare << " "
                 << psJuc[i + 1].numar << " " << psJuc[i + 1].culoare << " "
                 << psJuc[i + 2].numar << " " << psJuc[i + 2].culoare << '\n';

    cout << '\n' << "In functie de culoare" << '\n';
    for (int i = 0; i < psJuc.size() - 2; i++)
        for (int j = i + 1; j < psJuc.size() - 1; j++)
            for (int k = j + 1; k < psJuc.size(); k++)
                if (psJuc[i].culoare == psJuc[j].culoare && psJuc[i].culoare == psJuc[k].culoare)
                    cout << psJuc[i].numar << " " << psJuc[i].culoare << " "
                         << psJuc[j].numar << " " << psJuc[j].culoare << " "
                         << psJuc[k].numar << " " << psJuc[k].culoare << '\n';
}

void lastpiece(vector<piese>& psJuc) {
    piese tmp;
    cin >> tmp.numar >> tmp.culoare;
    while (valid(tmp.numar, tmp.culoare) == 0 || countOccurrences(psJuc, tmp) >= 2) {
        if (countOccurrences(psJuc, tmp) >= 2) {
            cout << "Datele sunt invalide. Aceasta combinatie a fost introdusa de 2 ori. Reintroduceti date conforme: ";
        } else {
            cout << "Datele sunt invalide. Reintroduceti date conforme: ";
        }
        cin >> tmp.numar >> tmp.culoare;
    }
    psJuc.push_back(tmp);
    findLongestFormation(psJuc, tmp); // Call the new function to find the longest formation
}

// Main function
int main() {
    vector<piese> psJuc; // Vector to hold pieces
    read(psJuc); // Read and validate data
    vector<piese> original = psJuc; // Create a copy for original data
    sorting(psJuc, original);
    
    formatie(psJuc);
    
    lastpiece(psJuc);
    cout << endl << endl;

    return 0; // Return 0 to indicate successful completion
}
