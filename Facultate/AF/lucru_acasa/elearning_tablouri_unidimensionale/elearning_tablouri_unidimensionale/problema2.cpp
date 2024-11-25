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
//
//int main() {
//    int n;
//    cin >> n;
//    int *a = new int[n];
//    
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    
//    for (int i = 1; i < n - 1; ) {
//        if (a[i] == a[i - 1] + a[i + 1]) {
//            
//            for (int j = i; j < n - 1; j++) {
//                a[j] = a[j + 1];
//            }
//            n--;
//        } else {
//            i++;
//        }
//    }
//    
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    
//    delete[] a; 
//    return 0;
//}
