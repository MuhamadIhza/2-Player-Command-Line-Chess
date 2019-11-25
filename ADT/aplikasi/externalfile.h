#ifndef __SCORE_BOARD__
#define __SCORE_BOARD__

#include "../main/mesin_kata.h"
#include "../main/prioqueue.h"

/*------------------- LEADERBOARD -------------------------*/
/* Menambahkan Nama Pemain dan Score ke dalam Leaderboard */ 
void addtolb(char* pemain,int score);

/* mencetak Leaderboard ke Layar*/ 
void printlb();

/* Mengubah Character ke Integer*/ 
int toint(char* x);

#endif
