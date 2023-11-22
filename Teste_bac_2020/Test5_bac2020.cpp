// test antrenament 5 bac 2020 info 
//Rezolvari pseudocod/sub 1 pe caiet

//Sub I

1. a)
2. b)
3. facut
4. b)
5. a)



//Sub II

1. a) D10
    b) 2,3,5,6,7,8
    c) lene
    d) daca e patrat perfect


//Sub III

1.int baza(int n)
{
    int b=0;
    if(n==0) return 0;
    else
        while(n!=0)
        { if(n%10>b) b=n%10+1;
            n/=10;
        }
    return b;
    
}

2.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[256];
    cin.getline(s,255);
    int ct=0;
    char *p=strtok(s," ");
    while(p!=NULL)
    {
        if(strchr(p,',')==NULL&&isdigit(p[0])) ct++;
        p=strtok(NULL, " ");
    }
    cout<<ct;  
}

3.
int main()
{
    int x,s,smax;
    s=smax=0;
    f>>x;
    s=smax=x;
    while(f>>x)
    {
        if(s>0)
           s=s+x;
        else
           s=x;
        if(s>smax)
           smax=s;
    }
    cout<<smax;
}
