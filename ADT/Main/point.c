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

boolean NEQ (POINT P1, POINT P2){
    return !NEQ(P1,P2);
}

boolean IsOrigin (POINT P){
    return (Absis(P)==0)&&(Ordinat(P)==0);
}

boolean IsOnSbX (POINT P){
    return Ordinat(P)==0;
}

boolean IsOnSbY (POINT P){
    return Absis(P)==0;
}

int Kuadran (POINT P){
    int kuadran;
    if (Absis(P)>0){
        if (Ordinat(P)>0){
            kuadran = 1;
        }else
        {
            kuadran = 4;
        }
    }else
    {
        if (Ordinat(P)>0)
        {
            kuadran = 2;
        }else
        {
            kuadran = 3;
        }

    }
    return kuadran;
}

POINT NextX (POINT P){
    ++Absis(P);
    return P;
}

POINT NextY (POINT P){
    ++Ordinat(P);
    return P;
}

POINT PlusDelta (POINT P, int deltaX, int deltaY){
    Absis(P)+=deltaX;
    Ordinat(P)+=deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if (SbX)
    {
        Ordinat(P)= -1 * Ordinat(P);
    }else
    {
        Absis(P)= -1 * Absis(P);
    }

    return P;
}

/*int Jarak0 (POINT P){
    return (int)(sqrt(pow(Absis(P),2)+pow(Ordinat(P),2)));
}

int Panjang (POINT P1, POINT P2){
    return (int)(sqrt(pow(Absis(P1)-Absis(P2),2)+pow(Ordinat(P1)-Ordinat(P2),2)));
}
*/
void Geser (POINT *P, int deltaX, int deltaY){
    (*P).X += deltaX;
    (*P).Y += deltaY;
}

void GeserKeSbX (POINT *P){
    (*P).Y = 0;
}

void GeserKeSbY (POINT *P){
    (*P).X = 0;
}

void Mirror (POINT *P, boolean SbX){
    if (SbX)
    {
      Ordinat(*P)= -1 * Ordinat(*P);
    }else
    {
       Absis(*P)= -1 * Absis(*P);
    }
}
