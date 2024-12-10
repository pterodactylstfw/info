#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Obiect  {
    int valoare,greutate;
};

bool comp(Obiect a, Obiect b)
{
    return (a.valoare/a.greutate)>(b.valoare/b.greutate);
}

void rucsac_discret(vector<Obiect> obj, int G)
{
    sort(obj.begin(),obj.end(),comp);
    int pfmax=0;
    vector<Obiect> sol;
    int index = 0;
    
    while(index < obj.size() && G>0)
    {
        if(obj[index].greutate<=G) // ob intra in rucsac
        {
            sol.push_back(obj[index]);
            G-= obj[index].greutate;
            pfmax += obj[index].valoare;
        }
        index++;
    }
    
    cout<<pfmax<<" este profitul maxim"<<'\n';
    cout<<" iar obiectele transportate sunt: "<<'\n';
    cout<<'\t';
    for(auto elem:sol)
    {
        cout<< elem.valoare<<" cu greutatea "<<elem.greutate<<" ";
    }
}

int main()
{
    vector<Obiect> obj= {{100,1},{50,10},{150,3},{60,4},{200,10},{300,6}};
    int g;
    cin>>g;
    rucsac(obj, g);
}
