//
//  main.cpp
//  partial_florarie
//
//  Created by Raul Constantin on 25.11.2024.
//

#include <iostream>
#include <fstream>
#include "QuickSort.h"


ifstream fin("date.txt");



vector<Floare> citire()
{
    int n;
    bool ok=0;
    fin>>n;
    vector<Floare> f(n);
    for(int i=0;i<n;i++)
    {fin>>f[i].nume>>f[i].culoare>>f[i].pret;
        for(int j=0;j<i&&ok==0;j++)
            if((f[i].nume == f[j].nume)&&(f[i].culoare==f[j].culoare)&&(f[i].pret == f[j].pret)) ok=true;
        
    }
    
    if(ok) cout<<"Exista 2 flori perfect identice in vector!"<<'\n';
    else cout<<"Nu exista 2 flori perfect identice in vector."<<'\n';
    
    
    return f;
}

void culoare_Predominanta(vector<Floare> fl)
{
    struct culoareID{
        int ID;
        string culoare;
        short ap=0;
    };
    
    vector<culoareID> clr;
    int k=1;
    
    int mxcul_ap = -1;
    string mxcul;
    
    int ct_flori = 0; // pentru cate flori au culoarea cu aparitii maxime
    
    for(const auto &el:fl)
    {   bool ok_clr = false;
        for(int i=0;i<clr.size()&&ok_clr == 0;i++) //parcurg vect de culori si caut daca a mai fost culoarea resp
            if(el.culoare == clr[i].culoare) {clr[i].ap++;
                ok_clr = 1;
                if(clr[i].ap>mxcul_ap) {
                    mxcul_ap = clr[i].ap; mxcul = el.culoare;
                }
            }
        if(ok_clr == 0) //daca nu am gasit culoarea deloc
        {clr.push_back({k++, el.culoare,0});} //adaug culoarea in vectorul de culori
    }
    
    for(auto elem: fl)
        if(elem.culoare == mxcul) ct_flori++;
    
    cout<<"Culoarea maxim predominanta este: "<<mxcul<<" si apare de "<<ct_flori<<" ori in vectorul de flori."<<'\n';
}


int verificare_Sortare_Desc(vector<Floare> fl)
{
    for(int i=0;i<fl.size()-1;i++)
        if(fl[i].pret<fl[i+1].pret) return 0;
    
    return 1;
}


int cautBin_floare(vector<Floare> fl, int st, int dr, float x, Floare &fl_cautata) {
    if (st > dr) return 0; // Dacă nu găsim elementul
    int mij = (st + dr) / 2;
    
    if (abs(fl[mij].pret - x) < 0.0001) {
        fl_cautata = fl[mij];
        return 1;
    }
    else if (fl[mij].pret > x) {
        return cautBin_floare(fl, mij + 1, dr, x, fl_cautata);
    }
    return cautBin_floare(fl, st, mij - 1, x, fl_cautata);
}


void constructieBuchet( vector<Floare> fl, int T, string C)
{
    vector<Floare> floriC;
    
    for(int i= fl.size()-1;i>=0;i--)
        if(fl[i].culoare == C) floriC.push_back(fl[i]);
    
    if(floriC.size()==0)
    {cout<<"Nu exista nicio floare de culoarea "<<C<<" !"<<'\n';
        return;}
    if(fl.size()<T)
        cout<<"Nu exista suficiente flori pentru a construi un buchet de "<<T<<" flori."<<'\n';
    
    
    // Altfel incepe constructia buchetului
    
    vector<Floare> buchet;
    float pretTotal = 0;
    short floriAdaugate;
    
    buchet.push_back(floriC[0]);
    floriAdaugate = 1;
    
    for(int i=fl.size()-1; i>=0;i--)
    { if(floriAdaugate >=T) break; //Am terminat buchetul, avem T flori
        if(fl[i].culoare!= C || buchet.size() == 1) {
            buchet.push_back(fl[i]);
            pretTotal += fl[i].pret;
            floriAdaugate++;
        }}
        
        if(buchet.size() < T) {
            cout<<" Nu am putut forma un buchet cu "<<T<<" flori.";
            return;
        }
        
        cout<<"Buchetul format are pretul minim: "<<pretTotal<<'\n';
        for(auto floare: buchet)
            cout<<'\t'<<floare.nume<<" "<<floare.culoare<<" "<<floare.pret<<'\n';
        
    }


void afisare(vector<Floare> fl)
{
    for(const auto & elem: fl)
        cout<<elem.nume<<" "<<elem.culoare<<" "<<elem.pret<<'\n';
}

int main(int argc, const char * argv[]) {
    vector<Floare> fl = citire();
    
    culoare_Predominanta(fl);
    
    if(verificare_Sortare_Desc(fl)==0) { cout<<"Vectorul nu este sortat descrescator dupa preturi!"<<'\n';
        quickSort(fl, 0, fl.size()-1);}
    
    cout<<endl;
    
    afisare(fl);
    
    cout<<'\n'<<"Subpunctul C)ii."<<'\n';
    
    Floare fl_caut;
    if(cautBin_floare(fl, 0, fl.size()-1, 7.0, fl_caut)==1)
    {
        cout<<"Am gasit floarea: "<<'\n';
        cout<<'\t'<<"Floarea are numele de "<<fl_caut.nume<<", culoarea de "<<fl_caut.culoare<<" si pretul de "<<fl_caut.pret<<'\n';
    }
    
    else cout<<"Nu am gasit floarea pe care o cautati."<<'\n';
    
    constructieBuchet(fl, 2, "Yellow");
    
    return 0;
}
