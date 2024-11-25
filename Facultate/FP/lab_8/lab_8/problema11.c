//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//int main(void) {
//    char *sir = (char*)calloc(256, sizeof(char));
//    fgets(sir, 256, stdin);
//    sir[strlen(sir) - 1] = '\0'; // Eliminăm newline-ul de la sfârșitul șirului
//    
//    char delim[] = "';:<,>.|}{[]() "; // Delimitații
//
//    char *p = strtok(sir, delim);
//    
//    while (p) {
//        bool ok = 1; // Setăm ok la 1 pentru a presupune că e un cuvânt valid
//        for (int i = 0; i < strlen(p); i++) {
//            if (!isalpha(p[i])) { // Dacă găsim un caracter non-alfabetic
//                ok = 0; // Setăm ok la 0 și ieșim din loop
//                break;
//            }
//        }
//        
//        if (ok) {
//            printf("%s\n", p); // Afișăm cuvântul valid
//        }
//
//        p = strtok(NULL, delim); // Continuăm cu următorul cuvânt
//    }
//
//    free(sir); // Eliberăm memoria alocată
//    return 0;
//}
