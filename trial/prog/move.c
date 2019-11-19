#include "../def/stack.h"
#include "board.h"

Stack getPionMove(address P);
Stack getHorseMove(address P);

typedef struct {
  POINT Move[30];
  int Num;
} ListPindah;

Stack getPionMove(address P){
  Stack S;
  CreateEmptyStack(&S);
  POINT x1;
  POINT x0;
  x0 = Lokasi(P);
  x1 = PlusDelta(x0,0,1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  return S;
}

Stack getHorseMove(address P){
  Stack S;
  CreateEmptyStack(&S);
  POINT x1;
  POINT x0;
  x0 = Lokasi(P);
  x1 = PlusDelta(x0,2,1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,2,-1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,-2,1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,-2,-1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }

  x1 = PlusDelta(x0,1,2);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,1,-2);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,-1,2);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,-1,-2);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  return S;
}

int main(){
  TabEl T;
  List L1,L2;
  initboard(&L1,&L2);
  T = board(L1,L2);
  printarray(T);
  address P;
  infolist X;
  X.Lokasi = MakePOINT(7,1);
  X.Infobidak = 'h';
  P = Search(L1,X);
  //Lokasi(P)=MakePOINT(4,4);
  T = board(L1,L2);
  printarray(T);


  Stack S;
  S = getHorseMove(P);
  POINT Z;
  while (! IsEmptyStack(S)) {
    Pop(&S,&Z);
    TulisPOINT(Z);
  }
  printf("\n");

  return 0;
}
