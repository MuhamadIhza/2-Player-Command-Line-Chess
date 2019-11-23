/* File : listlinier.h */
/* NIM / Nama : 18218003 / Muhamad Hudan Widzamil
	Tanggal 		: 23 Oktober 2019
	Topik 			: ADT List */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infolist adalah integer */
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong */
{
	return First(L)==Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L)=Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infolist X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	P = (address) malloc(sizeof(infolist));
	if (P!=Nil) {
		Infobidak(P)=X.Infobidak;
		Lokasi(P)=X.Lokasi;
		Next(P)=Nil;
	}
	return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infolist X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
	P = First(L);
	boolean found = false;
	while ((P!=Nil)&&(!found)) {
		if (Absis(X.Lokasi) == Absis(Lokasi(P))&&Ordinat(X.Lokasi) == Ordinat(Lokasi(P)) && X.Infobidak==Infobidak(P)) {
			found = true;
		} else {
			P = Next(P);
		}
	}
	return P;
}

boolean SearchEL (List L, POINT X){
	address P;
	P = First(L);
	boolean found = false;
	while ((P!=Nil)&&(!found)) {
		if (Absis(X) == Absis(Lokasi(P)) && Ordinat(X) == Ordinat(Lokasi(P))) {
			found = true;
		} else {
			P = Next(P);
		}
	}
	return found;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P;
	P = Alokasi(X);
	if (P!=Nil) {
		InsertFirst(L,P);
	}
}
void InsVLast (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P;
	P = Alokasi(X);
	if (P!=Nil) {
		InsertLast(L,P);
	}
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infolist *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	DelFirst(L,&P);
	(*X).Infobidak = Infobidak(P);
	(*X).Lokasi = Lokasi(P);
	Dealokasi(&P);
}
void DelVLast (List *L, infolist *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;
	DelLast(L,&P);
	(*X).Infobidak = Infobidak(P);
	(*X).Lokasi = Lokasi(P);
	Dealokasi(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P)= First(*L);
	First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	address Px=Next(Prec);
	Next(Prec) = P;
	Next(P)=Px;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmptyList(*L)) {
		InsertFirst(L,P);
	} else {
		address Last;
		Last = First(*L);
		while (Next(Last)!=Nil) {
			Last = Next(Last);
		InsertAfter(L,P,Last);
		}
	}
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L)= Next(First(*L));
	Next(*P)=Nil;
}
void DelP (List *L, infolist X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	if (!IsEmptyList(*L)) {
		address P,Prec;
		boolean found = false;
		P = First(*L);
		while (!found) {
			if (Infobidak(P)==X.Infobidak && Absis(Lokasi(P))==Absis(X.Lokasi)&& Ordinat(Lokasi(P))==Ordinat(X.Lokasi)) {
				found = true;
			} else {
				Prec = P;
				P = Next(P);
			}

		}
		if (P == First(*L)) {
				DelFirst(L,&P);
				Dealokasi(&P);
		}else if (P!=Nil) {
			DelAfter(L,&P,Prec);
			Dealokasi(&P);
		}
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	address Last, Prec;
	Last = First(*L);
	Prec = Nil;
	while (Next(Last)!=Nil) {
		Prec = Last;
		Last = Next(Last);
	}
	*P = Last;
	if (Prec==Nil) {
		First(*L)= Nil;
	} else {
		Next(Prec)= Nil;
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel)= Nil;
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	address P = First(L);
	if (! IsEmptyList(L)) {
		printf("%c",Infobidak(P));
		P = Next(P);
	}
	while(P!=Nil) {
		printf(",%c",Infobidak(P));
		P = Next(P);
	}
	printf("]");
}
void PrintBoard (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = First(L);
	for (int i = 1; i <= 8; i++)
	{
		printf(" %d ",i);
	}
	printf("\n");

	int count = 1;
	while(P!=Nil) {
		if (Infobidak(P) != '_')
		{
			printf("|%c|",Infobidak(P));
		}else
		{
			printf("| |");
		}
		if(count%8==0){
			printf("\n");
		}
		count++;
		P = Next(P);
	}
	for (int i = 1; i <= 8; i++)
	{
		printf(" %d ",i);
	}
	printf("\n");
}
int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	int num = 0;
	address P = First(L);
	while (P!=Nil) {
		num++;
		P = Next(P);
	}
	return num;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	address Last;
	if (IsEmptyList(*L1)) {
		First(*L3)=First(*L2);
		CreateEmptyList(L2);
	} else {
		First(*L3)=First(*L1);
		Last = First(*L1);
		while (Next(Last)!=Nil) {
			Last = Next(Last);
		}
		Next(Last) = First(*L2);
		CreateEmptyList(L1);
		CreateEmptyList(L2);
	}
}
