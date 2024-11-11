#include <iostream>
#include <fstream>
#include <vector>

std::ifstream fin("date.txt");

 struct alergator{
    unsigned ID;
    std::string nume_pren;
    float viteza, rezistenta;
};


void citire(std::vector<alergator>&alg)
{
    alergator tmp;
    int n;
    fin>>n;
    for(int i=0;i<n;i++)
    {
        bool ok=true;
        do{
            ok=true;
            
            fin>>tmp.ID;
            if(tmp.ID<300||tmp.ID>1500) ok=false;
            fin>>tmp.nume_pren;
            if(tmp.nume_pren.size()==0) ok=false;
            fin>>tmp.rezistenta;
            if(tmp.rezistenta<1) ok=false;
            fin>>tmp.viteza;
            if(tmp.viteza<1) ok=false;
            if(ok) alg.push_back(tmp);
            else std::cout<<"esuat, repeta citirea";
        }while(ok==0);
    }
    
    
}
void afisare(std::vector<alergator>alg)
{
    for(const auto& elem:alg)
        std::cout<<elem.ID<<" "<<elem.nume_pren<<" "<<elem.rezistenta<<" "<<elem.viteza<<'\n';
}



int valid(std::vector<alergator>alg)
{
    for(int i=0;i<alg.size()-1;i++)
        if(alg[i].viteza>alg[i+1].viteza) return 0;
    return 1;
}

void QuickSort(std::vector<alergator>&alg, int st, int dr)
{
    if(st < dr)
    {
        //pivotul este inițial v[st]
        int m = (st + dr) / 2;
        alergator aux = alg[st];
        alg[st] = alg[m];
        alg[m] = aux;
        int i = st , j = dr, d = 0;
        while(i < j)
        {
            if(alg[i].viteza > alg[j].viteza)
            {
                aux = alg[i];
                alg[i] = alg[j];
                alg[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(alg, st , i - 1);
        QuickSort(alg, i + 1 , dr);
    }
    
}

float dif_viteza(std::vector<alergator>alg)
{
    return alg[alg.size()-1].viteza-alg[0].viteza;
}


bool binarysearch(std::vector<alergator>alg, int st, int dr, float x)
{
    
    //Explicații: infoas.ro
    if(st > dr) return 0;
    if(st == dr) {
        if(alg[st].viteza == x) return 1;
        else return 0;
    }
    int mij = (st + dr) / 2;
    if(alg[mij].viteza == x) return 1;
    else if(alg[mij].viteza < x) return binarysearch(alg, mij + 1, dr, x);
    else return binarysearch(alg, st, mij - 1, x);
}

int main()
{
    std::vector<alergator> vect_alerg;
    citire(vect_alerg);
    
//    std::cout<<'\n';
    if(!valid(vect_alerg)) QuickSort(vect_alerg, 0, vect_alerg.size()-1);
//    afisare(vect_alerg); pt verif
    afisare(vect_alerg);
    /*
     pentru validarea initierii sortarii avem de a face cu o cautare liniara, clasica, de complexitate O(n),
     iar pentru sortare utilizam algoritmul de sortare QuickSort ce are complexitatea de timp O(nlogn).
     de spatiu ?
     */
    
    std::cout<<dif_viteza(vect_alerg);
    
    std::cout<<'\n'<<binarysearch(vect_alerg, 0, vect_alerg.size()-1,dif_viteza(vect_alerg));

    
}

