/* File : stacklist.h */
#ifndef _STACKLIST_H
#define _STACKLIST_H

#include "boolean.h"
#include <stdlib.h>

#include "../def/point.h"
/* Konstanta */
#define Nil NULL

/* Deklarasi infostack */
typedef POINT infostack;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack *address;
typedef struct tElmtStack {
  infostack Info;
  address Next;
} ElmtStack;

/* Type stack dengan ciri TOP : */
typedef struct {
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void AlokasiStack (address *P, infostack X);
/* I.S. Sembarang */
/* F.S. Alamat P diAlokasiStack, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika AlokasiStack gagal */
void DeAlokasiStack (address P);
/* I.S. P adalah hasil AlokasiStack, P != Nil */
/* F.S. Alamat P dideAlokasiStack, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyStack (Stack * S);
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infostack X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika AlokasiStack X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infostack * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama dideAlokasiStack */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif
