#include "point.h"
#include <stdio.h>

int main(){
    POINT P;
    BacaPOINT(&P);
    while (!IsPointValid(P))
    {
        printf("Masukan tidak valid, valid hanya 1..8\n");
        BacaPOINT(&P);
    }
    TulisPOINT(P);
    POINT R;
    R = MakePOINT(4,3);
    if (EQ(P,R))
    {
        R = PlusDelta(R,2,3);
    }
    TulisPOINT(R);
    


    return 0;
}