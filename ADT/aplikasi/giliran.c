#include "../def/queue.h"
#include "board.h"
#include <stdio.h>


void inisialisasi_Urutan(Queue *Q1) {
    char a;
    char b;
    int i;
    a = '1';
    b = '2';
    CreateEmpty(Q1,200);
    for (i = 1;i <= 100;i++){
        if (i % 2 == 1){
            Add(Q1,a);
        } else{
            Add(Q1,b);
        }
    }
}
