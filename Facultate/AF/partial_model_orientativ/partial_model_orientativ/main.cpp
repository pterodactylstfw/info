#include <iostream>
#include <vector>
#include <fstream>

std::ifstream fin("date.in");
struct Floare{
    unsigned pret;
    std::string nume, culoare;
};

void citire(std::vector<Floare>&fl)
{
    
    
    int N;
    fin>>N;
    int k=0; //pt parcurgerea pt validare
    fl.resize(N);
    bool ok=0;
    for(int i=0;i<N;i++){
        fin>>fl[i].nume>>fl[i].culoare>>fl[i].pret;
        
        
        /*
         pentru prima valoare nu compar nimic => pt i=0 nu parcurg vectorul
         dupa ce am citit mai multe valori => i>0
            folosesc un k care merge de la 0 pana la
         
         */
        if(k!=0)
        {
            for(int j=0;j<k;j++)
                if(fl[j].culoare==fl[i].culoare&&fl[j].pret==fl[i].pret&&fl[j].nume==fl[i].nume) ok=1;
        }
        
        
        k++; //scris aici pentru ca indentez doar dupa
    }
    
//    if(ok) std::cout<<"Exista cel putin 2 valori identice in vector"<<'\n';
//    else std::cout<<"Nu exista valori identice perfect in vector!"<<'\n';
}

void mxculoare(std::vector<Floare>fl)
{
    /*
     parcurg toate valorile
     parcurg vectorul secundar
     daca gasesc culoare in vec secundar cresc ct
     */
    
    struct culoare{
        int ct;
        std::string culoare;
    };
    
    
    
    std::vector<culoare> mxvec;
    
    int k=0;
    culoare mx;
    mxvec.resize(fl.size());
    for(int i=0;i<fl.size();i++)
    {
        if(k==0) { /*std::cout<<fl[i].culoare<<" "<<1;*/
            mxvec[k].culoare=fl[i].culoare;mxvec[i].ct=1;}
        else
        for(int j=0;j<k;j++){
            if(fl[i].culoare==mxvec[j].culoare) mxvec[j].ct++;
            else
            { culoare tmp;
                tmp.ct=1;
                tmp.culoare=fl[i].culoare;
                mxvec[k]=tmp;}}
            k++;
        
    }
    
    for(int i=0;i<k;i++) std::cout<<mxvec[i].culoare<<" "<<mxvec[i].ct<<'\n';
    
}

void afisare(std::vector<Floare>fl)
{
    for(const auto& el:fl)
        std::cout<<el.nume<<" "<<el.culoare<<" "<<el.pret<<'\n';
}

int main()
{
    std::vector<Floare> fl;
    citire(fl);
    mxculoare(fl);
//    afisare(fl);
}
