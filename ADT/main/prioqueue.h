/* File : prioqueue.h */
/* Representasi priority queue dengan list berkait dengan first (HEAD) sebagai alamat penghapusan elemen */
/* Queue terurut mengecil berdasarkan elemen nMat (nilai matematika) */
/* Jika nMat sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */
#ifndef _PRIOQUEUE_H
#define _PRIOQUEUE_H
#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotypePQ */
typedef struct {
	char nama[4];          /* nama player */
	int score; /* score player */
} infotypePQ;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue *addressPQ;
typedef struct tElmtQueue {
	infotypePQ Info;
	addressPQ Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	addressPQ HEAD;  /* alamat penghapusan */
} PrioQueue;

/* Selektor */
#define HeadPQ(Q) (Q).HEAD
#define InfoHeadPQ(Q) (Q).HEAD->Info
#define NextPQ(P) (P)->Next
#define InfoPQ(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiPQ (addressPQ *P, infotypePQ X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiPQ (addressPQ  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyPQ (PrioQueue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtPQ(PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyPQ(PrioQueue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void AddPQ (PrioQueue * Q, infotypePQ X);
/* Proses: Mengalokasi X dan menambahkan X aw==
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelPQ(PrioQueue * Q, infotypePQ * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif
