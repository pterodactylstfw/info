//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct
//{
//        char* nume;
//        int varsta;
//
//} Persoana;
//
//
//void citire_persoana(Persoana* p, FILE* fis)
//{
//        p->nume = (char*)calloc(100, sizeof(char));
//        if (!p->nume)
//        {
//                printf("Memorie insuficienta!");
//                exit(1);
//        }
//
//        if (fscanf(fis, "%s %d", p->nume, &p->varsta) != 2)
//        {
//                printf("Citirea a esuat!");
//                exit(1);
//        }
//}
//
//void afisare_persoana(Persoana p, FILE* fis)
//{
//        if (p.varsta < 20)
//                fprintf(fis, "%s are %d ani\n", p.nume, p.varsta);
//        else
//                fprintf(fis, "%s are %d de ani\n", p.nume, p.varsta);
//}
//
//int alocare_vector(Persoana** pers, int nrPers)
//{
//        *pers = (Persoana*)calloc(nrPers, sizeof(Persoana));
//        return *pers != NULL;
//}
//
//void dealocare_vector(Persoana* pers, int nrPers)
//{
//        for (int i = 0; i < nrPers; free((pers + i)->nume), ++i);
//        free(pers);
//}
//
//void citire_vector(Persoana** pers, int* nrPers)
//{
//        FILE* fis = fopen("persoane.txt", "r");
//        if (!fis)
//        {
//                printf("Nu s-a putut deschide fisierul!");
//                exit(1);
//        }
//
//        if (fscanf(fis, "%d", nrPers) != 1)
//        {
//                printf("Citirea a esuat!");
//                exit(1);
//        }
//
//        if (!alocare_vector(pers, *nrPers))
//        {
//                printf("Memorie insuficienta!");
//                fclose(fis);
//                exit(1);
//        }
//
//        for (int i = 0; i < *nrPers; ++i)
//                citire_persoana(&(*pers)[i], fis);
//
//        fclose(fis);
//}
//
//void afisare_vector(Persoana* pers, int nrPers)
//{
//        FILE* fis = fopen("persoane_sortate.txt", "w");
//        if (!fis)
//        {
//                printf("Nu s-a putut deschide fisierul!");
//                exit(1);
//        }
//
//        for (int i = 0; i < nrPers; ++i)
//        {
//                afisare_persoana(pers[i], fis);
//        }
//
//        fclose(fis);
//}
//
//int comparator(const void* a, const void* b)
//{
//        Persoana* p1 = (Persoana*)a;
//    Persoana* p2 = (Persoana*)b;
//                        
//        if (p1->varsta != p2->varsta)
//                return p1->varsta - p2->varsta;
//
//        return strcmp(p1->nume, p2->nume);
//}
//
//void main()
//{
//    int nrPers;
//    Persoana * pers;
//    citire_vector(&pers, &nrPers);
//    
//    qsort(pers, nrPers, sizeof(Persoana), comparator);
//    afisare_vector(pers, nrPers);
//    dealocare_vector(pers, nrPers);
//}
