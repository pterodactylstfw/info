////
////  main.cpp
////  elearning_tablouri_unidimensionale - probleme de pe elearning
////
////  Created by Raul Constantin on 18.11.2024.
////
//
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//ifstream fin("date.txt");
//
//int prim(int x, int d = 3)
//{
//    if(x!=2&&x%2==0||x<2) return 0;
//    if(d*d>x) return 1;
//    if(x%d==0) return 0;
//    return prim(x,d+2);
//}
//
//int mincif(int x)
//{
//    int mn = INT_MAX;
//    while(x)
//    {
//        if(x%10<mn) mn=x%10;
//        x/=10;
//    }
//    
//    return mn;
//}
//
//int main(int argc, const char * argv[]) {
//    int n;
//    cin>>n;
//    int * a = new int[n];
//    for(int i=0;i<n;i++)
//        cin>>a[i];
//    
//    for(int i=0;i<n;i++)
//        if(i%2)
//            if(prim(a[i])) a[i] = 0;
//            else a[i] = 1;
//            else a[i]= mincif(a[i]);
//    
//    for(int i=0; i<n; i++)
//        cout<<a[i]<<" ";
//        
//    
//    delete[] a;
//}
//
//
