////
////  problema6.c
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
//int main(void)
//{
//    struct tablou {
//        int ct;
//        char carac;
//    }v[27];
//    
//    char * sir = (char*)calloc(256, sizeof(char));
//    fgets(sir, 256, stdin);
//    
//    sir[strlen(sir)-1] = '\0';
//    
//    int k = 0;
//    for(int i=0;i<strlen(sir);i++)
//    {
//        if(islower(sir[i])){ bool ok=0;//daca e lit mic
//            for(int j=0;j<k;j++)
//                if(v[j].carac==sir[i]) {v[j].ct++; ok=1;
//                    if(ok) break;}
//            if(ok==0) {v[k].carac = sir[i], v[k].ct = 1;k++;}
//        }
//                
//        
//    }
//    
//    printf("Lungimea sirului de caractere este %d\n", strlen(sir));
//    
//    for(int i=0;i<k;i++)
//        printf("Litera %c apare de %d ori\n",v[i].carac, v[i].ct);
//    
//    
//}
