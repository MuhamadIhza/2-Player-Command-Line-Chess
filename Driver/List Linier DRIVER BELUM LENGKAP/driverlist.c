#include "listlinier.h"
#include <stdio.h>
int main(){

    List L;
    CreateEmptyList(&L);
    if (IsEmptyList(L))
    {
        printf("List kosong\n");
    }
    infolist X;
    X.Lokasi = MakePOINT(4,3);
    X.Infobidak = 'K';
    X.CountMove = 0;
    InsVFirst(&L,X);
    printf("Bidak %c di 4,3\n",SearchbyLocation(L,MakePOINT(4,3)));
    printf("Boolean %d\n",SearchEL(L,X.Lokasi));
    printf("Boolean %d\n",SearchBidak(L,'P'));
    
    return 0;
}
