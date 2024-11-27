#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


std::ifstream fin("date.txt");

std::vector<int> citire()
{
    std::vector<int> vect;
    int n;
    
    std::cin>>n;
    
    vect.resize(n);
    
    for(int i=0;i<vect.size();i++)
        std::cin>>vect[i];
    
    return vect;
}

void afisare(std::vector<int> vect)
{
    for(const auto& elem: vect)
        std::cout<<elem<<" ";
    std::cout<<'\n';
}

std::vector<std::vector<int>> citire()
{
    std::vector<std::vector<int>> matr;
    int n, m;
    std::cin>>n>>m;
    
    matr.resize(n);
    for(int i=0;i<n;i++) matr[i].resize(m);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            std::cin>>matr[i][j];
    
    return matr;
}
