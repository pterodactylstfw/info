#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>


using namespace std;

ifstream fin("angajati.in");

ofstream fout("cautare.out");

struct Angajat{
    string nume;
    int varsta;
    float salariu;
    bool salModif=0;
};

bool prim(int x, int d=3)
{
    if((x!=2&&x%2==0) ||x<2) return 0;
    if(d*d>x) return 1;
    if(x%d==0) return 0;
    return prim(x,d+2);
}


vector<Angajat> citire() {
    Angajat ang;
    vector<Angajat> angajati;
    int dim;
    fin>>dim;
    fin.ignore();
    angajati.resize(dim);
    
    for(int i=0;i<dim;i++)
    {
        fin>>ang.nume>>ang.varsta>>ang.salariu;
        angajati.push_back(ang);
    }
    
    return angajati;
}

void afisare(std::vector<Angajat> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i].nume << " "<<v[i].varsta<<" "<<v[i].salariu<<'\n';
    }
    std::cout << '\n';
}

void modificareSalariu(vector<Angajat> & ang)
{
    for(int i=0;i<ang.size();i++)
    {
        if(prim(ang[i].varsta)==1)
        {ang[i].salariu = ang[i].salariu + ((30*ang[i].salariu)/100);
            ang[i].salModif=true;}
        
    }
}

bool ComparatorAngajat(Angajat x, Angajat y)
{
    if(x.salariu==y.salariu)
        return x.varsta<y.varsta; //ordine crescatoare dupa varsta
    
    return x.salariu>y.salariu; //ordine descrescatoare dupa salariu
}

bool ComparatorSalariu(Angajat x, Angajat y)
{
    return x.salariu<y.salariu;
}

int partitionare(std::vector<Angajat>& v, int st, int dr, bool Comparator(Angajat, Angajat)) {
    int i = st - 1;
    Angajat pivot = v[dr];
    for (int j = st; j < dr; j++) {
        if (Comparator(v[j], pivot)) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    i++;
    std::swap(v[i], v[dr]);
    return i;
}

void quicksort(std::vector<Angajat>& v, int st, int dr, bool Comparator(Angajat, Angajat)) {
    if (st < dr) {
        int m = partitionare(v, st, dr,Comparator);
        quicksort(v, st, m - 1, Comparator);
        quicksort(v, m + 1, dr, Comparator);
    }
}

void sortareSalFinal(vector<Angajat>ang)
{
    vector<Angajat> ang_salModif;
    for(int i=0;i<ang.size();i++)
    {
        if(ang[i].salModif==1) ang_salModif.push_back(ang[i]);
    }
    
    quicksort(ang_salModif, 0, ang_salModif.size()-1, ComparatorAngajat);
    
    
}

int cautAngajat( std::vector<Angajat>& ang, int st, int dr, float x, float dif_min=INT_MAX)
{
    quicksort(ang, 0, ang.size()-1, ComparatorSalariu);
    
    if (st > dr) return dif_min;
    if (st == dr) {
        if (ang[st].salariu == x) { dif_min=0;
            return dif_min;}
        else if(x>ang[st].salariu)
            return x-ang[st].salariu;
    }

    int mij = (st + dr) / 2;
    if (ang[mij].salariu == x) { dif_min=0;
        return dif_min;}
    else if (ang[mij].salariu < x) return cautAngajat(ang, mij + 1, dr, x,min(dif_min,x-ang[mij].salariu));
    else return cautAngajat(ang, st, mij - 1, x,dif_min);
}

void afisareAngajatiPragMaxim(vector<Angajat> ang, float difMax, float x)
{
    for(int i=0;i<ang.size();i++)
        if(int(ang[i].salariu)-int(x)==difMax)
        {
            fout<<ang[i].nume<<" "<<ang[i].varsta<<" "<<ang[i].salariu;
            fout<<'\n';
        }
}


int main()
{
    vector<Angajat> ang = citire();
    modificareSalariu(ang);
    sortareSalFinal(ang);
    
    float prag;
    cout<<"Introduceti prag maxim: ";
    cin>> prag;
    
    afisareAngajatiPragMaxim(ang, cautAngajat(ang, 0, ang.size()-1, prag),prag);
    
    
}

