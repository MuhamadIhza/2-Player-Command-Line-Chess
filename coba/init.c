#include "init.h"
#include "listlinier.h"
#include "Main/array.h"
void inisialisasi_papan(List *L){
    CreateEmpty(L);
    InsVFirst(L,'R');
    InsVFirst(L,'H');
    InsVFirst(L,'B');
    InsVFirst(L,'Q');
    InsVFirst(L,'K');
    InsVFirst(L,'B');
    InsVFirst(L,'H');
    InsVFirst(L,'R');
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(L,'P');
    }
    for (int i = 1; i <= 32; i++)
    {
        InsVFirst(L,'_');
    }
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(L,'p');
    }
    InsVFirst(L,'r');
    InsVFirst(L,'h');
    InsVFirst(L,'b');
    InsVFirst(L,'q');
    InsVFirst(L,'k');
    InsVFirst(L,'b');
    InsVFirst(L,'h');
    InsVFirst(L,'r');
}

TabInt ListToArr (List L)
{
    TabInt T;
    address P;
    int 
    List Bidak; 
    inisialisasi_papan(&Bidak);
    MakeEmpty(&T);
    P = First(Bidak);
    while (P != Nil){
        for 

    }

}