////
////  main.c
////  lab_6
////
////  Created by Raul Constantin on 05.11.2024.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//void citire(int **vect,int* dim)
//{
//    scanf("%d",dim);
//    
//    *vect=(int*)calloc(*dim, sizeof(int));
////    for(int i = 0;i<*dim;i++)
////        scanf("%d", *vect+i );
//    
//    if(*vect == NULL)
//    {
//        printf("Memorie insuficienta!");
//        exit(1);
//    }
//    for(int i=0;i<*dim;i++)
//        scanf("%d", &(*vect)[i]);
//    
//}
//
//
//int main(int argc, const char * argv[]) {
//    int* vect =NULL, dim;
//    
//    citire(&vect, &dim);
//}


#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[])
{
        int** a, m, n;

        printf("Dati dimensiunile matricei: ");
        scanf("%d%d", &m, &n);

        a = (int**)calloc(m, sizeof(int*));
        if (a == NULL)
        {
                printf("Memorie insuficienta!");
                exit(1);
        }
        for (int i = 0; i < m; i++)
        {
            a[i] = (float*)calloc(n, sizeof(float));
                if (a[i] == NULL)
                {
                        printf("Memorie insuficienta!");
                        exit(1);
                }
        }

        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        scanf("%d", &a[i][j]);
                }
        }


        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        printf("%d ", a[i][j]);
                }

                printf("\n");
        }

        for (int i = 0; i < m; i++)
                free(a[i]);

        free(a);
    
    return 0;
}
