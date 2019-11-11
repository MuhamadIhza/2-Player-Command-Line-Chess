#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    List bidak;
    CreateEmpty(&bidak);
    InsVFirst(&bidak,'R');
    InsVFirst(&bidak,'H');
    InsVFirst(&bidak,'B');
    InsVFirst(&bidak,'Q');
    InsVFirst(&bidak,'K');
    InsVFirst(&bidak,'B');
    InsVFirst(&bidak,'H');
    InsVFirst(&bidak,'R');
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(&bidak,'P');
    }
    for (int i = 1; i <= 32; i++)
    {
        InsVFirst(&bidak,'_');
    }
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(&bidak,'p');
    }
    InsVFirst(&bidak,'r');
    InsVFirst(&bidak,'h');
    InsVFirst(&bidak,'b');
    InsVFirst(&bidak,'q');
    InsVFirst(&bidak,'k');
    InsVFirst(&bidak,'b');
    InsVFirst(&bidak,'h');
    InsVFirst(&bidak,'r');
    PrintBoard(bidak);
    printf("\n");
    return 0;
}