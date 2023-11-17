// test antrenament 2 bac 2020 info 
//Rezolvari pseudocod/sub 1 pe caiet

//Sub I

1. d)
2. c)
3. b)
4. b)
5. a)

//Sub II
//1a) pe caiet

1. a) 20950
    b) 20406, 40608, 60402
    c) 
#include <iostream>
using namespace std;
int main()
{
    int n,m,c;
    m=0;
    cin>>n;
    do {
        c=n%10;n/=10;
        if(c==0) c=2;
        else
            if(c%2==0) c=0;
        m=m*10+c;
        
    } while (n!=0);
    cout<<m;
}
    d) cat timp n!=0 ......

2. struct specie
{
    int cod;
    int nrExemplare;
    int varsta[10];
}s[20];

3. for(int i=1;i<=5;i++)
    for(int j=1;j<=7;j++)
    {
        if(i==1) a[i][j]=1;
        else if(j==1) a[i][j]=1;
        else a[i][j]=a[i-1][j]+a[i][j-1];
    }


//Sub III

1.
#include <iostream>
using namespace std;
void fii(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        int j=n/i;
        if(i*j==n&&i!=j) cout<<"("<<j<<" "<<i<<")"<<" ";
    }  
}
int main()
{
    int n;
    cin>>n;
    fii(n);
    return 0;
}

2.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[101],aux[101];
    cin.getline(s,100);
    char*p=strtok(s," ");
    while(p!=NULL)
    {
        
        if(p[0]!='-') strcat(aux,p);
        strcat(aux," ");
        p=strtok(NULL," ");
    }
    
    cout<<aux;
}

3.

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("numere.in");

int main()
{
    int x,mx1=0,mx2=0,mx3=0;
    while(fin>>x)
    {
        if(x%100==20)
        {
            if(x>mx1)
            {
                mx3=mx2;
                mx2=mx1;
                mx1=x;
            }
            else if(x>mx2)
            {
                mx3=mx2;
                mx2=x;
            }
            else
                if(x>mx3) mx3=x;
        }
    }
    cout<<mx3<<" "<<mx2<<" "<<mx1;
}
