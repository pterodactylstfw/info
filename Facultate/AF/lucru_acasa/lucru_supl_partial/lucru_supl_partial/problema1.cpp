#include <iostream>
using namespace std;

std::vector<std::vector<int>> citire_matrice()
{
    int n, m;
    fin>>n>>m;
    std::vector<std::vector<int>> mat;


    mat.resize(n);

    for(int i = 0 ;i< n;i ++)
        mat[i].resize(m);


    for(int i = 0; i<n;i++)
        for(int j = 0;j<m;j++)
        fin>>mat[i][j];

        return mat;
}
