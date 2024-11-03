#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <climits>
#include <random>
std::ifstream fin("partial.in");

std::vector<std::vector<int>> citire()
{
    std::vector<std::vector<int>> crpt;
    int zile,nr;
    fin>>nr>>zile;
    
    crpt.resize(nr);
    for(int i=0;i<nr;i++)
    {crpt[i].resize(zile);
        for(int j=0;j<zile;j++)
            fin>>crpt[i][j];
    }
    
    return crpt;
    
}

void afisare(std::vector<std::vector<int>>vect)
{
    for(const auto & row: vect)
    {for(const auto& elem:row)
        std::cout<<elem<<" ";
            std::cout<<std::endl;}
}

void profit(std::vector<std::vector<int>>vect)
{
    double mx=-1;
    int index=0;
    for(int i=0;i<vect.size();i++)
    {
        double pf = ((vect[i][vect[i].size() - 1] - vect[i][0]) / double(vect[i][0])) * 100;

            
        std::cout<<pf<<" ";
        if(pf>mx) {mx=pf; index=i;}
        
        
    }
    std::cout<<'\n';
    std::cout<<"Criptomoneda "<<index<<" cu "<<std::fixed << std::setprecision(4)<<mx<<"% profit."<<'\n'<<'\n';
    
}

void pierdere(std::vector<std::vector<int>>vect)
{
    
    for(int i=0;i<vect.size();i++) //criptomoneda curenta
    {
        int mx=0,index=0;
        for(int j=0;j<vect[i].size()-1;j++)
        {
            if(vect[i][j]-vect[i][j+1]>mx) {mx=vect[i][j]-vect[i][j+1];
                index=j;}
            
            
            
        }
        
        std::cout<<"de la ziua cu indexul "<<index<<" la ziua cu indexul "<<index+1<<" am fi avut pierderea de "<<mx<<" bani"<<'\n';
    }
}

/*
    criptomoneda 1 - id
                   - diferenta
 
 */
struct diff {
    int cr_ind;
    int dif;
};
void QuickSort(std::vector<diff>&v, int st, int dr)
{
    if(st < dr)
    {
        //pivotul este inițial v[st]
        int m = (st + dr) / 2;
        diff aux = v[st];
        v[st] = v[m];
        v[m] = aux;
        int i = st , j = dr, d = 0;
        while(i < j)
        {
            if(v[i].dif > v[j].dif)
            {
                std::swap(v[i],v[j]);
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(v, st , i - 1);
        QuickSort(v, i + 1 , dr);
    }
}

void sortare(std::vector<std::vector<int>>vect)
{
   
    std::vector<diff> diferenta;
    for(int i=0;i<vect.size();i++)
    {
        int cresc,desc;
        cresc=desc=0;
        for(int j=0;j<vect[i].size()-1;j++)
        {
            int dif=vect[i][j]-vect[i][j+1];
            if(dif>0) cresc++;
            else if(dif<0) desc++;
            
        }
        diff tmp;
        tmp.cr_ind=i;
        tmp.dif=cresc-desc;
        diferenta.push_back(tmp);
        
    }
//    for(int i=0;i<diferenta.size();i++)
//        std::cout<<"ID_Cr "<<diferenta[i].cr_ind<<" "<<"dif "<<diferenta[i].dif<<"\n";
    
    std::cout<<'\n'<<'\n';
    QuickSort(diferenta, 0, diferenta.size()-1);
//    
//    for(int i=0;i<diferenta.size();i++)
//        std::cout<<"ID_Cr "<<diferenta[i].cr_ind<<" "<<"dif "<<diferenta[i].dif<<"\n";
    
 for(int i=0;i<diferenta.size();i++)
     std::swap(vect[i],vect[diferenta[i].cr_ind]);
 std::cout<<'\n'<<'\n';
 afisare(vect);
    
}


/*
 subpunct d)
 
 1. calculam fluctuatia (max-min)
 
 2.
 
 generam random in intervalul [min-fluc, max]
 
 3. verificam fluc<min && fluc>max
 
 4. recalculam fluctuatia
 
 
 facem de 3 ori
 
 int range = max - min + 1;
 int num = rand() % range + min;
 
 */


void random(std::vector<std::vector<int>>vect)
{
    struct fluct {
        int mn,mx,flu;
    };
    std::vector<fluct>fluc;
    for(int i = 0; i < vect.size(); i++)
        {
            int mn = INT_MAX, mx = INT_MIN;

            // Calculăm minimul și maximul pentru întreaga linie
            for(int j = 0; j < vect[i].size(); j++)
            {
                if(vect[i][j] < mn) mn = vect[i][j];
                if(vect[i][j] > mx) mx = vect[i][j];
            }

            int flu = mx - mn;

            // Acum generăm valori pentru cele 3 zile suplimentare
            for(int k = 0; k < 3; k++)
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distrib(mn - flu, mx);
                int randomVal = distrib(gen);
                vect[i].push_back(randomVal);
            }
        }
    std::cout<<'\n'<<'\n'<<'\n';
    afisare(vect);
    
}





int main()
{
    std::vector<std::vector<int>>crpt=citire();
    afisare(crpt);
    profit(crpt);
    pierdere(crpt);
    sortare(crpt);
    random(crpt);
}
