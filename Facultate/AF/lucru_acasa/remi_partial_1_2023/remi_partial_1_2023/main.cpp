//
//  main.cpp
//  remi_partial_1_2023
//
//  Created by Raul Constantin on 23.11.2024.
//

#include <iostream>
#include "QuickSort.h"
#include <vector>
#include <fstream>

using namespace std;



ifstream fin("data.in");

std::vector<Piesa> citire()
{
    std::vector<Piesa> rummy;
    
    for(int i=0;i<14;i++)
    {
        Piesa tmp;
        fin>>tmp.numar>>tmp.culoare;
        rummy.push_back(tmp);
    }
    
    return rummy;
}

bool validarePiesa(Piesa tmp)
{
    
    if(!(tmp.culoare == "negru"||tmp.culoare== "albastru" || tmp.culoare == "rosu"|| tmp.culoare =="galben")) return 0;
    if(tmp.numar<1||tmp.numar>13) return 0;
    
    return 1;
}


bool validare(std::vector<Piesa> v)
{
    vector<short> nrPiese(104);
    for(const auto & elem: v)
    {
        if(validarePiesa(elem)==0) {cout<<"Vectorul de piese nu este valid complet! Reincercati citirea datelor!";
            return -1;}
    }
    
    
    
    for(int i=0;i<v.size()-1;i++)
    {   int ct = 0;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i].numar == v[j].numar && v[i].culoare == v[j].culoare) ct++;
        }
        if(ct>=2) return 0;
    }
    
    return 1;
    
}

bool verifSortat( vector<Piesa> v)
{
    for(size_t i=0;i<v.size()-1;i++)
    {
        size_t j=i+1;
        if(v[i].numar>v[j].numar) return 0;
    }
    
    return 1;
}

int nrPozModifPiese( vector<Piesa> orig, vector< Piesa> v)
{
    int ct= 0;
    
    for(int i=0;i<orig.size();i++)
        if(orig[i].numar!=v[i].numar ) ct++;
    
    return ct;
    
}


void afisare(std::vector<Piesa> v)
{
    for(const auto & elem: v)
        cout<<elem.numar<<" "<<elem.culoare<<'\n';
}


void formatieCuloriDiferite( vector<Piesa> v)
{
    int ct=0;
    for(int i=0;i<v.size()-2;i++)
    {
        
        ct = 1;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i].numar==v[j].numar) ct++;
            else break;}
        
        
        if(ct>2)
        {
            cout<<"Formatie: "<<'\n'<<'\t';
            for(int k = 0; k<ct; k++)
                cout<<v[i+k].numar<<" "<<v[i+k].culoare<<" ";
            cout<<'\n';
        }
        
    }
}

void formatieNumereConsec(std::vector<Piesa> v)
{
    int ct, nrCrt;
    
    // Sortare pentru a fi sigur că piesele sunt ordonate înainte de a verifica secvențele
    std::sort(v.begin(), v.end(), [](const Piesa& a, const Piesa& b) {
        return a.numar < b.numar || (a.numar == b.numar && a.culoare < b.culoare);
    });

    for (int i = 0; i < v.size() - 2; ++i)
    {
        nrCrt = v[i].numar;
        ct = 1;  // Contorizează numărul de piese consecutive

        for (int j = i + 1; j < v.size(); ++j)
        {
            // Dacă piesele sunt de aceeași culoare și numerotarea este consecutivă
            if (v[j].culoare == v[i].culoare && v[j].numar == nrCrt + 1)
            {
                ct++;
                nrCrt = v[j].numar;  // Actualizează valoarea pentru numărul consecutiv
            }
            else
            {
                break;  // Nu mai continuăm căutarea, ieșim din bucla interioară
            }
        }

        if (ct >= 3)  // Dacă am găsit cel puțin 3 piese consecutive
        {
            cout << "Formatie cu aceleasi culori dar numere consecutive: " << '\n' << '\t';
            for (int k = 0; k < ct; k++)  // Afișează toate piesele din formatie
                cout << v[i + k].numar << " " << v[i + k].culoare << " ";
            cout << '\n';
        }
    }
}


int main(int argc, const char * argv[]) {
    vector<Piesa> rmy = citire();
    
    vector <Piesa> original = rmy;
    
    if(validare(rmy)) cout<<"Succes in citirea vectorului de piese!"<<'\n';
    else {cout<<"Vectorul de piese nu este valid complet! Reincercati citirea datelor!";
        rmy.clear();
        rmy = citire();}
    
    if(verifSortat(rmy))
        cout<<"Vectorul este deja sortat crescator dupa numerele de pe piese!"<<'\n';
    
    else
    {
        int ct=0;
        cout<<"Vectorul de piese nu este sortat crescator dupa numarul de piese. "<<'\n'<<'\t'<<"Se incepe sortarea acestuia...";
        quickSort(rmy, 0, rmy.size()-1, verifSortat(rmy),ct);
        
        cout<<'\n'<<"Si-au schimbat pozitia "<<nrPozModifPiese(original, rmy)<<" piese."<<'\n';
    }
    
    formatieCuloriDiferite(rmy);
    cout<<'\n'<<'\n';
    
    formatieNumereConsec(rmy);
    
//    afisare(rmy);
    
    Piesa piesaFinala;
    do{
        cin>>piesaFinala.numar>>piesaFinala.culoare;
    }while(validarePiesa(piesaFinala)!=1);
    
    rmy.push_back(piesaFinala);
    
    formatieCuloriDiferite(rmy);
    formatieNumereConsec(rmy);
    
    return 0;
}
