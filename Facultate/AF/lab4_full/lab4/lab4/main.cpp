//                              ALOCAREA DINAMICA A MEMORIEI
#include <iostream>
#include <vector>


void citire_vector_static(int &dim, int vect[100])
{
    std::cin>>dim;
    for(int i=0;i< dim; i++)
        std::cin>>vect[i];
}

void afisare_vect_static(int dim, int vect[100])
{
    for(int i=0;i<dim;i++)
        std::cout<<vect[i]<<" ";
    std::cout<<'\n';
}

int * citire_vector_dinamic(int &dim)
{
    std::cin>> dim;
    int * vect= new int[dim];
    for(int i=0;i< dim; i++)
        std::cin>>vect[i];
    return vect;
    
}

void afisare_vect_dinamic(int dim ,int *vect)
{
    for(int i=0;i<dim;i++)
        std::cout<<vect[i]<<" ";
    std::cout<<'\n';
    
    
}

//Se citește un număr natural n și cele n cele n elemente ale unui vector. Să se insereze în vector între oricare două valori vecine suma și produsul acestora.
//Obs: Determinarea sumei și a produsului a două numere se va realiza în cadrul unui singure funcții.
void inserare_statica(int dim, int v[100])
{
    for(int i=dim-1 ; i>0; i--)
    {
        int s= v[i]+v[i-1];
        int p=v[i]*v[i-1];
        v[3*i]= v[i];
        v[3*i-1]= p;
        v[3*i-2] = s;
    }
    dim=3*dim-2;
}




void citire_dinam(int &dim, std::vector <int> &v)
{
    std::cin>>dim;
    for(int i=0;i<dim;i++){
        int x; std::cin>>x;
        v.push_back(x);}
}

void afis_dinam(int dim, std::vector <int> v)
{
    for(auto i:v)
        std::cout<<i<<" ";
    std::cout<<'\n';
}

void sum_prod(int x, int y, int &s, int &p)
{
    s=x+y;
    p=x*y;
}

void inserare_dinam(std::vector <int> &v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        int s, p;
        sum_prod(v[i], v[i+1], s, p);
        v.insert(v.begin()+i+1,s);
        v.insert(v.begin()+i+2, p);
        i+=2;
    }
}

void inserare_dinam2(int &dim, int * &v)
{
    int *vect = new int[3*dim-2];
    vect[0]=v[0];
    
    for(int i=0;i<dim; i++)
    {
        int s= vect[i]+vect[i-1];
        int p=vect[i]*vect[i-1];
        vect[3*i]= vect[i];
        vect[3*i-1]= p;
        vect[3*i-2] = s;
    }
    dim = dim*3 - 2;
    delete[] v;
    v=vect;
}

/*
 3
 1 2 3
 1 3 2 2 5 6 3
 0 1 2 3 4 5 6 7
 
 4
 2 3 5 7
 2 5 6 3 8 15 5 12 35 7
 0 1 2 3 4 5  6 7  8  9
 
 */


void inserare_stat(int dim, int &v)
{
    
}


int main()
{
    //    int vect[100];
    //    int dim;
    //    citire_vector_static(dim, vect);
    //    afisare_vector_static(dim, vect);
    //
    //    int * v = citire_vector_dinamic(dim);
    //    afisare_vect_dinamic(dim, v);
    std::vector <int> v;
    int dim;
    citire_dinam(dim, v);
    inserare_dinam(v);
    afis_dinam(dim, v);
    
    
}
