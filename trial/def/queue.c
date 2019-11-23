#include <stdio.h>
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q)==NilQueue && Tail(Q)==NilQueue);
}
boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q)==MaxElQueue(Q));
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (Head(Q)==NilQueue && Tail(Q)==NilQueue) return 0;
    else return (((Tail(Q)-Head(Q))%MaxElQueue(Q))+1);
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    Head(*Q)=NilQueue;
    Tail(*Q)=NilQueue;
    MaxElQueue(*Q)=Max;
    (*Q).T = (infotypequeue *) malloc ((Max+1)*sizeof(infotypequeue));
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxElQueue(*Q)=NilQueue;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotypequeue X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if(IsEmptyQueue(*Q)) {
        Head(*Q)=NilQueue+1;
        Tail(*Q)=NilQueue+1;
        InfoTail(*Q)=X;
    } else {
        Tail(*Q)=(Tail(*Q) % MaxElQueue(*Q)) + 1;
        InfoTail(*Q)=X;
    }
}
void Del (Queue * Q, infotypequeue * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    if (Head(*Q)==Tail(*Q)) {
        *X=InfoHead(*Q);
        Head(*Q)=NilQueue;
        Tail(*Q)=NilQueue;
    } else {
        *X=InfoHead(*Q);
        Head(*Q)=(Head(*Q) % MaxElQueue(*Q)) + 1;
    }
}