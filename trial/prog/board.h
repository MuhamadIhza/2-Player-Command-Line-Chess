#include "../def/listlinier.h"
#include "../def/array.h"
#include "../def/point.h"
#include "../def/stack.h"
#include <stdio.h>

typedef struct {
  POINT Move[30];
  int Num;
} ListPindah;

void initboard(List *L1,List *L2);
TabEl board(List L1,List L2);
void printarray(TabEl T);
ListPindah getPionMove(address P,List *L1, List *L2);
Stack getHorseMove(address P);

