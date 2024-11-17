//
//  main.cpp
//  din fisierul de probleme cu structuri unde se afla si cea cu pixelii
//
//  Created by Raul Constantin on 13.11.2024.
//

#include <iostream>
#include <fstream>
#include <vector>

std::ifstream fin("reteta.txt");

std::vector<std::vector<std::pair<std::string, int>>> Citire()
{
    int n;
    fin >> n;
    
    std::vector<std::vector<std::pair<std::string, int>>> reteta;
    
    for (int i = 0; i < n; i++)
    {
        int nr;
        fin >> nr;
        std::vector<std::pair<std::string, int>> ing(nr);
        for (int j = 0; j < nr; j++)
            fin >> ing[j].first >> ing[j].second;
        
        reteta.push_back(ing);
    }
    
    return reteta;
}

void ingrComun(std::vector<std::vector<std::pair<std::string, int>>> reteta)
{
    std::vector<std::pair<std::string, int>> fr;
    for(int i=0; i<reteta.size(); i++)
    {
        std::vector<std::pair<std::string, int>>lista;
        for(int j = 0; j < reteta[i].size(); j++)
        {   int poz = Exista
            if()
            }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
