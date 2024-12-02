#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

ifstream fin("date.txt");

bool validareDimensiuni(int n, int m)
{
    return n>0 && m>0;
}

bool validarePaduriAdiacente(const std::vector<std::vector<int>>& terrain) {
    int n = terrain.size();
    int m = terrain[0].size();
    
    for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Verifică stânga
                if (j > 0 && terrain[i][j] == terrain[i][j - 1]) {
                    return false;
                }
                // Verifică dreapta
                if (j < m - 1 && terrain[i][j] == terrain[i][j + 1]) {
                    return false;
                }
                // Verifică sus
                if (i > 0 && terrain[i][j] == terrain[i - 1][j]) {
                    return false;
                }
                // Verifică jos
                if (i < n - 1 && terrain[i][j] == terrain[i + 1][j]) {
                    return false;
                }
            }
        }
        return true;
}

bool validare(int n, int m, vector<vector<int>> v)
{
    return validareDimensiuni(n,m) && validarePaduriAdiacente(v);
}

vector<vector<int>> citire()
{
    vector<vector<int>> v;
    int n,m;
    do{
        fin>>n>>m;
        v.resize(n);
        for(int i = 0 ;i < n ;i ++){
            v[i].resize(m);
            for( int j = 0; j<m; j++)
                fin>>v[i][j];}
        cout<<validare(n, m, v)<<" ";
    }while(validare(n,m,v)==0);
    
    return v;
}

void afisare(vector<vector<int>> v)
{
    for( auto row: v)
    {for( auto elem:row)
        cout<<elem<<" ";
        cout<<'\n';}
}

int main()
{
    vector<vector<int>> padure = citire();
    afisare(padure);
}
