/*File      : stacklist.c
  NIM/Nama  : 18218003/Muhamad Hudan Widzamil
  Tanggal   : 31 Oktober 2019
  Topik     : Variasi List */

#include "stacklist.h"
#include <stdio.h>

/* Prototype manajemen memori */
void AlokasiStack (saddress *P, infostack X)
/* I.S. Sembarang */
/* F.S. Alamat P diAlokasiStack, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika AlokasiStack gagal */
{
  (*P) = (ElmtStack*)malloc(sizeof(ElmtStack));
  if (*P!=Nil) {
    InfoStack(*P)=X;
    NextStack(*P)=Nil;
  }
}
void DeAlokasiStack (saddress P)
/* I.S. P adalah hasil AlokasiStack, P != Nil */
/* F.S. Alamat P dideAlokasiStack, dikembalikan ke sistem */
{
  free(P);
}
/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
  return Top(S)==Nil;
}
void CreateEmptyStack (Stack * S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
{
  Top(*S)=Nil;
}
void Push (Stack * S, infostack X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika AlokasiStack X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
  saddress P;
	AlokasiStack(&P,X);
	if (P!=Nil) {
		NextStack(P)= Top(*S);
    Top(*S)= P;
	}
}
void Pop (Stack * S, infostack * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama dideAlokasiStack */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
  saddress P;
	P = Top(*S);
  Top(*S) = NextStack(Top(*S));
  NextStack(P)=Nil;
	(*X) = InfoStack(P);
	DeAlokasiStack(P);
}

int NbElmtStack (Stack S)
{
  saddress P;
  int count = 0;
  P = Top(S);
  while (!IsEmptyStack && P != Nil){
      count++;
      P = NextStack(P); 
  } return count;
}
