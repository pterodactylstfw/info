//
//  main.c
//  lab_3
//
//  Created by Raul Constantin on 22.10.2024.
//

#include <stdio.h>
#include <stdbool.h>
int sumimp_iter(int n)
{
    int s=0;
    while(n)
    {
        if(n%2==1) s+=n%10;
        n/=10;
    }
    return s;
}
int sumimp_rec(int n)
{
    if(n==0) return 0;
    if(n%2) return n%10+sumimp_rec(n/10);
    return sumimp_rec(n/10);
}

int rasturnat_iter(int n)
{
    int og=0;
    while(n)
    {
        og=og*10+n%10;
        n/=10;
    }
    return og;
}

int rasturnat_rec(int n, int og)
{
    if(n==0) return og;
    return rasturnat_rec(n/10,og*10+n%10);
}


int fact_iter(int n)
{   int fact=1;
    for(int i=1;i<=n;i++) fact*=i;
    return fact;
}

int fact_rec(int x)
{
    if(x==0) return 1;
    return x*fact_rec(x-1);
}

int cmmdc_iter(int a, int b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int cmmdc_rec(int a, int b)
{
    if(b==0) return a;
    return cmmdc_rec(b, a%b);
}


int caut_vector(int *a, int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(x==a[i]) return i;
    }
    return -1;
}

void bubblesort(int n, int* a)
{
    bool ok;
    do {
        ok=1;
        for(int i = 0 ; i < n - 1 ; i ++)
            if(a[i] > a[i+1])
            {
              int aux = a[i];
              a[i] = a[i+1];
              a[i+1] = aux;
              ok = false;
            }
    } while (!ok);
}

bool prim(int x, int d)
{
    if((x!=2&&x%2==0)||x<2) return 0;
    if(d*d>x) return 1;
    if(x%d==0) return 0;
    return prim(x,d+2);
}

void insert_after_prim(int *n, int *a, int nr) {
    int pos = -1;

    
    for (int i = 0; i < *n; i++) {
        if (prim(a[i],3)) {
            pos = i;
            break;
        }
    }

    
    if (pos == -1) {
        printf("Nu există niciun număr prim în vector.\n");
        return;
    }

    
    (*n)++;

    
    for (int i = *n - 1; i > pos + 1; i--) {
        a[i] = a[i - 1];
    }

    
    a[pos + 1] = nr;
}


int sum_diag_sec(int n, int a[100][100])
{
    int s=0;
    for(int i=0;i<n;i++)
        s+=a[i][n - 1 - i];
    
    return s;
}

int min_elem_col(int n, int a[n][n], int col)
{   int mn=999999;
    for(int i=0;i<n;i++)
        if(a[col-1][i]<mn) mn=a[col-1][i];
    return mn;
}

void rotire_ungdrept(int a[100][100], int n, int m) {
    int temp[100][100];  // Matrice temporară pentru a stoca rezultatul rotației

    // Copiem elementele rotite în matricea temporară
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[j][n - 1 - i] = a[i][j];
        }
    }

    // Copiem matricea temporară în matricea originală
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = temp[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
 int n,m,x;
 //scanf("%d" ,&n);
printf("suma cifrelor impare iterativa: %d \n",sumimp_iter(n));
printf("suma cifrelor impare recursiva: %d \n",sumimp_rec(n));
printf("Rasturnatul iterativ: %d \n",rasturnat_iter(n));
printf("Rasturnatul recursiv: %d \n",rasturnat_rec(n,0));
printf("factorialul lui n iterativ %d \n",fact_iter(n));
printf("factorialul lui n recursiv %d \n",fact_rec(n));
printf("Mai introdu un numar pt cmmdc: ");
scanf("%d" ,&m);
printf("cmmdc iterativ dintre m si n este %d \n",cmmdc_iter(n, m));
printf("cmmdc recursiv dintre m si n este %d \n",cmmdc_rec(n, m));
 printf("Mai introdu numarul de elemente pentru vector: ");
 scanf("%d" ,&x);
printf("\n");
int a[101];
for(int i=0;i<x;i++)
{
   scanf("%d", &a[i]);
}
 int nr;
printf("Numarul cautat de tine este: ");
scanf("%d" ,&nr);
printf("\n");
if(caut_vector(a, x, nr)!=-1) printf("Am gasit elementul la pozitia %d!\n",caut_vector(a, x, nr)+1);
else printf("Elementul nu se afla in vector!\n");
printf("\n");
printf("Sortam vectorul... \n");
printf("\n");
 //bubblesort(x, a);
printf("Vectorul sortat este: ");
for(int i=0;i<x;i++)
{
   printf("%d ",a[i]);
}
printf("\n");
 
insert_after_prim(&x, a, n);

for(int i=0;i<x;i++)
{
   printf("%d ",a[i]);
}
printf("\n");
 
 int mat[15][15];
 for(int i=0;i<x;i++)
     for(int j=0;j<x;j++) scanf("%d", &mat[i][j]);
 
 printf("Suma elementelor de pe diagonala secundara a matricei este: %d \n",sum_diag_sec(x, mat));
 int col;
 scanf("%d",&col);
 printf("%d",col);
 printf("cel mai mic element de pe coloana %d este %d \n", col, min_elem_col(x, mat, col));

    //pt ultima cerinta; rotire la 90 grade.
//    int n,m;
//    scanf("%d %d", &n,&m);
//    int a[100][100];
//    for(int i=0;i<n;i++)
//        for(int j=0;j<m;j++)
//            scanf("%d",&a[i][j]);
//    printf("\n");
//    rotire_ungdrept(a, n, m);
//    for(int i=0;i<n;i++,printf("\n"))
//        for(int j=0;j<m;j++) printf("%d ", a[i][j]);
    return 0;
}
