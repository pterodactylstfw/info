#include <stdio.h>
#include <stdlib.h>
void citire_vector_static(int* dim, int* v)
{
    scanf("%d", dim);
    for (int i = 0; i < *dim; i++)
        scanf("%d", &v[i]);
}

void afisare_vector_static(int dim, int v[])
{
    for (int i = 0; i < dim; i++)
        printf("%d ", v[i]);
}

int main(int argc, char *argv[])
{
    // alocare statica
//    int v[20], dim;
//
//    citire_vector_static(&dim, v);
//    afisare_vector_static(dim, v);

    int *v = NULL, dim;
    scanf("%d", &dim);
    v= (int*)malloc(dim * sizeof(int));
    //malloc pt initializarea elementelor din vector cu valori random de catre program
    //calloc pt initializare cu 0 a elementelor din vector
    // realloc - realoca memorie pt un vector existent
    for(int i=0; i<dim ;i++)
        scanf("%d",&v[i]);
    
    for(int i=0;i<dim;i++) printf("%d ", v[i]);
    
    free(v);
    
    return 0;
}
