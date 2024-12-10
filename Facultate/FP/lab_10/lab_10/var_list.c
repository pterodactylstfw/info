//
//  var_list.c
//  lab_10
//
//  Created by Raul Constantin on 10.12.2024.
//

#include <stdio.h>
#include <stdarg.h>

double maxim(int n, ...)
{
    //folosim tipul de date va_list din stdarg.h
    
    va_list list;
    va_start(list, n);
    
    double vmax= -1E10;
    
    for(int i=0;i<n;i++)
    {
        double x = va_arg(list, double);
        if(x>vmax) vmax=x;
    }
    va_end(list);
    
    return vmax;
}


void main(void)
{
    
}
