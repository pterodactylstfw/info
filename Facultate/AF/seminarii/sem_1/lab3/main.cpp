#include <iostream>
using namespace std;

int gauss(int n)
{
    
    return (n*(n+1))/2;
}

void ex3(int n)
{
    int sum=gauss(n);
    
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        sum-=x;
        
    }
    cout<<"Numarul care nu a fost citit este "<<sum<<'\n';
}


void ex4(int n)
{
    /*
     missing = double *factorial/produs
     missing-double=Sg-S
     */
    
    
    
}

int main()
{
    int n;
    cin>>n;
//    ex3(n);
    
    
}
