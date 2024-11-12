#include <iostream>
#include <vector>
using namespace std;


void citire(unsigned &n,unsigned &a,unsigned &m)
{
    cin>>n>>a>>m;
}

int cmmdc(int a, int b)
{
    if(b==0) return a;
    return cmmdc(b,a%b);
}

vector<int> modulo_vect(int n){
    vector<int> modulo_vect;
    for(int i=1;i<n;i++)
        if(cmmdc(i, n)==1) modulo_vect.push_back(i);
    
    return modulo_vect;
}



vector<int> rezolvaEc(int a, int m, int n) {
    vector<int> sol;
    for (int x = 0; x < n; ++x) {
        if ((a * x) % n == m) {
            sol.push_back(x);
        }
    }
    return sol;
}


int phi_n(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

// Funcție pentru a calcula (a ^ m) % n folosind exponențiere modulară rapidă
int expmodulara(int a, int m, int n) {
    int rez = 1;
    a = a % n;
    while (m > 0) {
        if (m % 2 == 1) {  // Dacă m este impar
            rez = (rez * a) % n;
        }
        m = m / 2;
        a = (a * a) % n;
    }
    return rez;
}

// Funcție pentru calculul a^m % n folosind Teorema lui Euler
int teoremaEuler(int a, int m, int n) {
    if (cmmdc(a, n) == 1) {  // a și n sunt coprime
        int phiN = phi_n(n);
        m = m % phiN;
    }
    return expmodulara(a, m, n);
}


// Functia pentru calcularea puterilor modulo n
int putereMod(int baza, int exp, int n) {
    int rez = 1;
    baza = baza % n;  // Reducem base inainte de calcule
    while (exp > 0) {
        if (exp % 2 == 1)  // Daca exp este impar
            rez = (rez * baza) % n;
        baza = (baza * baza) % n;  // Ridicam base la puterea urmatoare
        exp = exp / 2;
    }
    return rez;
}

// Functia pentru a gasi elementele nilpotente
vector<int> calculeazaNil(int n) {
    vector<int> nilpot;
    for (int x = 1; x < n; ++x) {
        for (int k = 1; k < n; ++k) {
            if (putereMod(x, k, n) == 0) {
                nilpot.push_back(x);
                break;  // Daca am gasit o putere pentru care x^k = 0, adaugam x si trecem la urmatorul
            }
        }
    }
    return nilpot;
}

void afisare(vector<int> v)
{
    for(const auto & elem: v)
        cout<<elem<<" ";
    
}

void afisareSol(vector<int>sol, int n, int m, int a)
{
    cout<<"Subpunctul b)"<<'\n';
    if(sol.size()==0) {
        cout<<"Nu exista solutii pentru ecuatia a*x=m in Zn!";
        return;
        
    }
    
    else {
        cout << "Soluțiile ecuației " << a << " * x = " << m << " în Z_" << n << " sunt: { ";
        afisare(sol);
        cout << "}" << endl;
    }
    cout<<'\n';
    cout<<'\n';
}

void afisareNil(vector<int> v, int n)
{
    cout<<"Subpunctul d)"<<'\n';
    if(v.size()==0) {
        cout<<"Nu exista elemente Nilpotente in Z_"<<n<<" !";
        return;
    }
    
    else {
        cout << "Nil(Z" << n << ") = { ";
        afisare(v);
        cout << "}" << endl;
    }
    cout<<'\n';
}

int main()
{
    unsigned n,a,m;
    citire(n,a,m);
    vector<int> mdl_vect = modulo_vect(n);
    cout<<"Subpunctul a)"<<'\n';
    afisare(mdl_vect);
    
    
    vector<int> sol_b = rezolvaEc(a, m, n);
    
    afisareSol(sol_b, n, m, a);
    
    int result = teoremaEuler(a, m, n);
        cout <<"Subpunctul c)"<<'\n'<<"Rezultatul calculului a^m % n este: " << result << endl;
    
    vector<int> elem_Nil = calculeazaNil(n);
    afisareNil(elem_Nil,n);
}
