////
////  main.cpp
////  lab_divide_et_impera(lab_10) - fisa 1
////
////  Created by Raul Constantin on 20.11.2024.
////
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int suma_elem(vector<int>v, int st, int dr) //pb 1a)
//{
//    if(st==dr) return v[st];
//    
//    int mij = (st+dr)/2;
//    
//    return suma_elem(v, st, mij) + suma_elem(v, mij+1, dr);
//    
//}
//
//int elem_max(vector<int> v, int st, int dr) // pb 1b)
//{
//    if(st==dr)
//    {
//        return v[st];
//        
//    }
//    int mij = (st+dr)/2;
//    
//    return max(elem_max(v, st, mij),elem_max(v, mij+1, dr));
//}
//
//
//
//int partitionare (vector<int> &vect, int st, int dr)
//{
//    int i= st-1, pivot= vect[dr];
//    for(int j= st ; j<dr; j++)
//    {
//        if(vect[j]<= pivot)
//        {
//            i++;
//            swap(vect[i],vect[j]);
//        }
//    }
//    swap(vect[i+1], vect[dr]);
//    return i+1;
//}
//
//int cautare_elem_x_minim(vector<int>& vect, int st, int dr, int x) {
//    if (st <= dr) {
//        int pivotIndex = partitionare(vect, st, dr);
//
//        
//        int rang = pivotIndex - st + 1;
//
//        if (rang == x) {
//            return vect[pivotIndex];
//        } else if (x < rang) {
//            return cautare_elem_x_minim(vect, st, pivotIndex - 1, x);
//        } else {
//            return cautare_elem_x_minim(vect, pivotIndex + 1, dr, x - rang);
//        }
//    }
//    return -1;
//}
//
//
//int main(int argc, const char * argv[]) {
//    
//    int n;
//    cin>>n;
//    vector<int> vect(n);
//    
//    for(int i=0;i<n;i++) cin>>vect[i];
//    
//    cout<<suma_elem(vect, 0, vect.size()-1)<<'\n';
//    cout<<elem_max(vect, 0, vect.size()-1)<<'\n';
//    cout<<cautare_elem_x_minim(vect, 0, vect.size()-1, 3);
//    return 0;
//}
//
//
//
///*
// 5
// 
// 5 3 2 1 3
// 
// */
