#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
std::ifstream fin("date.txt");

struct date {
    int an, luna, ziua;
};

struct carti {
    std::string titlu, autor;
    int an;
};

void ex1()
{   int maxAn=0, maxLuna=0, maxZi=0;
    std::vector<date> vectDate;
    int k=-1, mxk;
    date tmp;
    while(fin>>tmp.ziua>>tmp.luna>>tmp.an)
    { k++;
        if(tmp.an>maxAn) static_cast<void>(maxAn=tmp.an), static_cast<void>(maxZi=tmp.ziua), static_cast<void>(maxLuna = tmp.luna),mxk=k;
        else
            if(tmp.an==maxAn)
            {
                if(tmp.luna>maxLuna) maxLuna=tmp.luna, maxZi=tmp.ziua,mxk=k;
                else
                    if(tmp.luna==maxLuna) maxZi=tmp.ziua,mxk=k;
            }
        vectDate.push_back(tmp);
    }
    
    std::cout<<"Data maxima este: "<<vectDate[mxk].ziua<<" "<<vectDate[mxk].luna<<" "<<vectDate[mxk].an;
}

void ex2() {
    std::vector<carti>vectCarti;
    std::string linie;
        while (getline(fin, linie)) {
            std::stringstream ss(linie);
            std::string titlu, autor, anStr;
            getline(ss, titlu, ';');
            getline(ss, autor, ';');
            getline(ss, anStr, ';');
            
            carti carte = { titlu, autor, stoi(anStr) };
            vectCarti.push_back(carte);
        }
}

int main()
{
    ex1();
    
}
