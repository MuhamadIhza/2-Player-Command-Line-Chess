#include "queue.h"
#include <stdio.h>

int main(){
    Queue Q;
    CreateEmpty(&Q,10);
    if (IsEmptyQueue(Q))
    {
        printf("Queue kosong\n");
    }
    Add(&Q,'A');
    Add(&Q,'B');
    Add(&Q,'C');
    printf("jumlah elemen queue %d\n",NBElmt(Q));
    infotypequeue X;
    Del(&Q,&X);
    printf("jumlah elemen queue %d\n",NBElmt(Q));
    printf("hasil del %c\n",X);
    return 0;
}