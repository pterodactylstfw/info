#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Funcție pentru a calcula transpunerea unei matrice
vector<vector<double>> transpose(const vector<vector<double>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<double>> transposed(cols, vector<double>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = mat[i][j];
        }
    }
    return transposed;
}

// Funcție pentru înmulțirea a două matrici
vector<vector<double>> multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rows = A.size();
    int cols = B[0].size();
    int common = B.size();
    vector<vector<double>> result(rows, vector<double>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Funcție pentru rezolvarea unui sistem de ecuații folosind metoda Gauss
vector<double> gauss(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    vector<double> x(n, 0);

    // Construirea matricei extinse
    for (int i = 0; i < n; ++i) {
        A[i].push_back(b[i]);
    }

    // Eliminare Gauss
    for (int i = 0; i < n; ++i) {
        // Pivotare
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        swap(A[i], A[maxRow]);

        // Verificare dacă sistemul e singular
        if (fabs(A[i][i]) < 1e-9) {
            throw runtime_error("Sistemul nu are soluții unice.");
        }

        // Normalizare pe linia pivot
        for (int k = i + 1; k <= n; ++k) {
            A[i][k] /= A[i][i];
        }

        // Eliminarea sub pivot
        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i];
            for (int j = i; j <= n; ++j) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    // Substituție înapoi
    for (int i = n - 1; i >= 0; --i) {
        x[i] = A[i][n];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
    }

    return x;
}

int main() {
    int m, n;

    cout << "Introduceți numărul de ecuații (m): ";
    cin >> m;
    cout << "Introduceți numărul de necunoscute (n): ";
    cin >> n;

    vector<vector<double>> A(m, vector<double>(n));
    vector<double> b(m);

    cout << "Introduceți coeficienții matricei A (pe linii):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Introduceți termenii liberi vectorului b:" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    try {
        if (m == n) {
            // Sistem bine determinat
            vector<double> sol = gauss(A, b);
            cout << "Soluția sistemului este:" << endl;
            for (int i = 0; i < n; ++i) {
                cout << fixed << setprecision(6) << "x" << i + 1 << " = " << sol[i] << endl;
            }
        } else if (m > n) {
            // Sistem supra-determinat - folosim metoda celor mai mici pătrate
            auto At = transpose(A);
            auto AtA = multiply(At, A);
            auto Atb = multiply(At, {b});
            vector<double> b_mod;
            for (auto& row : Atb) b_mod.push_back(row[0]);

            vector<double> sol = gauss(AtA, b_mod);

            cout << "Soluția aproximativă (metoda celor mai mici pătrate) este:" << endl;
            for (int i = 0; i < n; ++i) {
                cout << fixed << setprecision(6) << "x" << i + 1 << " = " << sol[i] << endl;
            }
        } else {
            cout << "Sistem sub-determinat: soluții multiple sau infinite." << endl;
        }
    } catch (runtime_error& e) {
        cout << "Eroare: " << e.what() << endl;
    }

    return 0;
}
