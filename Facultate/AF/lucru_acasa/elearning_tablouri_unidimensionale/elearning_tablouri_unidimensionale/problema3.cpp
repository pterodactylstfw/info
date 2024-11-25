//
//  main.cpp
//  elearning_tablouri_unidimensionale - probleme de pe elearning
//
//  Created by Raul Constantin on 18.11.2024.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.txt");

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int * a = new int[n*3];
    
    for(int i = 0 ;i < n; i++)
        cin >> a[i];
    
    
    for(int i=n-1;i>0;)
    {
        a[i+2]=a[i];
        a[i+1]=a[i]*a[i-1];
        i--;
    }
    
    for(int i = 0 ; i < n; i ++)
        cout << a[i] << " ";
    delete[] a;
    return 0;
}
