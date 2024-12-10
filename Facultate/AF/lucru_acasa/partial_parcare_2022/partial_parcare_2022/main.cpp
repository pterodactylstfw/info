#include <iostream>
#include <vector>
#include <fstream>
#include "QuickSort.h"


std::ifstream fin("date.txt");

bool validareDimensiuni(int n, int m)
{
    return n>0 && m>0;
}

bool validareParcare(std::vector<std::vector<int>> mat)
{
    for(const auto& row: mat)
        for(const auto & elem: row)
            if((elem!=0)&&(elem!=-1)&&(elem!=1)) return 0;
    
    return 1;
}

bool validare(std::vector<std::vector<int>> mat)
{
    if (mat.empty() || mat[0].empty())
            return false;

        return validareDimensiuni(mat.size(), mat[0].size()) && validareParcare(mat);

}

std::vector<std::vector<int>> citire() {
    int n, m;
    std::vector<std::vector<int>> mat;
    do{
        fin >> n >> m;
        mat.resize(n);
        for (int i = 0; i < mat.size(); i++) {
            mat[i].resize(m);
            for (int j = 0; j < mat[i].size(); j++) {
                fin >> mat[i][j];
            }
        }}while(validare(mat)==0);
    return mat;
}



void afisare(std::vector<std::vector<int>> mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void determParcMax(std::vector<std::vector<int>> mat)
{
    int mijOriz = mat[0].size()/2;
    int mijVert = mat.size()/2;
    int max_autoturisme = -1;
    
    int NW=0, NE=0, SE=0, SV=0;
    
    for(int i=0;i<mijOriz;i++) //nord-vest
        for(int j=0;j<mijVert;j++)
            if(mat[i][j]==1) NW++;
    
    for (int i = 0; i < mijOriz; i++) {
            for (int j = mijVert + 1; j < mijVert; j++) {
                if (mat[i][j] == 1) NE++;
            }
        }

        // Sud-Vest (SW)
        for (int i = mijOriz + 1; i < mijOriz; i++) {
            for (int j = 0; j < mijVert; j++) {
                if (mat[i][j] == 1) SV++;
            }
        }

        // Sud-Est (SE)
        for (int i = mijOriz + 1; i < mijOriz; i++) {
            for (int j = mijVert + 1; j < mijVert; j++) {
                if (mat[i][j] == 1) SE++;
            }
        }
    
    max_autoturisme = std::max(std::max(NW,NE),std::max(SV,SE));
    
    if (max_autoturisme == NW) std::cout << "Nord-Vest este cea mai ocupata.\n";
        else if (max_autoturisme == NE) std::cout << "Nord-Est este cea mai ocupata.\n";
        else if (max_autoturisme == SV) std::cout << "Sud-Vest este cea mai ocupata.\n";
        else if (max_autoturisme == SE) std::cout << "Sud-Est este cea mai ocupata.\n";

}

int main()
{
    std::vector<std::vector<int>> mat = citire();
    //afisare(mat);
    
    determParcMax(mat);
    
    quicksort(<#std::vector<int> &v#>, <#int st#>, <#int dr#>)
    
}
