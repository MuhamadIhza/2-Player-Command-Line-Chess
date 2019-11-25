#include "array.h"
#include <stdio.h>

int main(){
    TabEl T;
    T.Neff = 0;
    if (IsEmptyArray(T))
    {
        printf("Array Kosong\n");
    }
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            T.TI[i][j] = 'Z';
            T.Neff ++;
        }
    }
    printf("%d\n",NbElmt(T));

    return 0;
}