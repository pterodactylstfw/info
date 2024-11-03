

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int n, *ptr;

    // nr. de octeti pe care il ocupa int in memorie
    //sizeof(int);
    // nr. de octeti pe care il ocupa un pointer catre int in memorie
    //sizeof(int*);

    // & - operator de referentiere
    // %d - variabila de tip int
    scanf("%d", &n);
    printf("%d\n", n);

    // %p - pt afisarea adresei de memorie
    printf("%p\n\n", &n);

    ptr = &n;
    printf("%p\n", ptr);
    printf("%p\n", &ptr);

    // * - operator de dereferentiere
    // se aplica asupra unui pointer si intoarce valoarea de la adresa pe care pointer-ul o retine - adica n
    printf("%d\n\n", *ptr);

    n++;
    printf("%d\n", n);
    printf("%d\n", *ptr);

    (*ptr)++;
    printf("%d\n", n);
    printf("%d\n\n", *ptr);

    printf("%zu\n", sizeof(int));
    printf("%zu\n\n", sizeof(int*));



    return 0;
}
