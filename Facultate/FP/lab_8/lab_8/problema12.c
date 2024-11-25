////
////  problema12.c
////  lab_8
////
////  Created by Raul Constantin on 19.11.2024.
////
//
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
//        if (islower(p[0])) p[0] = toupper(p[0]);
//        
//        for(int i=1;i<strlen(p);i++)
//            if(isupper(p[i])) p[i] = tolower(p[i]);
//        
//        printf("%s ", p);
//
//        p = strtok(NULL, delim); // Continuăm cu următorul cuvânt
//    }
//
//    free(sir); // Eliberăm memoria alocată
//    return 0;
//}
