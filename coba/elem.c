#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"


int main(){
    List bidak1;
    List bidak2
    CreateEmpty(&bidak);
    InsVFirst(&bidak1,'R');
    InsVFirst(&bidak1,'H');
    InsVFirst(&bidak1,'B');
    InsVFirst(&bidak1,'Q');
    InsVFirst(&bidak1,'K');
    InsVFirst(&bidak1,'B');
    InsVFirst(&bidak1,'H');
    InsVFirst(&bidak1,'R');
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(&bidak1,'P');
    }
    for (int i = 1; i <= 32; i++)
    {
        InsVFirst(&bidak1,'_');
    }
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(&bidak2,'p');
    }
    InsVFirst(&bidak2,'r');
    InsVFirst(&bidak2,'h');
    InsVFirst(&bidak2,'b');
    InsVFirst(&bidak2,'q');
    InsVFirst(&bidak2,'k');
    InsVFirst(&bidak2,'b');
    InsVFirst(&bidak2,'h');
    InsVFirst(&bidak2,'r');
    PrintBoard(bidak1,bidak2);
    printf("\n");
    return 0;
}
