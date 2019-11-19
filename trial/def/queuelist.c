/*File      : queuelist.c
  NIM/Nama  : 18218003/Muhamad Hudan Widzamil
  Tanggal   : 31 Oktober 2019
  Topik     : Variasi List */

#include "queuelist.h"
#include <stdio.h>

/* Prototype manajemen memori */
void AlokasiQueue (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P diAlokasiQueue, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika AlokasiQueue gagal */
{
  (*P) = (ElmtQueue*)malloc(sizeof(ElmtQueue));
  if ((*P)!=Nil) {
    Info(*P)=X;
    Next(*P)=Nil;
  }
}
void DeAlokasiQueue (address P)
/* I.S. P adalah hasil AlokasiQueue, P != Nil */
/* F.S. Alamat P dideAlokasiQueue, dikembalikan ke sistem */
{
  free(P);
}
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
  return (Head(Q)==Nil) && (Tail(Q)==Nil);
}
int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
  int num = 0;
	address P = Head(Q);
	while (P!=Nil) {
		num++;
		P = Next(P);
	}
	return num;
}
/*** Kreator ***/
void CreateEmpty(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
  Head(*Q)=Nil;
  Tail(*Q)=Nil;
}
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X)
/* Proses: MengAlokasiQueue X dan menambahkan X pada bagian TAIL dari Q
   jika AlokasiQueue berhasil; jika AlokasiQueue gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
  address P;
  AlokasiQueue(&P,X);
  if (P!=Nil) {
    if (IsEmpty(*Q)) {
      Head(*Q) = P;
    } else {
      Next(Tail(*Q)) = P;
    }
    Tail(*Q) = P;
  }
}
void Del(Queue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendeAlokasiQueue
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
  address P;
  *X = InfoHead(*Q);
  P = Head(*Q);
  Head(*Q) = Next(Head(*Q));
  if (Head(*Q)==Nil) {
    Tail(*Q)= Nil;
  }
  DeAlokasiQueue(P);
}
