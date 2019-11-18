#include "board.h"

void initboard(List *L1,List *L2){
  CreateEmpty(L1);
  infotype bidak;
  bidak.Lokasi = MakePOINT(8,1);bidak.Infobidak = 'r';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(7,1);bidak.Infobidak = 'h';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(6,1);bidak.Infobidak = 'b';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(5,1);bidak.Infobidak = 'q';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(4,1);bidak.Infobidak = 'k';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(3,1);bidak.Infobidak = 'b';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(2,1);bidak.Infobidak = 'h';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(1,1);bidak.Infobidak = 'r';
  InsVFirst(L1,bidak);

  bidak.Lokasi = MakePOINT(8,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(7,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(6,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(5,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(4,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(3,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(2,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(1,2);bidak.Infobidak = 'p';
  InsVFirst(L1,bidak);

  CreateEmpty(L2);
  bidak.Lokasi = MakePOINT(8,8);bidak.Infobidak = 'R';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(7,8);bidak.Infobidak = 'H';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(6,8);bidak.Infobidak = 'B';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(5,8);bidak.Infobidak = 'K';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(4,8);bidak.Infobidak = 'Q';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(3,8);bidak.Infobidak = 'B';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(2,8);bidak.Infobidak = 'H';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(1,8);bidak.Infobidak = 'R';
  InsVFirst(L2,bidak);

  bidak.Lokasi = MakePOINT(8,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(7,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(6,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(5,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(4,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(3,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(2,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(1,7);bidak.Infobidak = 'P';
  InsVFirst(L2,bidak);
}

TabEl board(List L1,List L2){
  TabEl T;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      T.TI[i][j] = '-';
      T.Neff ++;
    }
  }
  address P = First(L1);
  while (P!=Nil) {
    T.TI[Absis(Lokasi(P))][Ordinat(Lokasi(P))]=Infobidak(P);
    T.Neff ++;
    P = Next(P);
  }

  address Q = First(L2);
  while (Q!=Nil) {
    T.TI[Absis(Lokasi(Q))][Ordinat(Lokasi(Q))]=Infobidak(Q);
    T.Neff ++;
    Q = Next(Q);
  }
  return T;
}

void printarray(TabEl T){
  printf("\e[1;1H\e[2J");/*clear screen*/
  printf("+-------------------------------+\n");
  for (int j = 8; j > 0; j--) {
    for (int i = 1; i < 9 ; i++) {
      if (T.TI[i][j]=='-') {
        if ((j%2==0 && i%2==1)||(j%2==1 && i%2==0)) {
          printf("| ■ ");
        } else {
          printf("|   ");
        }
      }else{
        printf("| %c ",T.TI[i][j]);
      }
      if (i%8==0) {
        printf("| %d\n",j);
        printf("+-------------------------------+\n");
      }
    }
  }
  printf("  a   b   c   d   e   f   g   h  \n");
}

int main(){
  TabEl T;
  List L1,L2;
  initboard(&L1,&L2);
  T = board(L1,L2);
  printarray(T);
  return 0;
}
