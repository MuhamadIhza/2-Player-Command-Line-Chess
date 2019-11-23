#include "../def/queue.h"
#include "board.h"
#include <stdio.h>


void inisialisasi_Urutan(Queue *Q1) {
    char a;
    char b;
    int i;
    a = '1';
    b = '2';
    CreateEmpty(Q1,50);
    for (i = 1;i < MaxElQueue(*Q1);i++){
        if (i % 2 == 1){
            Add(Q1,a);
        } else{
            Add(Q1,b);
        }
    }
}
/* void Urutan(Queue *Q1, List *L1,List *L2, TabEl *T) {
    while (!(IsEmptyQueue(*Q1))){
        if(InfoHead(*Q1) == '1'){
            printf("Giliran Player 1 untuk memindahkan bidaknya !\n");
            move(L1,L2,T);
        } else {
            printf("Giliran Player 2 untuk memindahkan bidaknya !\n");
            move2(L1,L2,T);
        }
        Del(Q1,&InfoHead(*Q1));
    } 
} */
