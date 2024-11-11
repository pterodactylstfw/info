// QuickSort algoritmus

#include <iostream>
#include "cautari.h"
#include "cautare2.h"
#include <fstream>
bool comparator_cresc(int a, int b)
{
    return a<=b;
}

bool comparator_descresc(int a, int b)
{
    return a>=b;
}

int partitionare(std::vector<int> &vect, int st, int dr, bool comparator(int, int))
{
    int pivot = vect[dr];
    int i = st-1;
    for(int j=st;j<dr;j++)
    {
        if(comparator(vect[j],pivot)) //vect[j]<=pivot standard, dar acum folosim comparator
        {
            i++;
            std::swap(vect[i],vect[j]);
        }
    }
    std::swap(vect[dr],vect[i+1]);
    
    return i+1;
}

void quicksort(std::vector<int> &vect, int st, int dr, bool comparator(int, int))
{
    if(st<dr)
    {
        int poz_pivot = partitionare(vect, st, dr,comparator);
        quicksort(vect, st, poz_pivot-1, comparator);
        quicksort(vect, poz_pivot+1, dr,comparator);
    }
}

std::vector <int> citire()
{
    
        int dim;
        std::cin>>dim;
        std::vector<int> vect(dim);
        for(int i=0;i<vect.size();i++)
            std::cin>>vect[i];
    
    return vect;
}

void afisare(std::vector<int> vect)
{
    for(const auto & elem:vect)
        std::cout<<elem<<" ";
}

struct data
{
    int zi, luna, an;
};

std::vector<data> citire_fisier(std::string cale_fisier)
{
    std::vector<data> date_calendaristice;
    int zi, luna, an;
    std::ifstream fin(cale_fisier);
    while(fin>>zi>>luna>>an)
    {
        date_calendaristice.push_back({zi, luna, an});
    }
    return date_calendaristice;
}

void afisare2(std::vector<data> vect)
{
    for( auto d: vect)
        std::cout<<d.zi<<" "<<d.luna<<" "<<d.an<<'\n';
}

int main()
{
    //    std::vector<int> vect = citire();
    //    afisare(vect);
    //    std::cout<<'\n';
    //    quicksort(vect, 0, vect.size()/2, comparator_cresc);
    //    quicksort(vect, vect.size()/2+1, vect.size()-1, comparator_descresc);
    //    afisare(vect);
    std::vector<data> vect = citire_fisier("date_calendaristice.txt");
    afisare2(vect);
    
}

// de revizuit functii template

// de modificat QS in tip de data data pt struct (problema cu date_calendaristice fisier)
