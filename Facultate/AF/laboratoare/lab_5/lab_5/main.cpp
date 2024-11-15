#include <iostream>
#include <vector>

/*
 TEORIE VECTORI STL
 std::vector<int> v;
 
//    //adaugarea la sfarsit in vector se face cu v.push_back(x);
 int x=2;
 v.push_back(x);
 std::cout<<v.size()<<'\n';
 
 //adaugarea pe o pozitie
 
 v.insert(v.begin(),3);
 v.insert(v.begin()+1, 4);
 
 //stergere
 v.erase((v.begin())+1);
 
 for(int i=0;i<v.size();i++)
     std::cout<<v[i]<<" "; //sau v.at(v.begin()+1);
 
 */

std::vector<int> citire()
{
    int dim;
    std::vector<int> vect;
    int elem;
    std::cin>>dim;
    for(int i=0;i<dim;i++)
    {
        std::cin>>elem;
        vect.push_back(elem);
    }
    return vect;
}

std::vector<int> citire2()
{
    int dim;
    std::cin>>dim;
    std::vector<int> vect;
    vect.resize(dim); // !!!
    
    for(int i=0;i<dim;i++)
        std::cin>>vect[i];
    
    return vect;
}

std::vector<int> citire3()
{
    int dim;
    std::cin>>dim;
    std::vector<int> vect;
    
    for(int i=0;i<dim;i++)
        std::cin>>vect[i];
    
    return vect;
}



int main()
{
    std::vector<int> vect = citire2();
    
    for(auto elem:vect)
        std::cout<<elem<<" ";
    
    
}
