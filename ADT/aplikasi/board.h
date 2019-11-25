#ifndef BOARD_H
#define BOARD_H

#include "../main/listlinier.h"
#include "../main/array.h"
#include "../main/point.h"
#include "../main/stack.h"
#include "giliran.h"
#include <stdio.h>

typedef struct {
  POINT Move[30];
  int Num;
} ListPindah;
typedef struct {
  infolist PPawn[16];
  int PNum;
}ListPossible;



void initboard(List *L1,List *L2);
/*Menginisialisasi kondisi awal permainan 
  dengan mengisi L1 dan L2 dengan bidak yang sesuai*/
TabEl board(List L1,List L2);
/* Memindahkan infobidak L1 dan L2 ke tempat yang sesuai
   agar mudah dicetak menjadi papan(peta)*/
void printarray(TabEl T);
/* Mencetak papan/peta dari array berisi bidak yang tersusun
   menjadi papan catur yang sudah ada*/
void TabToList(TabEl T,List *L1, List *L2);

ListPossible pawnavail(List L1,List L2);
/* Mencari bidak putih apa saja yang bisa bergerak*/
ListPossible pawnavail2(List L1,List L2);
/* Mencari bidak hitam apa saja yang bisa bergerak*/

ListPindah getPionMove(address P,List *L1, List *L2);
/* Mencari kemungkinan gerak pion putih*/
ListPindah getPionMove2(address P,List *L1, List *L2);
/* Mencari kemungkinan gerak pion hitam*/
ListPindah getBishopMove(address P,List *L1, List *L2);
/* Mencari kemungkinan pindah gerak menteri*/
ListPindah getHorseMove(address P,List *L1, List *L2);
/* Mencari kemungkinan pindah gerak kuda*/
ListPindah getRookMove(address P,List *L1, List *L2);
/* Mencari kemungkinan pindah gerak benteng*/
ListPindah getQueenMove(address P,List *L1, List *L2);
/* Mencari kemungkinan pindah gerak ratu*/
ListPindah getKingMove(address P,List *L1, List *L2);
/* Mencari kemungkinan pindah gerak raja*/


void Castling(address K, address RK, address RQ, List *L1, List *L2);
/* Memindahkan bidak dengan cara Castling untuk List 1. */
void Castling2(address K, address RK, address RQ, List *L1, List *L2);
/* Memindahkan bidak dengan cara Castling untuk List 2. */
boolean CanCastling(address K, address RK, address RQ, List *L1, List *L2);
/* Melakukan validasi apakah gerakan Castling dapat dilakukan. */
void ShowSpecialMove(List *L1, List *L2, TabEl *T);
/* Menampilkan gerakan khusus yang dapat dilakukan untuk List 1. */
void ShowSpecialMove2(List *L1, List *L2, TabEl *T);
/* Menampilkan gerakan khusus yang dapat dilakukan untuk List 2. */

boolean IsCheck(address P,List *teman, List *musuh);
boolean IsCheck2(address P,List *teman, List *musuh);
boolean IsCheckMate(address P,List *teman, List *musuh);

/*Selektor*/
POINT moveselector(ListPindah S,int select);
infolist possiblepawn(ListPossible S,int select);

/*Prosedur gerak*/
void move(List *L1, List *L2,TabEl *T,int *poinP1);
/*Prosedur gerak untuk P1*/
void move2(List *L1, List *L2,TabEl *T,int *poinP2);
/*Prosedur gerak untuk P2*/


#endif
