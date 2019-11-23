#ifndef BOARD_H
#define BOARD_H

#include "../def/listlinier.h"
#include "../def/array.h"
#include "../def/point.h"
#include "../def/stack.h"
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
TabEl board(List L1,List L2);
void printarray(TabEl T);
ListPindah getPionMove(address P,List *L1, List *L2);
ListPindah getBishopMove(address P,List *L1, List *L2);
ListPindah getPionMove2(address P,List *L1, List *L2);
ListPindah getHorseMove(address P,List *L1, List *L2);
ListPindah getKingMove(address P,List *L1, List *L2);
ListPindah getRookMove(address P,List *L1, List *L2);
ListPindah getQueenMove(address P,List *L1, List *L2);

POINT moveselector(ListPindah S,int select);
infolist possiblepawn(ListPossible S,int select);
void move(List *L1, List *L2,TabEl *T);
void move2(List *L1, List *L2,TabEl *T);
ListPossible pawnavail(List L1,List L2);
ListPossible pawnavail2(List L1,List L2);
#endif