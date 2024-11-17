
#include <stdio.h>
#include <stdlib.h>

void citire(int ***a, int *m, int *n) {
    printf("Dati dimensiunile matricei: ");
    scanf("%d%d", m, n);

    
    *a = (int**)calloc(*m, sizeof(int*));
    if (*a == NULL) {
        printf("Memorie insuficienta!");
        exit(1);
    }

    
    for (int i = 0; i < *m; i++) {
        (*a)[i] = (int*)calloc(*n, sizeof(int));
        if ((*a)[i] == NULL) {
            printf("Memorie insuficienta!");
            exit(1);
        }
    }

    
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            scanf("%d", &(*a)[i][j]);
        }
    }
}


int **create_submatrix(int **a, int m, int n) {
    int m_nou = m - 1;
    int n_nou = n - 1;
    
    
    int **sbm = (int**)calloc(m_nou, sizeof(int*));
    if (sbm == NULL) {
        printf("Memorie insuficienta!");
        exit(1);
    }

    for (int i = 0; i < m_nou; i++) {
        sbm[i] = (int*)calloc(n_nou, sizeof(int));
        if (sbm[i] == NULL) {
            printf("Memorie insuficienta!");
            exit(1);
        }
    }

    
    for (int i = 0; i < m_nou; i++) {
        for (int j = 0; j < n_nou; j++) {
            sbm[i][j] = a[i + 1][j + 1];
        }
    }

    return sbm;
}

void afisare(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
            for (int j = 0; j < n; j++)
            {
                    printf("%d ", a[i][j]);
            }

            printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    int **a;
    int m, n;

    citire(&a, &m, &n);
    
    afisare(a, m, n);
    printf("\n");
    printf("\n");
    int **submatrix = create_submatrix(a, m, n);
    printf("\n");
    printf("\n");
    afisare(submatrix, m-1, n-1);
    for (int i = 0; i < m; i++)
            free(a[i]);

    free(a);
    return 0;
}


/*
 4 5
 1 2 3 4 5
 6 7 8 9 10
 11 12 13 14 15
 16 17 18 19 20
 */
