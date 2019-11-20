#include "board.h"
void initboard(List *L1,List *L2){
  CreateEmptyList(L1);
  infolist bidak;
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

  CreateEmptyList(L2);
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
  //printf("\e[1;1H\e[2J");/*clear screen*/
  printf("+-------------------------------+\n");
  for (int j = 8; j > 0; j--) {
    for (int i = 1; i < 9 ; i++) {
      if (T.TI[i][j]=='-') {
        if ((j%2==0 && i%2==1)||(j%2==1 && i%2==0)) {
          printf("|   ");
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

ListPindah getPionMove(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  POINT x1,x2,x3;
  POINT x0;
  x0 = Lokasi(P);
  x1 = PlusDelta(x0,0,1);
  if (IsPointValid(x1)) {
    if (!(SearchEL(*L1,x1) || SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }
  x2 = PlusDelta(x0,1,1);
  x3 = PlusDelta(x0,-1,1);
  if (IsPointValid(x2)){
    if (SearchEL(*L2,x2)){
      S.Num ++;
      S.Move[S.Num] = x2;      
    }
  }
  if (IsPointValid(x3)){
    if (SearchEL(*L2,x3)){
      S.Num ++;
      S.Move[S.Num] = x3;      
    }
  }
  return S;
}

ListPindah getPionMove2(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  POINT x1,x2,x3;
  POINT x0;
  x0 = Lokasi(P);
  x1 = PlusDelta(x0,0,-1);
  if (IsPointValid(x1)) {
    if (!(SearchEL(*L1,x1) || SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }
  x2 = PlusDelta(x0,1,-1);
  x3 = PlusDelta(x0,-1,-1);
  if (IsPointValid(x2)){
    if (SearchEL(*L1,x2)){
      S.Num ++;
      S.Move[S.Num] = x2;      
    }
  }
  if (IsPointValid(x3)){
    if (SearchEL(*L1,x3)){
      S.Num ++;
      S.Move[S.Num] = x3;      
    }
  }
  return S;
}

ListPindah getHorseMove(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  POINT x1;
  POINT x0;
  x0 = Lokasi(P);
  x1 = PlusDelta(x0,2,1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }

  x1 = PlusDelta(x0,2,-1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }

  x1 = PlusDelta(x0,-2,1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }


  x1 = PlusDelta(x0,-2,-1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }

  x1 = PlusDelta(x0,1,2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }

  x1 = PlusDelta(x0,1,-2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }
  x1 = PlusDelta(x0,-1,2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }
  x1 = PlusDelta(x0,-1,-2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
    }
  }
  return S;
}

ListPindah getRookMove(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  POINT x0,x1;
  x0 = Lokasi(P);
  x1 = PlusDelta (x0,0,1);
  while (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,0,1);
     }
     else if (SearchEL(*L2,x1)){
       S.Num++;
       S.Move[S.Num] = x1;
       break;
     }
     else break;
  }

  x1 = PlusDelta (x0,0,-1);
  while (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,0,-1);
     }
     else if (SearchEL(*L2,x1)){
       S.Num++;
       S.Move[S.Num] = x1;
       break;
     }
     else break;
  }

  x1 = PlusDelta (x0,1,0);
  while (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,1,0);
     }
     else if (SearchEL(*L2,x1)){
       S.Num++;
       S.Move[S.Num] = x1;
       break;
     }
     else break;
  }

  x1 = PlusDelta (x0,-1,0);
  while (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,-1,0);
     }
     else if (SearchEL(*L2,x1)){
       S.Num++;
       S.Move[S.Num] = x1;
       break;
     }
     else break;
  }
  return S;
}

ListPindah getBishopMove(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  POINT x0=Lokasi(P),x1;

  x1 = PlusDelta(x0,1,1);
  while (IsPointValid(x1)){
    if (! (SearchEL(*L1,x1)) ){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,1,1);
    } else if (SearchEL(*L2,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      break;
    } else break;
  }

  x1 = PlusDelta(x0,1,-1);
  while (IsPointValid(x1)){
    if (! (SearchEL(*L1,x1)) ){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,1,-1);
    } else if (SearchEL(*L2,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      break;
    } else break;
  }

  x1 = PlusDelta(x0,-1,1);
  while (IsPointValid(x1)){
    if (! (SearchEL(*L1,x1)) ){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,-1,1);
    } else if (SearchEL(*L2,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      break;
    } else break;
  }

  x1 = PlusDelta(x0,-1,-1);
  while (IsPointValid(x1)){
    if (! (SearchEL(*L1,x1)) ){
      S.Num ++;
      S.Move[S.Num] = x1;
      x1 = PlusDelta(x1,-1,-1);
    } else if (SearchEL(*L2,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
      break;
    } else break;
  }
  return S;
}

ListPindah getKingMove(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  POINT x0,x1;
  x0 = Lokasi(P);
  x1 = PlusDelta (x0,0,1);
  if (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
     }
  }

  x1 = PlusDelta (x0,1,0);
  if (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
     }
  }

  x1 = PlusDelta (x0,1,1);
  if (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
     }
  }

  x1 = PlusDelta (x0,0,-1);
  if (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
     }
  }

  x1 = PlusDelta (x0,-1,0);
  if (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
     }
  }

  x1 = PlusDelta (x0,-1,-1);
  if (IsPointValid(x1)){
     if (!SearchEL(*L1,x1)){
      S.Num ++;
      S.Move[S.Num] = x1;
     }
  }
}




int main(){
  TabEl T;
  List L1,L2;
  initboard(&L1,&L2);
  T = board(L1,L2);
  printarray(T);
  address P;
  infolist X;
  // X.Lokasi = MakePOINT(4,2);
  // X.Infobidak = 'p';
  // P = Search(L1,X);
  // Lokasi(P)=MakePOINT(4,6);
  T = board(L1,L2);
  


  ListPindah S;
  address Q,tes2;
  X.Lokasi = MakePOINT(4,1);
  X.Infobidak = 'k';
  P = Search(L1,X);
  //Lokasi(P) = MakePOINT(2,5);
  T = board(L1,L2);
  printarray(T);

  ListPindah R;
  address O,tes;
  infolist kosong;
  X.Lokasi = MakePOINT(4,1);
  X.Infobidak = 'k';
  O = Search(L1,X);

  X.Lokasi = MakePOINT(3,1);
  X.Infobidak = 'b';
  P = Search(L1,X);
  R = getBishopMove(P,&L1,&L2);
  POINT Y;
  R = getKingMove(P,&L1,&L2);
  R = getRookMove(P,&L1,&L2);
  int i = 1;
  while ( i <= R.Num)
  {
    TulisPOINT(R.Move[i]);
    i++;
  }
  
  printf("\n");

  return 0;
}
