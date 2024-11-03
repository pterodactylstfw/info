#include <iostream>
#include <vector>
#include <cstdlib>
void citire(std::vector<int> &vect1, std::vector<int> &vect2)
{
    int n,m;
    std::cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x;
        vect1.push_back(x);
    }
    
    for(int i=0;i<m;i++)
    {
        int x;
        std::cin>>x;
        vect2.push_back(x);
    }
    
}

std::vector<int> interclasare(std::vector<int> vect1, std::vector<int> vect2)
{
    std::vector<int>vectfull;
    
    
    int i=0,j=0;
    
    while(i<vect1.size()&&j<vect2.size())
    {
        if(vect1[i]<vect2[j])
        {
            vectfull.push_back(vect1.at(i++));
        }
        else if(vect1[i]>vect2[j])
        {
            vectfull.push_back(vect2.at(j++));
        }
        else
        {
            vectfull.push_back(vect1.at(i++));
            vectfull.push_back(vect1.at(j++));
        }
    }
    
    while(i<vect1.size())
    {
        vectfull.push_back(vect1.at(i++));
    }
    while(j<vect2.size())
    {
        vectfull.push_back(vect2.at(j++));
    }
    
    return vectfull;
}


void afisare(std::vector<int> vect)
{
    for(auto elem:vect)
        std::cout<<elem<<" ";
}

std::vector<int> citire2()
{
    std::vector<int> vect;
    int dim,elem;
    std::cin>>dim;
    for(int i=0;i<dim;i++)
    {
        std::cin>>elem;
        vect.push_back(elem);
    }
    return vect;
}

std::vector <int> inmultire(std::vector<int>& numar)
{
    srand((unsigned) time(NULL));
    std::vector<int> rezultat;
    rezultat.resize(numar.size()+1);
        // Get a random number
    int inmultitor;
    do {
        inmultitor = rand()%9+1;
    } while (inmultitor==0);
    
    int transport=0;
    for(int i=numar.size()-1;i>=0;i--)
    {
        rezultat[i]=(inmultitor*numar[i]+transport)%10;
        transport=(inmultitor*numar[i])/10;
    }
    if(transport)
        rezultat.insert(rezultat.begin(), transport);
    
    return rezultat;
}


int main()
{       // pt ex 6
//    std::vector<int> vect1, vect2,vectfull;
//    citire(vect1,vect2);
//    vectfull=interclasare(vect1, vect2);
//    afisare(vectfull);
    
        // pt ex 8
    std::vector <int> vect = citire2();
    std::vector<int> rezultat=inmultire(vect);
    afisare(rezultat);
    return 0;
}
