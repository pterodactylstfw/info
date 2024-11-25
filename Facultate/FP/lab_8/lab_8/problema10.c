////
////  problema10.c
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
//int main(void){
//    char *s1, *s2;
//     s1 = (char*)calloc(256, sizeof(char));
//    s2 = (char*)calloc(256, sizeof(char));
//    fgets(s1, 256, stdin);
//    
//    s1[strlen(s1)-1] = '\0';
//    
//    char *cuvant = (char*) calloc(10,sizeof(char));
//    
//    scanf("%s", cuvant);
//    cuvant[strlen(cuvant)-1] = '\0';
//    
//    char *p = strtok(s1, " ");
//    
//    while(p)
//    {
//        if(strstr(p, cuvant)==0) {
//            strcat(s2, p);
//            strcat(s2, " ");
//        }
//        p = strtok(NULL," ");
//    }
//    
//    s2[strlen(s2)]= '\0';
//    printf("%s", s2);
//    
//}
