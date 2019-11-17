#include "posisiawal.h"
#include <stdio.h>

void inisialisasi_papan(List *L,List *L2){
    CreateEmpty(L);
    CreateEmpty(L2);
    infotype R,H,B,Q,K,B1,H1,R1,P,P1,P2,P3,P4,P5,P6,P7,r,h,b,q,k,b1,h1,r1,p,p1,p2,p3,p4,p5,p6,p7;
    R.X = 0; R.Y = 0; R.Infobidak = 'R';
    H.X = 1; H.Y = 0; H.Infobidak = 'H';
    B.X = 2; B.Y = 0; B.Infobidak = 'B';
    Q.X = 3; Q.Y = 0; Q.Infobidak = 'Q';
    K.X = 4; K.Y = 0; K.Infobidak = 'K';
    B1.X = 5; B1.Y = 0; B1.Infobidak = 'B';
    H1.X = 6; H1.Y = 0; H1.Infobidak = 'H';
    R1.X = 7; R1.Y = 0; R1.Infobidak = 'R';
    P.X = 0; P.Y = 1; P.Infobidak = 'P';
    P1.X = 1; P1.Y = 1; P1.Infobidak = 'P';
    P2.X = 2; P2.Y = 1; P2.Infobidak = 'P';
    P3.X = 3; P3.Y = 1; P3.Infobidak = 'P';
    P4.X = 4; P4.Y = 1; P4.Infobidak = 'P';
    P5.X = 5; P5.Y = 1; P5.Infobidak = 'P';
    P6.X = 6; P6.Y = 1; P6.Infobidak = 'P';
    P7.X = 7; P7.Y = 1; P7.Infobidak = 'P';
    r.X = 0; r.Y = 7; r.Infobidak = 'r';
    h.X = 1; h.Y = 7; h.Infobidak = 'h';
    b.X = 2; b.Y = 7; b.Infobidak = 'b';
    q.X = 3; q.Y = 7; q.Infobidak = 'q';
    k.X = 4; k.Y = 7; k.Infobidak = 'k';
    b1.X = 5; b1.Y = 7; b1.Infobidak = 'b';
    h1.X = 6; h1.Y = 7; h1.Infobidak = 'h';
    r1.X = 7; r1.Y = 7; r1.Infobidak = 'r';
    p.X = 0; p.Y = 6; p.Infobidak = 'p';
    p1.X = 1; p1.Y = 6; p1.Infobidak = 'p';
    p2.X = 2; p2.Y = 6; p2.Infobidak = 'p';
    p3.X = 3; p3.Y = 6; p3.Infobidak = 'p';
    p4.X = 4; p4.Y = 6; p4.Infobidak = 'p';
    p5.X = 5; p5.Y = 6; p5.Infobidak = 'p';
    p6.X = 6; p6.Y = 6; p6.Infobidak = 'p';
    p7.X = 7; p7.Y = 6; p7.Infobidak = 'p';

    InsVFirst(L,P7);
    InsVFirst(L,P6);
    InsVFirst(L,P5);
    InsVFirst(L,P4);
    InsVFirst(L,P3);
    InsVFirst(L,P2);
    InsVFirst(L,P1);
    InsVFirst(L,P);
    InsVFirst(L,R1);
    InsVFirst(L,H1);
    InsVFirst(L,B1);
    InsVFirst(L,K);
    InsVFirst(L,Q);
    InsVFirst(L,B);
    InsVFirst(L,H);
    InsVFirst(L,R);
      
    InsVFirst(L2,r1);
    InsVFirst(L2,h1);
    InsVFirst(L2,b1);
    InsVFirst(L2,k);
    InsVFirst(L2,q);
    InsVFirst(L2,b);
    InsVFirst(L2,h);
    InsVFirst(L2,r);
    InsVFirst(L2,p7);
    InsVFirst(L2,p6);
    InsVFirst(L2,p5);
    InsVFirst(L2,p4);
    InsVFirst(L2,p3);
    InsVFirst(L2,p2);
    InsVFirst(L2,p1);
    InsVFirst(L2,p);   
}

TabInt ListToArr (List L,List L2)
{
    TabInt T;
    address P,P1;
    int i,j;
    infotype kosong;
    inisialisasi_papan(&L,&L2);
    MakeEmpty(&T);
    P = First(L);
    P1 = First(L2);
    i = 0;
    j = 48;
    while (P != Nil){
        SetEl(&T,i,Info(P));
        P = Next(P);
        i += 1;
    }
    for (i=16;i<48;i++){
        SetEl(&T,i,kosong);
    }
    while (P1 != Nil){
        SetEl(&T,j,Info(P1));
        P1 = Next(P1);
        j += 1;
    }
    return T;
}

void PrintArray(TabInt *T)
{
    int i,j,k;
    printf("y   1   2   3   4   5   6   7   8   x\n");
    printf("   --- --- --- --- --- --- --- ---\n");
    k =0;
    for (i =0;i<=14;i++){
        if (i%2 == 1) printf("   --- --- --- --- --- --- --- ---");
        else { 
            printf ("%d ", (i+2)/2);
            for (j=0;j<8;j++){
            printf ("|");
            if ((((i)/2) == (*T).TI[k].y) && (j == (*T).TI[k].x)){
                if (j == 7) printf (" %c |",(*T).TI[k].Isi);
                else printf(" %c ",(*T).TI[k].Isi);}
            else {
                if (j == 7) printf ("   |");
                else printf ("   ");
                } k++;
            }
        }
        printf ("\n");   
    }
    printf("   --- --- --- --- --- --- --- ---\n");
}

int main (){
    int i;
    List bidak1,bidak2;
    TabInt T;
    inisialisasi_papan(&bidak1,&bidak2);
    T = ListToArr(bidak1,bidak2);
    PrintArray(&T);
    PrintInfo(bidak1);
    printf("\n");
    PrintInfo(bidak2);
    printf("\n");
}
