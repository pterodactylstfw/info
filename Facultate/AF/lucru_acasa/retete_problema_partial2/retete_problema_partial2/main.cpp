#include <fstream>
#include <iostream>
#include <vector>
#include "QuickSort.h"
std::ifstream fin("date.txt");


bool valid_ingr(const Ingredient& ingr) {
    return (ingr.ID >= 1 && ingr.ID <= 99);
}

bool valid_reteta(const Reteta& reteta, int n) {
    if (n < 5 || n > 10) return false;
    if (reteta.ID_reteta < 100 || reteta.ID_reteta > 1000) return false;
    for (const auto& ingredient : reteta.ingr) {
        if (!valid_ingr(ingredient)) return false;
    }
    return true;
}

int id_ingr_max;

std::vector<Reteta> citire(){
    std::vector<Reteta> vect_ret;
    unsigned n;

    // Check if file is open
    if (!fin.is_open()) {
        std::cerr << "Error: could not open file 'date.txt'\n";
        return vect_ret;
    }
    
    fin >> n;
    vect_ret.resize(n);
    
    for(int i = 0; i < n; i++)
    {   do{
        fin >> vect_ret[i].ID_reteta;
        fin >> vect_ret[i].pret;
        fin >> vect_ret[i].nrIngr;
        vect_ret[i].ingr.resize(vect_ret[i].nrIngr);
        
        for(int j = 0; j < vect_ret[i].nrIngr; j++)
        {
            fin >> vect_ret[i].ingr[j].ID;
            fin >> vect_ret[i].ingr[j].nume;
            fin >> vect_ret[i].ingr[j].calorii;
            vect_ret[i].calorii += vect_ret[i].ingr[j].calorii;
            if(id_ingr_max<vect_ret[i].ingr[j].ID) id_ingr_max = vect_ret[i].ingr[j].ID;
        }}while(valid_reteta(vect_ret[i], n)==0);
    }
    
    return vect_ret;
}

void ingr_max(std::vector<Reteta> v)
{
    /*
     ca sa retin care e ingredientul cu ap maxime ma voi folosi de faptul ca elementele au id-uri consecutive iar ele pot fi accesate apoi prin intermediul numelui.
     */
    
    std::vector<unsigned> ingr_max;
    struct maxim_ingr {
        unsigned short id_ingr=0;
        unsigned short val_max=0;
        std::string nume;
    };
    
    maxim_ingr maxim_ingr;
    std::cout<<id_ingr_max;
    ingr_max.resize(id_ingr_max+1,0);
    
    for(int i=0;i<v.size();i++)
    {
        for(const auto & elem: v[i].ingr) {ingr_max[elem.ID]++; //vect de ap;
            if(maxim_ingr.val_max<ingr_max[elem.ID]) {maxim_ingr.id_ingr = elem.ID;
                maxim_ingr.val_max = ingr_max[elem.ID];
                maxim_ingr.nume = elem.nume;}}
        
    }
    
    std::cout<<"Ingredientul cel mai comun din toate retetele este: "<<maxim_ingr.nume<<" cu ID: "<<maxim_ingr.id_ingr<<" si"<<maxim_ingr.val_max<<" aparitii."<<'\n';
    
    std::cout<<"Acesta se regaseste in retetele cu ID: ";
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].ingr.size();j++)
        {
            if(v[i].ingr[j].ID==maxim_ingr.id_ingr) {std::cout<<v[i].ID_reteta<<" ";
                break;}
        }
    }
    
}

void afisare(const std::vector<Reteta>& v)
{
    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << "ID_RETETA pozitia " << i+1 << " : "
                  << v[i].ID_reteta << " cu "
                  << v[i].calorii << " calorii si pret de "
                  << v[i].pret << " lei." << '\n';
        
        std::cout << "Ingredientele din reteta " << i+1 << " sunt:" << '\n';
        
        for(const auto& elem: v[i].ingr)
        {
            std::cout << "Ingredientul " << elem.nume
                      << " cu ID_Ingredient: " << elem.ID
                      << " si cu calorii: " << elem.calorii << '\n';
        }
        std::cout << '\n';
    }
}


bool verif_sort_calorii(std::vector<Reteta> v)
{
    for(int i=0;i<v.size()-1;i++)
        if(v[i].calorii<v[i+1].calorii) return false; //daca nu e sort desc return false
    return true;
}

int cautBin_calorii(std::vector<Reteta>a, int st, int dr, int x) {
    
    if(st > dr) return 0;
    if(st == dr) {
        if(a[st].calorii == x) return st;
        else return 0;
    }
    int mij = (st + dr) / 2;
    if(a[mij].calorii == x) return 1;
    else if(a[mij].calorii < x) return cautBin_calorii(a, mij + 1, dr, x);
    else return cautBin_calorii(a, st, mij - 1, x);
}

int cautBin_ingr(std::vector<Reteta>a, int st, int dr, int x) {
    
    if(st > dr) return 0;
    if(st == dr) {
        if(a[st].nrIngr == x) return st;
        else return 0;
    }
    int mij = (st + dr) / 2;
    if(a[mij].nrIngr == x) return 1;
    else if(a[mij].nrIngr < x) return cautBin_ingr(a, mij + 1, dr, x);
    else return cautBin_ingr(a, st, mij - 1, x);
}


int main() {
    std::vector<Reteta> vect_retete = citire();
    //afisare(vect_retete);
    
    ingr_max(vect_retete);
    std::cout<<'\n';
    quickSort(vect_retete, 0, vect_retete.size()-1, verif_sort_calorii(vect_retete));
    afisare(vect_retete);
    
    int x, y;
    std::cout<<"Introduceti x si y:";
    std::cin>>x>>y;
    
    if(cautBin_calorii(vect_retete, 0, vect_retete.size()-1, x)!=0) std::cout<<"am gasit reteta cu "<<x<<" calorii la pozitia "<<cautBin_calorii(vect_retete, 0, vect_retete.size()-1, x);
    else std::cout<<" nu am gasit reteta cu x calorii.";
    std::cout<<'\n'<<'\n';
    if(cautBin_ingr(vect_retete, 0, vect_retete.size()-1, y)!=0) std::cout<<"am gasit reteta cu "<<y<<" ingrediente la pozitia "<<cautBin_ingr(vect_retete, 0, vect_retete.size()-1, y);
    else std::cout<<" nu am gasit reteta cu x calorii.";
    
    return 0;
}
