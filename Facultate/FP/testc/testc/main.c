#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 NU AM MAI PUS MESAJE PENTRU FUNCTII, DEOARECE DIN RETURN-UL ACESTORA SE INTELEGE RASPUNSUL. IN CAZUL IN CARE SUNT NECESARE MESAJELE, VOI ADAUGA.
 */

int rasturnat(int n)
{
    int og=0,x=n;
    while(x)
    {
        og=og*10+x%10;
        x/=10;
    }
    
    return og;
}


int prim(int x, int d)
{
    if((x!=2&&x%2==0)||x<2) return 0;
    if(d*d>x) return 1;
    if(x%d==0) return 0;
    return prim(x,d+2);
}

int patrat_perfect(int n,int x)
{
     
    while(x*x<=n)
    {
        if(x*x==n) return 1;
        else return patrat_perfect(n,x+1);
    }
    return 0;
}
int cifraControl(int n)
{
    int cifraDeControl;
    if(n % 9 == 0) {
        cifraDeControl = 9;
    } else {
        cifraDeControl = n % 9;
    }
    return cifraDeControl;
}

int palindrom(int n)
{
    int og=rasturnat(n);
    return og==n;
}

int dif_sutezeci(int n)
{
    return n/100%10-n/10%10;
}

int gauss(int n)
{
    return (n*(n+1))/2;
}

int suma(int n, int *a)
{
    int suma=0;
    for(int i=0;i<n;i++)
        suma+=a[i];
    return suma;
}
int produs(int n, int *a)
{
    {
        int produs=1;
        for(int i=0;i<n;i++)
            produs*=a[i];
        return produs;
    }
}

int armstrong(int n)
{
    int sumaArm=0;
    int x=n;
    while(x)
    {
        int c=x%10;
        sumaArm+=c*c*c;
        x/=10;
    }
    return sumaArm==n;
}

float dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

float media_ponderata(int n, int *note, float *p)
{
    float suma=0, total=0;
    for(int i=0;i<n;i++)
    {suma+=note[i]*p[i];
        total+=p[i];}
    return suma/total;
}

void polinom(int n)
{
    int pln=0,x,a;
    for(int i=0;i<n;i++)
    {scanf("%d %d", &x,&a );
        pln+=x*a;}
    printf("%d", pln);
    printf("\n");
        
}

int sumadiv(int n)
{
    int suma=0;
    for(int d=1;d<n;d++)
        if(n%d==0) suma+=d;
    return suma;
}

int perfect(int n)
{
    int sd=sumadiv(n);
    return n==sd;
}

int deficient(int n)
{
    return n>sumadiv(n);
}

int abundent(int n)
{
    return n<sumadiv(n);
}

int genFibo(int n)
{
    int f1=0,f2=1,f3=0;
    int i=1;
    while(i<n)
    {
        f3=f1+f2;
        f1=f2;
        f2=f3;
        i++;
    }
    return f3;
}

void convertIntegerPart(int n, int base) {
    char result[32];
    int index = 0;

    
    while (n > 0) {
        int remainder = n % base;
        result[index++] = (remainder > 9) ? (remainder - 10) + 'A' : remainder + '0';
        n /= base;
    }

    
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
}


void convertFractionalPart(double fraction, int base) {
    printf(".");
    for (int i = 0; i < 6; i++) {
        fraction *= base;
        int integerPart = (int)fraction;
        printf("%c", (integerPart > 9) ? (integerPart - 10) + 'A' : integerPart + '0');
        fraction -= integerPart;
    }
}


void rnd(void){
    srand(time(NULL));
    int x= rand() %100;
    x++;
    
    int nr;
    do {
        
        scanf("%d", &nr);
        if(nr>x) printf("Mai mic!");
        else if(nr<x) printf ("Mai mare!");
        printf("\n");
    } while (nr!=x);
    printf("Ai ghicit numarul!");
}

struct Persoana {
    char nume[50];
    int varsta;
    float salariu;
};


void afisareMedie(struct Persoana persoane[], int nrPersoane) {
    float sumaVarsta = 0, sumaSalariu = 0;

    for (int i = 0; i < nrPersoane; i++) {
        sumaVarsta += persoane[i].varsta;
        sumaSalariu += persoane[i].salariu;
    }

    printf("| Medie%42s| %4.2f| %7.2f|\n", "", sumaVarsta / nrPersoane, sumaSalariu / nrPersoane);
}


void afisarePersoane(struct Persoana persoane[], int nrPersoane) {
    printf("---------------------------------------------------------------\n");
    printf("|Nr. | NUMELE SI PRENUMELE                  |Varsta|Salariu|\n");
    printf("|crt.|                                     |      |       |\n");
    printf("|----+-------------------------------------+------+-------|\n");

    for (int i = 0; i < nrPersoane; i++) {
        printf("|%2d  |%-37s| %4d | %7.2f|\n", i + 1, persoane[i].nume, persoane[i].varsta, persoane[i].salariu);
    }

    printf("|------------------------------------------+------+-------|\n");
    afisareMedie(persoane, nrPersoane);
    printf("---------------------------------------------------------------\n");
}





void tabel(void)
{
    struct Persoana persoane[10] = {
//        {"Ionescu_Monica", 19, 520.17},
//        {"Aionesei_Adrian_Ionel", 23, 884.25},
//        {"Popescu_Gigel", 19, 443.10},
//        {"Popescu_Maria", 28, 1155.00}
    };
    printf("Cate persoane vor fi in tabel? ");
    int x;
    scanf("%d",&x);
    
    getchar();
    for(int i=0;i<x;i++)
    {
        printf("Nume si prenume pentru persoana %d\n", i + 1);
        fgets(persoane[i].nume, 50, stdin);
        persoane[i].nume[strcspn(persoane[i].nume, "\n")] = 0;
        printf("Varsta pentru persoana %d\n", i + 1);
        scanf("%d",&persoane[i].varsta);
        printf("Salariu pentru persoana %d\n", i + 1);
        scanf("%f",&persoane[i].salariu);
        getchar();

    }
    afisarePersoane(persoane, x);
    
}


int main(int argc, char *argv[]){
 int n;
 scanf("%d",&n);
 printf("%d",rasturnat(n));
    
 printf("\n");
    
 printf("%d",prim(n,3));
    
 printf("\n");
    
 printf("%d",patrat_perfect(n,1));
    
 printf("\n");
    
 printf("%d", cifraControl(n));
    
 printf("\n");
    
 printf("%d",palindrom(n));
    
 printf("\n");
    
 printf("%d", dif_sutezeci(n));
    
 printf("\n");
    
 printf("%d",gauss(n));
    
 printf("\n");
 
 int a[10];
 for(int i=0;i<n;i++)
     scanf("%d",&a[i]);
    
 printf("\n");
    
 printf("%d", suma(n, a));
    
 printf("\n");
    
 printf("%d",produs(n, a));
    
 printf("\n");
    
 printf("%d",armstrong(n));
    
 printf("\n");
    
 int x1,y1,x2,y2;
 scanf("%d %d %d %d", &x1, &y1, &x2,&y2);
    
 printf("\n");
    
 printf("%f", dist(x1, y1, x2, y2));
    
 printf("\n");
    
 int note[10];
 float p[10];
 for(int i=0;i<n;i++)
     scanf("%f %d", &p[i],&note[i]);
 printf("%f", media_ponderata(n, note, p));
    
 printf("\n");
    
 polinom(n);
    
 printf("\n");
    
 printf("%d", perfect(n));
    
 printf("\n");
    
 printf("%d", deficient(n));
    
 printf("\n");
    
 printf("%d", abundent(n));
    
 printf("\n");
    
 printf("%d", genFibo(n));
    
 printf("\n");
    
 int b;
 scanf("%d", &b);
 printf("\n");
    
 rnd();
    
 printf("\n");
    
 float x,frac;
 int intr;
 scanf("%f",&x);
 intr=(int)x;
 frac=x-intr;
 printf("Introdu baza in care ai citit numarul zecimal: ");
 int baza;
 scanf("%d",&baza);
    
 printf("\n");
    
 printf("Numarul tau zecimal, transformat in baza b este de forma: ");
 convertIntegerPart(intr, b);
 convertFractionalPart(frac, b);
    
 printf("\n");
 tabel();
    
    return 0;
    
    
}



