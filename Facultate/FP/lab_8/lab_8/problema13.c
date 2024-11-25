//
//  problema13.c
//  lab_8
//
//  Created by Raul Constantin on 19.11.2024.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
   char *s1, *s2;
   s1 = (char*)calloc(256, sizeof(char));
   s2 = (char*)calloc(261, sizeof(char));
   fgets(s1, 256, stdin);
   fgets(s2, 256, stdin);
   s1[strlen(s1)-1] = '\0';
   s2[strlen(s2)-1] = '\0';
    
    if(strcmp(s1, s2)<0) printf("s1 este mai mic lexicografic decat s2");
    else if(strcmp(s1, s2)==0) printf("sirurile sunt egale");
    else printf("s2 este mai mic lexicografic decat s1");
    
}
