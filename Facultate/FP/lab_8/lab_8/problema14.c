//
//  problema14.c
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
    char vec[25][256];
    char *s1;
    s1 = (char*)calloc(256, sizeof(char));
    fgets(s1, 256, stdin);
    s1[strlen(s1)-1] = '\0';
    
    char * p= strtok(s1, " ");
    short i = 9;
    while(p)
    {
        
    }
}
