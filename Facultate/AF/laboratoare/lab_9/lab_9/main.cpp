//
//  Probleme Căutări - problemele 3 și 4
//  lab_9
//
//  Created by Raul Constantin on 13.11.2024.
//

/*
 problema 3
    o idee este sa ordonam un vector crescator si pe celalalt descrescator
    apoi verificam in functie de k daca ne permite sa respectam cerinta ( a[i] + b[i} >= k )
 */

#include <iostream>
#include <vector>
#include <algorithm> // pt std::sort

void afisare(std::vector<int> v)
{
    for(const auto &elem: v)
        std::cout<<elem<<" ";
    std::cout<<'\n';
}

void aranjare_vect(std::vector<int> a, std::vector<int> b, int prag) //pb 3
{
    std::sort(a.begin(), a.end());
    
    afisare(a);
    
    std::sort(b.begin(), b.end(), std::greater<int>());
    
    afisare(b);
    if(a.size()==b.size())
    {for(int i=0;i<a.size();i++)
        if(a[i]+b[i]<prag)
        {std::cout<<"Nu";
            return;}
        std::cout<<"Succes! Criteriu indeplinit.";}
    else
    {
        std::cout<<"Nu";
    }
    
}

void verificare(std::vector<int> a, std::vector<int>b) // pb 4
{
    int i=0, j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i] == b[j]) {i++;
            j++;}
        else i++;
    }
    
    if(j!=b.size())
        std::cout<<"nu il include";
    else std::cout<<"il include";
    
    // alte variante pentru ex 4
    /*
        daca nu ne intereseaza ordinea => sortam vectorii(O(nlogn+nlogn), apoi la fel (O(n+m))
        verific fiecare elem din b cu cel din a
     */
    
}



int main()
{
//    std::vector<int> a = {1, 0, 7, 6, 2};
//    std::vector<int> b = {2, -3, 1, 5, 4};
    std::vector<int> a = {1, 5, 2, 7, 4, 6, 8, 12, 5};
    std::vector<int> b = {2, 4, 8};
//    int prag;
//    std::cin>>prag;
//    aranjare_vect(a, b, prag);
    verificare(a, b);
}
