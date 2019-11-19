#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q)==Nil && Tail(Q)==Nil);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q)==MaxEl(Q));
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (Head(Q)==Nil && Tail(Q)==Nil) return 0;
    else return (((Tail(Q)-Head(Q))%MaxEl(Q))+1);
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
    MaxEl(*Q)=Max;
    (*Q).T = (infotype *) malloc ((Max+1)*sizeof(infotype));
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q)=Nil;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    int field,banding;

    if(IsEmpty(*Q)) {
        Head(*Q)=Nil+1;
        Tail(*Q)=Nil+1;
        InfoTail(*Q)=X;
    } else {
        Tail(*Q)=(Tail(*Q) % MaxEl(*Q)) + 1;
        field=Tail(*Q);
        banding=((field+MaxEl(*Q)-2) % MaxEl(*Q)) + 1;
        while( ((*Q).T[banding].prio < X.prio) && (field!=Head(*Q)) ){
            (*Q).T[field]=(*Q).T[banding];
            field=banding;
            banding=((field+MaxEl(*Q)-2) % MaxEl(*Q)) + 1;
        }
        (*Q).T[field]=X;
    }
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    if (Head(*Q)==Tail(*Q)) {
        *X=InfoHead(*Q);
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    } else {
        *X=InfoHead(*Q);
        Head(*Q)=(Head(*Q) % MaxEl(*Q)) + 1;
    }
}

void PrintQueue (Queue Q) {
    infotype X;
    
    while(!IsEmpty(Q)){
        Del(&Q,&X);
        printf("%d %d\n",X.prio,X.info);
    }
    printf("#\n");
}