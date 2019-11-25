#include "stack.h"
#include <stdio.h>

int main(){

    Stack S;
    CreateEmptyStack(&S);
    if (IsEmptyStack(S))
    {
        printf("Stack kosong\n");
    }
    infostack X;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            X.T.TI[i][j] = 'Z';
            X.T.Neff ++;
        }
    }
    X.Poin1 = 1;
    X.Poin2 = 0;
    Push(&S,X);
    Pop(&S,&X);
    printf("Poin 1 %d\n",X.Poin1);
    printf("Poin 2 %d\n",X.Poin2);
    return 0;
}