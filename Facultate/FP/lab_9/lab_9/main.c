//
//  main.c
//  lab_9
//
//  Created by Raul Constantin on 26.11.2024.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct Persoana {
//    char * nume;
//    int varsta;
//};
//
//typedef struct Persoana Persoana;

typedef struct {
    char * nume;
    int varsta;
}Persoana;


void citire_persoana(Persoana *p)
{
    char * nume = (char*) calloc(100, sizeof(char));
    if(!nume) {
        printf("Memorie insuficienta!");
        exit(1);
    }
    fgets(nume, 100, stdin);
    nume[strlen(nume)-1]='\0';
    
    int varsta;
    scanf("%d", &varsta);
    getchar();
//    (*p).nume;
    p->nume = nume;// echivalent cu strcpy((*p).nume, nume);
    p->varsta = varsta;
    
    /*
     op -> face dereferentiere (*)
     apoi foloseste . pentru a accesa campul dorit
     */
    
}

//int comp( Persoana *p1, Persoana *p2)
//{
//    if(p1->varsta!=p2->varsta)
//    return p1->varsta - p2->varsta;
//    
//    return strcmp(p1->nume, p2->nume);
//}
int comp(const void *a, const void *b)
{
    Persoana *p1 = (Persoana *)a;
    Persoana *p2 = (Persoana *)b;

    if (p1->varsta != p2->varsta)
        return p1->varsta - p2->varsta;

    return strcmp(p1->nume, p2->nume);
}


void afisare_persoana(Persoana p)
{
    printf("%s are %d ani\n", p.nume, p.varsta);
}


int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    getchar();
    Persoana *p = NULL;
    
    p = (Persoana*)calloc(n, sizeof(Persoana));
    if(!p)
    {
        printf("Memorie insuficienta.");
        exit(1);
    }
    for(int index = 0; index <n; ++index){
        citire_persoana(&p[index]);
        }
    
    qsort(p, n, sizeof(Persoana), comp);
    
    for(int index = 0; index <n; ++index){
        afisare_persoana(p[index]);
    }
    for(int index = 0; index <n; ++index){
        free(p[index].nume); }//am alocat char dinamic !!
    
    free(p);
    
    return 0;
}
