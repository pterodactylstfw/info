//
//  problema5.cpp
//  lab_divide_et_impera(lab_10)
//
//  Created by Raul Constantin on 20.11.2024.
//

#include <iostream>
#include <vector>
using namespace std;

int cautBin(vector<int>v, int st, int dr) {
    if(st<dr){
        int mij = (st + dr) / 2;
        if(v[mij] == mij) return mij;
        else if(v[mij] > mij) return cautBin(v, mij + 1, dr);
        else return cautBin(v, st, mij - 1);}
    return -1;
}



int main()
{
    int n;
    cin>>n;
    
    vector<int>v(n);
    
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    cout<<cautBin(v, 0, v.size()-1);
    
    
}
