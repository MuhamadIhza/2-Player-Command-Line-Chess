#include "prioqueue.h"
#include "boolean.h"
#include <stdlib.h>
#include <string.h>

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P=(address) malloc (sizeof(infotype));
    if (*P!=Nil){
        Info(*P).score=X.score;
        int i=0;
        while(X.nama[i]!='\0'){
            Info(*P).nama[i]=X.nama[i];
            i++;
        }
        Info(*P).nama[3]='\0';
        Next(*P)=Nil;
    } else *P = Nil;
}
void Dealokasi (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free (P);
}
boolean IsEmpty (PrioQueue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return (Head(Q)==Nil);
}
int NbElmt(PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
{
    int count=0;
    if(!IsEmpty(Q)){
        address P=Head(Q);
        count++;
        while(Next(P)!=Nil){
            count++;
            P=Next(P);
        }
    }
    return count;
}
void CreateEmpty(PrioQueue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
{
    Head(*Q)=Nil;
}
void Add (PrioQueue * Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X aw==
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    address P,CurrP,PrevP;
    int sec;

    Alokasi(&P,X);
    if (P!=Nil){
        if(IsEmpty(*Q)) Head(*Q)=P;
        else {
            CurrP=Head(*Q);
            PrevP = CurrP;
            int i=0;
            
            if ( Info(CurrP).score < Info(P).score ){
                Next(P)=Head(*Q);
                Head(*Q)=P;
                PrevP=P;
                CurrP=Next(P);

            } else {
                while ( Info(CurrP).score > Info(P).score && Next(CurrP)!=Nil && (strcmp(Info(P).nama,Info(PrevP).nama)!=0)){
                    PrevP=CurrP;
                    CurrP=Next(CurrP);
                }
                i=0;
                while (( Info(CurrP).score == Info(P).score) && (Next(CurrP)!=Nil) && (strcmp(Info(P).nama,Info(CurrP).nama)>0) ){
                    PrevP=CurrP;
                    CurrP=Next(CurrP);
                }
                if (strcmp(Info(P).nama,Info(CurrP).nama)==0 ) {
                    if ( Info(CurrP).score > Info(P).score ) Dealokasi(P);
                    else Info(CurrP).score=Info(P).score;
                }
                else if ( Next(CurrP)==Nil && Info(CurrP).score > Info(P).score ) Next(CurrP) = P;
                else {
                    Next(PrevP)=P;
                    Next(P)=CurrP;
                    PrevP=P;
                }
            }
            while ( Next(CurrP)!=Nil ){
                if (strcmp(Info(P).nama,Info(CurrP).nama)==0) {
                    Next(PrevP)=Next(CurrP);
                    Dealokasi(CurrP);
                    break;
                }
                PrevP=CurrP;
                CurrP=Next(CurrP);
            }            
        }
    }
}
void Del(PrioQueue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    address P=Head(*Q);
    *X=Info(P);
    if(Next(P)==Nil) CreateEmpty(Q);
    else Head(*Q)=Next(P);
    Dealokasi(P);
}

