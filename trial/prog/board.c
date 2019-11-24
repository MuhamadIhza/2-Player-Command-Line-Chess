#include "board.h"

void initboard(List *L1,List *L2){
  CreateEmptyList(L1);
  infolist bidak;
  bidak.Lokasi = MakePOINT(8,1);bidak.Infobidak = 'r';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(7,1);bidak.Infobidak = 'h';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(6,1);bidak.Infobidak = 'b';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(5,1);bidak.Infobidak = 'q';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(4,1);bidak.Infobidak = 'k';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(3,1);bidak.Infobidak = 'b';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(2,1);bidak.Infobidak = 'h';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(1,1);bidak.Infobidak = 'r';bidak.CountMove = 0;
  InsVFirst(L1,bidak);

  bidak.Lokasi = MakePOINT(8,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(7,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(6,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(5,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(4,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(3,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(2,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);
  bidak.Lokasi = MakePOINT(1,2);bidak.Infobidak = 'p';bidak.CountMove = 0;
  InsVFirst(L1,bidak);

  CreateEmptyList(L2);
  bidak.Lokasi = MakePOINT(8,8);bidak.Infobidak = 'R';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(7,8);bidak.Infobidak = 'H';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(6,8);bidak.Infobidak = 'B';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(5,8);bidak.Infobidak = 'K';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(4,8);bidak.Infobidak = 'Q';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(3,8);bidak.Infobidak = 'B';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(2,8);bidak.Infobidak = 'H';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(1,8);bidak.Infobidak = 'R';bidak.CountMove = 0;
  InsVFirst(L2,bidak);

  bidak.Lokasi = MakePOINT(8,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(7,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(6,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(5,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(4,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(3,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(2,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
  InsVFirst(L2,bidak);
  bidak.Lokasi = MakePOINT(1,7);bidak.Infobidak = 'P';bidak.CountMove = 0;
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
  POINT x1,x2,x3,x4;
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
  x4 = PlusDelta(x0,0,2);
  if (IsPointValid(x4) && Ordinat(Lokasi(P)) == 2) {
    if (!(SearchEL(*L1,x1) || SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x4;
    }
  }
  return S;
}

ListPindah getPionMove2(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  POINT x1,x2,x3,x4;
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
  x4 = PlusDelta(x0,0,-2);
  if (IsPointValid(x4) && Ordinat(Lokasi(P)) == 7) {
    if (!(SearchEL(*L1,x4) || SearchEL(*L2,x4))){
      S.Num ++;
      S.Move[S.Num] = x4;
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
  boolean Stop;
  S.Num = 0;
  POINT x0,x1;
  x0 = Lokasi(P);
  x1 = PlusDelta (x0,0,1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,0,1);
     }
     else break;
  }

  x1 = PlusDelta (x0,0,-1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,0,-1);
     }
     else break;
  }

  x1 = PlusDelta (x0,1,0);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,1,0);
     }
     else break;
  }
  
  x1 = PlusDelta (x0,-1,0);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,-1,0);
     }
     else break;
  }
  return S;
}

ListPindah getBishopMove(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  boolean Stop;
  POINT x0=Lokasi(P),x1;
  
  x1 = PlusDelta(x0,1,1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,1,1);
     }
     else break;
  }

  x1 = PlusDelta(x0,1,-1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,1,-1);
     }
     else break;
  }

  x1 = PlusDelta(x0,-1,1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,-1,1);
     }
     else break;
  }
  
  x1 = PlusDelta(x0,-1,-1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,-1,-1);
     }
     else break;
  }
  return S;
}

ListPindah getQueenMove(address P,List *L1, List *L2){
  ListPindah S;
  S.Num = 0;
  boolean Stop;
  POINT x0=Lokasi(P),x1;
  x1 = PlusDelta (x0,0,1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,0,1);
     }
     else break;
  }

  x1 = PlusDelta (x0,0,-1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,0,-1);
     }
     else break;
  }

  x1 = PlusDelta (x0,1,0);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,1,0);
     }
     else break;
  }

  x1 = PlusDelta (x0,-1,0);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,-1,0);
     }
     else break;
  }

  x1 = PlusDelta(x0,1,1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,1,1);
     }
     else break;
  }

  x1 = PlusDelta(x0,1,-1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,1,-1);
     }
     else break;
  }

  x1 = PlusDelta(x0,-1,1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,-1,1);
     }
     else break;
  }

  x1 = PlusDelta(x0,-1,-1);
  Stop = false;
  while (IsPointValid(x1) && (!Stop)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      S.Num ++;
      S.Move[S.Num] = x1;
      if (SearchEL(*L2,x1)){
        Stop = true;
      }
      x1 = PlusDelta(x1,-1,-1);
     }
     else break;
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
  return S;
}

boolean CanCastling(address K, address RK, address RQ, List *L1, List *L2){
  boolean Stop, CanCastRK, CanCastRQ;
  POINT x0=Lokasi(K), x1, RKing, RQueen, xK, xRK, xRQ;
  x1 = PlusDelta(x0,0,0);
  Stop = false;
  CanCastRK = false;
  RKing = Lokasi(RK); RQueen = Lokasi(RQ);
  while (IsPointValid(x1) && (!Stop)){
    while (Absis(x1) != Absis(RKing)){
      x1 = PlusDelta(x0,0,1);
      if (SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
        Stop = true;
      }
    }
  }
  if (!Stop && (CountMove(RK) == 0) && (CountMove(K) == 0)){
    CanCastRK = true;
  }

  x0=Lokasi(K);
  x1 = PlusDelta(x0,0,0);
  Stop = false;
  CanCastRQ = false;
  while (IsPointValid(x1) && (!Stop)){
    while (Absis(x1) != Absis(RQueen)){
      x1 = PlusDelta(x0,0,1);
      if (SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
        Stop = true;
      }
    }
  }

  if (!Stop && (CountMove(RQ) == 0) && (CountMove(K) == 0)){
    CanCastRQ = true;
  }

  if (CanCastRQ || CanCastRK){
    return true;
  }
  else return false;
}

void Castling(address K, address RK, address RQ, List *L1, List *L2){
  boolean Stop, CanCastRK, CanCastRQ;
  POINT x0=Lokasi(K), x1, RKing, RQueen, xK, xRK, xRQ;
  x1 = PlusDelta(x0,0,0);
  Stop = false;
  CanCastRK = false;
  RKing = Lokasi(RK); RQueen = Lokasi(RQ);
  while (IsPointValid(x1) && (!Stop)){
    while (Absis(x1) != Absis(RKing)){
      x1 = PlusDelta(x0,0,1);
      if (SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
        Stop = true;
      }
    }
  }
  if (!Stop && (CountMove(RK) == 0) && (CountMove(K) == 0)){
    CanCastRK = true;
  }

  x0=Lokasi(K);
  x1 = PlusDelta(x0,0,0);
  Stop = false;
  CanCastRQ = false;
  while (IsPointValid(x1) && (!Stop)){
    while (Absis(x1) != Absis(RQueen)){
      x1 = PlusDelta(x0,0,1);
      if (SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
        Stop = true;
      }
    }
  }

  if (!Stop && (CountMove(RQ) == 0) && (CountMove(K) == 0)){
    CanCastRQ = true;
  }  

  int pilihan;
  xK = Lokasi(K);
  xRK = Lokasi(RK);
  xRQ = Lokasi(RQ);
  if (CanCastRK && CanCastRQ){
    printf("Pilihan Castling yang tersedia: \n");
    printf("1. Castling King\n");
    printf("2. Castling Queen\n");
    scanf("%d", &pilihan);
    if (pilihan == 1){
      xK = PlusDelta(xK, 2, 0);
      xRK = PlusDelta(xRK, -2, 0);
      Lokasi(K) = xK; Lokasi(RK) = xRK;
    }
    else if (pilihan == 2){
      xK = PlusDelta(xK, -2, 0);
      xRQ = PlusDelta(xRK, 3, 0);
      Lokasi(K) = xK; Lokasi(RQ) = xRQ;
    }
  }
  else if (CanCastRK){
    xK = PlusDelta(xK, 2, 0);
    xRK = PlusDelta(xRK, -2, 0);
    Lokasi(K) = xK; Lokasi(RK) = xRK;
  }
  else if (CanCastRK){
    xK = PlusDelta(xK, -2, 0);
    xRQ = PlusDelta(xRK, 3, 0);
    Lokasi(K) = xK; Lokasi(RQ) = xRQ;
  }
}

void ShowSpecialMove(List *L1, List *L2, TabEl *T){
  int pilihan;
  boolean cek;
  /*search address king*/
  address K;
  infolist king;
  king.Lokasi = MakePOINT(4,1); 
  king.Infobidak = 'k';  
  K = Search(*L1,king);

  /*search address rook kanan*/
  address RK;
  infolist RookKing;
  RookKing.Lokasi = MakePOINT(8,1); 
  RookKing.Infobidak = 'r';  
  RK = Search(*L1,RookKing);

  /*search address rook kiri*/
  address RQ;
  infolist RookQueen;
  RookQueen.Lokasi = MakePOINT(1,1); 
  RookQueen.Infobidak = 'r';  
  RQ = Search(*L1,RookQueen);

  // cek = CanCastling(K,RK,RQ,L1,L2);
  // if(cek){
  printf("Pilihan Special Move yang tersedia: \n");
  printf("1. Castling\n");
  scanf("%d", &pilihan);
  if (pilihan == 1){
    Castling(K, RK, RQ, L1, L2);
    printarray(*T);
  }
  //}
  //else{
    //printf("Tidak ada Special Move yang tersedia.\n");;
  //}
}

POINT moveselector(ListPindah S,int select){
  POINT X;
  X = S.Move[select];
  return X;
}
infolist possiblepawn(ListPossible S,int select){
  infolist X;
  X = S.PPawn[select];
  return X;
}

ListPossible pawnavail(List L1,List L2){
  ListPossible S;
  address P;
  S.PNum = 0;
  P = First(L1);
  while (P!=Nil)
  {
    ListPindah R;
    switch (Infobidak(P))
    {
    case 'p':
      R = getPionMove(P,&L1,&L2);
      break;
    case 'r':
      R = getRookMove(P,&L1,&L2);
      break;
    case 'h':
      R = getHorseMove(P,&L1,&L2);
      break;
    case 'b':
      R = getBishopMove(P,&L1,&L2);
      break;
    case 'k':
      R = getKingMove(P,&L1,&L2);
      break;
    case 'q':
      R = getQueenMove(P,&L1,&L2);
      break;
    default:
      //printf("notdefined\n");
      break;
    }
    if (R.Num>0)
    {
      S.PNum++;
      S.PPawn[S.PNum]=Info(P);
    }
    
    P = Next(P);
  }
  return S;
}
ListPossible pawnavail2(List L1,List L2){
  ListPossible S;
  address P;
  S.PNum = 0;
  P = First(L2);
  while (P!=Nil)
  {
    ListPindah R;
    switch (Infobidak(P))
    {
    case 'P':
      R = getPionMove2(P,&L1,&L2);
      break;
    case 'R':
      R = getRookMove(P,&L2,&L1);
      break;
    case 'H':
      R = getHorseMove(P,&L2,&L1);
      break;
    case 'B':
      R = getBishopMove(P,&L2,&L1);
      break;
    case 'K':
      R = getKingMove(P,&L2,&L1);
      break;
    case 'Q':
      R = getQueenMove(P,&L2,&L1);
      break;
    default:
      break;
    }
    if (R.Num>0)
    {
      S.PNum++;
      S.PPawn[S.PNum]=Info(P);
    }
    
    P = Next(P);
  }
  return S;
}
void move(List *L1, List *L2,TabEl *T,int *poinP1){
  /*bidak yang mau dipindah*/
  address P;
  infolist X;
  ListPindah R;
  ListPossible S;
  S = pawnavail(*L1,*L2);
  printf("Bidak yang mungkin pindah\n");
  for (int j = 1; j <= S.PNum; j++)
  {
    printf("%d.",j);
    switch (S.PPawn[j].Infobidak)
      {
      case 'p':
        printf("Pion ");
        break;
      case 'r':
        printf("Benteng ");
        break;
      case 'h':
        printf("Kuda ");
        break;
      case 'b':
        printf("Menteri ");
        break;
      case 'q':
        printf("Ratu ");
        break;  
      case 'k':
        printf("Raja ");
        break;  
      default:
        break;
      }
    switch (Absis(S.PPawn[j].Lokasi))
      {
      case 1:
        printf("A,");
        break;
      case 2:
        printf("B,");
        break;
      case 3:
        printf("C,");
        break;
      case 4:
        printf("D,");
        break;
      case 5:
        printf("E,");
        break;  
      case 6:
        printf("F,");
        break;  
      case 7:
        printf("G,");
        break;
      case 8:
        printf("H,");
        break;    
      default:
        break;
      }
    printf("%d\n",Ordinat(S.PPawn[j].Lokasi));
  }
  printf("input select :");
  int select1;
  scanf(" %d",&select1);
  while (select1 <1 || select1 > S.PNum) {
    printf("Input tidak valid, masukkan kembali nomor bidak yang anda ingin gerakkan : \n");
    scanf(" %d",&select1);
  }
  X = possiblepawn(S,select1);
  P = Search(*L1,X);
  switch (X.Infobidak)
  {
  case 'p':
    R = getPionMove(P,L1,L2);
    break;
  case 'r':
    R = getRookMove(P,L1,L2);
    break;
  case 'h':
    R = getHorseMove(P,L1,L2);
    break;
  case 'b':
    R = getBishopMove(P,L1,L2);
    break;
  case 'k':
    R = getKingMove(P,L1,L2);
    break;
  case 'q':
    R = getQueenMove(P,L1,L2);
    break;
  default:
    printf("notdefined\n");
    break;
  }
  /* print possible moves*/
  if (R.Num!=0)
  {
    printf("Lokasi Mungkin Pindah\n");
    int i = 1;
    while ( i <= R.Num && R.Num!=0)
    {
      printf("%d.",i);
      TulisPOINT(R.Move[i]);
      printf("\n");
      i++;
    }
    printf("Select : ");
    /*pemindahan*/
    int select;
    int pilihan;
    scanf("%d",&select);
    while (select < 1 || select > R.Num){
          printf("Input tidak valid, masukkan kembali nomor lokasi yang anda inginkan : \n");
          scanf(" %d",&select);
    }
    POINT dest;
    dest = moveselector(R,select);
    if ( X.Infobidak = 'p' && Ordinat(dest) == 8){
      printf("Selamat,pion anda dapat dipromosikan, silahkan pilih transformasi bidak anda : ");
      printf("1.Benteng \n 2.Kuda \n 3.Mentri \n 4.Ratu \n");
      scanf("%d", &pilihan);
      while (pilihan < 1 || pilihan > 4){
        printf("Pilihan yang anda masukkan tidak valid, silahkan pilih kembali ! ");
        scanf("%d",&pilihan);
      }
      if (pilihan == 1) Infobidak(P) = 'r';
      else if (pilihan == 2)  Infobidak(P) = 'h';
      else if (pilihan == 3)  Infobidak(P) = 'b';
      else if (pilihan == 4)  Infobidak(P) = 'q';
    }
    Lokasi(P) = dest;
    if (SearchEL(*L2,dest))
    {
      switch (SearchbyLocation(*L2,dest))
      {
      case 'P':
        (*poinP1) +=1;
        break;
      case 'R':
        (*poinP1) += 4;
        break;
      case 'H':
        (*poinP1) += 2;
        break;
      case 'B':
        (*poinP1) += 4;
        break;
      case 'Q':
        (*poinP1) += 8;
        break;  
      case 'K':
        (*poinP1) += 10;
        break;  
      default:
        break;
      }
      DelPoint(L2,dest);
    }
    
    printf("\n");
    *T = board(*L1,*L2);
    printf("Bidak ");
    switch (Infobidak(P))
      {
      case 'p':
        printf("pion ");
        break;
      case 'r':
        printf("benteng ");
        break;
      case 'h':
        printf("kuda ");
        break;
      case 'b':
        printf("menteri ");
        break;
      case 'q':
        printf("ratu ");
        break;  
      case 'k':
        printf("raja ");
        break;  
      default:
        break;
      }
    printf("telah pindah dari %d,%d ke %d,%d\n",Absis(X.Lokasi),Ordinat(X.Lokasi),dest.X,dest.Y);
    printf("Poin P1 terkini : %d\n",*poinP1);
    printarray(*T);
  }else
  {
    printf("tidak bisa dipindah\n");
  }
  
  printf("\n");
}
void move2(List *L1, List *L2,TabEl *T,int *poinP2){
  /*bidak yang mau dipindah*/
  address P;
  infolist X;
  ListPindah R;
  ListPossible S;
  int pilihan;
  S = pawnavail2(*L1,*L2);
  printf("Bidak yang mungkin pindah\n");
  for (int j = 1; j <= S.PNum; j++)
  {
    printf("%d.",j);
    switch (S.PPawn[j].Infobidak)
      {
      case 'P':
        printf("Pion ");
        break;
      case 'R':
        printf("Benteng ");
        break;
      case 'H':
        printf("Kuda ");
        break;
      case 'B':
        printf("Menteri ");
        break;
      case 'Q':
        printf("Ratu ");
        break;  
      case 'K':
        printf("Raja ");
        break;  
      default:
        break;
      }
    switch (Absis(S.PPawn[j].Lokasi))
      {
      case 1:
        printf("A,");
        break;
      case 2:
        printf("B,");
        break;
      case 3:
        printf("C,");
        break;
      case 4:
        printf("D,");
        break;
      case 5:
        printf("E,");
        break;  
      case 6:
        printf("F,");
        break;  
      case 7:
        printf("G,");
        break;
      case 8:
        printf("H,");
        break;    
      default:
        break;
      }

    printf("%d\n",Ordinat(S.PPawn[j].Lokasi));
  }
  printf("input select :");
  int select1;
  scanf(" %d",&select1);
  while (select1 <1 || select1 > S.PNum) {
    printf("Input tidak valid, masukkan kembali nomor bidak yang anda ingin gerakkan : \n");
    scanf(" %d",&select1);
  }
  X = possiblepawn(S,select1);
  P = Search(*L2,X);
  switch (X.Infobidak)
  {
  case 'P':
    R = getPionMove2(P,L1,L2);
    break;
  case 'R':
    R = getRookMove(P,L2,L1);
    break;
  case 'H':
    R = getHorseMove(P,L2,L1);
    break;
  case 'B':
    R = getBishopMove(P,L2,L1);
    break;
  case 'K':
    R = getKingMove(P,L2,L1);
    break;
  case 'Q':
    R = getQueenMove(P,L2,L1);
    break;
  default:
    printf("notdefined\n");
    break;
  }
  /* print possible moves*/
  if (R.Num!=0)
  {
    printf("Lokasi Mungkin Pindah\n");
    int i = 1;
    while ( i <= R.Num && R.Num!=0)
    {
      printf("%d.",i);
      TulisPOINT(R.Move[i]);
      printf("\n");
      i++;
    }
    printf("Select : ");
    /*pemindahan*/
    int select;
    scanf("%d",&select);
    while (select < 1 || select > R.Num){
          printf("Input tidak valid, masukkan kembali nomor lokasi yang anda inginkan : \n");
          scanf(" %d",&select);
    }
    POINT dest;
    dest = moveselector(R,select);
    if ( X.Infobidak = 'p' && Ordinat(dest) == 1){
      printf("Selamat,pion anda dapat dipromosikan, silahkan pilih transformasi bidak anda : ");
      printf("1.Benteng \n 2.Kuda \n 3.Mentri \n 4.Ratu \n");
      scanf("%d", &pilihan);
      while (pilihan < 1 || pilihan > 4){
        printf("Pilihan yang anda masukkan tidak valid, silahkan pilih kembali ! ");
        scanf("%d",&pilihan);
      }
      if (pilihan == 1) Infobidak(P) = 'R';
      else if (pilihan == 2)  Infobidak(P) = 'H';
      else if (pilihan == 3)  Infobidak(P) = 'B';
      else if (pilihan == 4)  Infobidak(P) = 'Q';
    }
    Lokasi(P) = dest;
    if(SearchEL(*L1,dest))
    {
      switch (SearchbyLocation(*L1,dest))
      {
      case 'p':
        (*poinP2) +=1;
        break;
      case 'r':
        (*poinP2) += 4;
        break;
      case 'h':
        (*poinP2) += 2;
        break;
      case 'b':
        (*poinP2) += 4;
        break;
      case 'q':
        (*poinP2) += 8;
        break;  
      case 'k':
        (*poinP2) += 10;
        break;  
      default:
        break;
      }
      DelPoint(L1,dest);
    }
    
    printf("\n");
    *T = board(*L1,*L2);
    printf("Bidak ");
    switch (Infobidak(P))
      {
      case 'P':
        printf("pion ");
        break;
      case 'R':
        printf("benteng ");
        break;
      case 'H':
        printf("kuda ");
        break;
      case 'B':
        printf("menteri ");
        break;
      case 'Q':
        printf("ratu ");
        break;  
      case 'K':
        printf("raja ");
        break;  
      default:
        break;
      }
    printf("telah pindah dari %d,%d ke %d,%d\n",Absis(X.Lokasi),Ordinat(X.Lokasi),dest.X,dest.Y);
    printf("Poin P2 terkini : %d\n",*poinP2);
    printarray(*T);
  }else
  {
    printf("tidak bisa dipindah\n");
  }
  
  
  printf("\n");
}

boolean isCheck(address P,List *L1, List *L2){
  boolean check=false;
  char c;
  POINT x0=Lokasi(P),x1;
  
  x1 = PlusDelta(x0,0,1);
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='R') check = true;
      }
      x1 = PlusDelta(x1,0,1);
     }
     else break;
  }

  x1 = PlusDelta(x0,0,-1);
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='R') check = true;
      }
      x1 = PlusDelta(x1,0,-1);
     }
     else break;
  }

  x1 = PlusDelta(x0,1,0);
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='R') check = true;
      }
      x1 = PlusDelta(x1,1,0);
     }
     else break;
  }

  x1 = PlusDelta(x0,-1,0);
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='R') check = true;
      }
      x1 = PlusDelta(x1,-1,0);
     }
     else break;
  }

  x1 = PlusDelta(x0,1,1);
  c = SearchbyLocation(*L2,x1);
  if (c=='P') check = true;
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='B') check = true;
      }
      x1 = PlusDelta(x1,1,1);
     }
     else break;
  }

  x1 = PlusDelta(x0,1,-1);
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='B') check = true;
      }
      x1 = PlusDelta(x1,1,-1);
     }
     else break;
  }

  x1 = PlusDelta(x0,-1,1);
  c = SearchbyLocation(*L2,x1);
  if (c=='P') check = true;
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='B') check = true;
      }
      x1 = PlusDelta(x1,-1,1);
     }
     else break;
  }

  x1 = PlusDelta(x0,-1,-1);
  while (IsPointValid(x1) && (!check)){
     if (!SearchEL(*L1,x1) || (SearchEL(*L2,x1))){
      if (SearchEL(*L2,x1)){
        c = SearchbyLocation(*L2,x1);
        if (c=='Q' || c=='B') check = true;
      }
      x1 = PlusDelta(x1,-1,-1);
     }
     else break;
  }

  x1 = PlusDelta(x0,2,1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }

  x1 = PlusDelta(x0,2,-1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }
  x1 = PlusDelta(x0,-2,1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }


  x1 = PlusDelta(x0,-2,-1);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }

  x1 = PlusDelta(x0,1,2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }

  x1 = PlusDelta(x0,1,-2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }
  x1 = PlusDelta(x0,-1,2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }
  x1 = PlusDelta(x0,-1,-2);
  if (IsPointValid(x1)) {
    if (!SearchEL(*L1,x1)){
      c = SearchbyLocation(*L2,x1);
      if ( c=='H' ) check = true;
    }
  }
  return check;
}
/*int main(){
  TabEl T;
  List L1,L2;
  int poinP1 =0;
  int poinP2 =0;
  Queue Q1;
  
  initboard(&L1,&L2);
  T = board(L1,L2);
  printarray(T);
  printf("\n");
  inisialisasi_Urutan(&Q1);
  while (!(IsEmptyQueue(Q1))){
        if(InfoHead(Q1) == '1'){
            printf("Giliran Player 1 untuk memindahkan bidaknya !\n");
            move(&L1,&L2,&T,&poinP1);
        } else {
            printf("Giliran Player 2 untuk memindahkan bidaknya !\n");
            move2(&L1,&L2,&T,&poinP2);
        }
        Del(&Q1,&InfoHead(Q1));
  }
  ShowSpecialMove(&L1,&L2,&T);

  return 0;
}*/
