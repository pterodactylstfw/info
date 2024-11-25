//
//  problema3.cpp
//  lab_divide_et_impera(lab_10)
//
//  Created by Raul Constantin on 20.11.2024.
//

#include <iostream>
#include <vector>
using namespace std;

int cautElem(vector<vector<int>>matr, int sus, int jos, int n, int k)
{
    int mij = (sus+jos)/2;
    if(matr[mij][n-1]) return cautElem(matr, mij+1, jos, n, k);
    else if(k< matr[mij][0])
        return cautElem(matr, sus, mij-1, n, k);
}


int main()
{
    int n,m;
    cin>>m>>n;
    
    vector<vector<int>>mat(m);
    for(int i=0;i<m;i++)
    {
        mat[i].resize(n);
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    
    cout<<cautElem;
}
