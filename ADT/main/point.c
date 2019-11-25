#include <stdio.h>
#include "point.h"
#include <math.h>

POINT MakePOINT (int X, int Y){
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void BacaPOINT (POINT *P){
    scanf("%d %d",&P->X,&P->Y);
}

void TulisPOINT (POINT P){
    printf("(%d,%d)",Absis(P),Ordinat(P));
}
boolean IsPointValid (POINT P){
  return Absis(P)>0 && Absis(P)<=8 && Ordinat(P)>0 && Ordinat(P)<=8;
}
boolean EQ (POINT P1, POINT P2){
    return (Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2));
}

POINT PlusDelta (POINT P, int deltaX, int deltaY){
    Absis(P)+=deltaX;
    Ordinat(P)+=deltaY;
    return P;
}
