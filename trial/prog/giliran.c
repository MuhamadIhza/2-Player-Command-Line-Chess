#include "../def/queue.h"
#include <stdio.h>

void Urutan(Queue *Q1){
    char a;
    char b;
    int i;
    a = 'Player 1';
    b = 'Player 2';
    CreateEmpty(Q1,50);
    for (i = 1;i < MaxEl(*Q1);i++){
        if (i % 2 == 1){
            Add(Q1,a);
        } else{
            Add(Q1,b);
        }
    }
}
