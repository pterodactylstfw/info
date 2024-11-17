#include <stdio.h>
#include <stdlib.h>

int matrixAlloc(float*** a, int m, int n)
{
        *a = (float**)calloc(m, sizeof(float*));
        if (*a == NULL)
                return 0;

        for (int i = 0; i < m; i++)
        {
                (*a)[i] = (float*)calloc(n, sizeof(float));
                if ((*a)[i] == NULL)
                {
                        for (int j = 0; j < i; j++)
                                free((*a)[j]);

                        free(*a);
                        return 0;
                }
        }

        return 1;
}

void matrixRead(float*** a, int* m, int* n)
{
        // m - nr. de linii, n - nr. de coloane
        printf("Dati dimensiunile matricei: ");
        scanf("%d%d", m, n);

        int alloc = matrixAlloc(a, *m, *n);
        if (!alloc)
        {
                printf("Memorie insuficienta!");
                exit(1);
        }

        for (int i = 0; i < *m; i++)
                for (int j = 0; j < *n; j++)
                        scanf("%f", &(*a)[i][j]);
}

void matrixPrint(float** a, int m, int n)
{
        printf("Elementele matricei sunt: \n");
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                        printf("%10.2f ", a[i][j]);

                printf("\n");
        }
}

int submatrix(int** a, int n1, int m1, int i1, int j1, int i2, int j2, int*** b, int* m2, int* n2)
{
        // daca avem coordonate invalide, se returneaza 0 ca valoare a functiei
        // ...

        return 1;
}


void main()
{
        int** a, m1, n1;
        // alocare dinamica de memorie pentru matricea 'a'
        // citirea elementelor matricei 'a'
        // ...

        int i1, j1, i2, j2;
        // citire coordonate i1, j1, i2, j2
        // ...

        int** b, m2, n2;
        submatrix(a, m1, n1, i1, j1, i2, j2, &b, &m2, &n2);

        // afisarea elementelor matricei 'b'
        // ...

        // eliberarea zonelor de memorie pentru 'a' si 'b'
        for (int i = 0; i < m1; i++)
                free(a[i]);
        free(a);

        for (int i = 0; i < m2; i++)
                free(b[i]);
        free(b);
}
