#include "prioqueue.h"
#include "boolean.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Prototype manajemen memori */
void AlokasiPQ (addressPQ *P, infotypePQ X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoPQ(P)=X dan NextPQ(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P=(addressPQ) malloc (sizeof(infotypePQ));
    if (*P!=Nil){
        InfoPQ(*P).score=X.score;
        int i=0;
        while(X.nama[i]!='\0'){
            InfoPQ(*P).nama[i]=X.nama[i];
            i++;
        }
        InfoPQ(*P).nama[3]='\0';
        NextPQ(*P)=Nil;
    } else *P = Nil;
}
void DealokasiPQ (addressPQ  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free (P);
}
boolean IsEmptyPQ (PrioQueue Q)
/* Mengirim true jika Q kosong: HEADPQ(Q)=Nil and TAIL(Q)=Nil */
{
    return (HeadPQ(Q)==Nil);
}
int NbElmtPQ(PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
{
    int count=0;
    if(!IsEmptyPQ(Q)){
        addressPQ P=HeadPQ(Q);
        count++;
        while(NextPQ(P)!=Nil){
            count++;
            P=NextPQ(P);
        }
    }
    return count;
}
void CreateEmptyPQ(PrioQueue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
{
    HeadPQ(*Q)=Nil;
}
void AddPQ (PrioQueue * Q, infotypePQ X)
/* Proses: Mengalokasi X dan menambahkan X
   jika alokasi berhasil; jika alokasi gagal Q tetap
   sesuai urutan score dan abjad
   memperbarui score bila terdapat nama yang sama */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    addressPQ P,CurrP,PrevP;
    int sec;

    AlokasiPQ(&P,X);
    if (P!=Nil){
        if(IsEmptyPQ(*Q)) HeadPQ(*Q)=P;
        else { // !IsEmpty(*Q)
            CurrP=HeadPQ(*Q);
            PrevP = CurrP;
            int i=0;
            
            if ( InfoPQ(CurrP).score < InfoPQ(P).score ){   // case input score terbesar
                NextPQ(P)=HeadPQ(*Q);
                HeadPQ(*Q)=P;
                PrevP=P;
                CurrP=NextPQ(P);

            } else { // !( InfoPQ(CurrP).score < InfoPQ(P).score )      // case input bukan score terbesar
                while ( InfoPQ(CurrP).score > InfoPQ(P).score && NextPQ(CurrP)!=Nil && (strcmp(InfoPQ(P).nama,InfoPQ(PrevP).nama)!=0)){
                    PrevP=CurrP;
                    CurrP=NextPQ(CurrP);
                }
                i=0;
                while (( InfoPQ(CurrP).score == InfoPQ(P).score) && (NextPQ(CurrP)!=Nil) && (strcmp(InfoPQ(P).nama,InfoPQ(CurrP).nama)>0) ){  // case memiliki score yang sama
                    PrevP=CurrP;
                    CurrP=NextPQ(CurrP);
                }
                if (strcmp(InfoPQ(P).nama,InfoPQ(CurrP).nama)==0 ) {
                    if ( InfoPQ(CurrP).score > InfoPQ(P).score ) DealokasiPQ(P);  // Mengabaikan data nama yang sama dengan score yang lebih kecil
                    else /* !( InfoPQ(CurrP).score > InfoPQ(P).score ) */ InfoPQ(CurrP).score=InfoPQ(P).score;
                }
                else if ( NextPQ(CurrP)==Nil && InfoPQ(CurrP).score > InfoPQ(P).score ) NextPQ(CurrP) = P;
                else { /* !( NextPQ(CurrP)==Nil && InfoPQ(CurrP).score > InfoPQ(P).score ) */
                    NextPQ(PrevP)=P;
                    NextPQ(P)=CurrP;
                    PrevP=P;
                }
            }
            while ( NextPQ(CurrP)!=Nil ){
                if (strcmp(InfoPQ(P).nama,InfoPQ(CurrP).nama)==0) {     // Menghapus nama yang sama dengan score yang lebih kecil
                    NextPQ(PrevP)=NextPQ(CurrP);
                    DealokasiPQ(CurrP);
                    break;
                }
                PrevP=CurrP;
                CurrP=NextPQ(CurrP);
            }            
        }
    }
}
void DelPQ(PrioQueue * Q, infotypePQ * X)
/* Proses: Menghapus X pada bagian HEADPQ dari Q dan mendealokasi elemen HEADPQ */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEADPQ pd I.S., HEADPQ "mundur" */
{
    addressPQ P=HeadPQ(*Q);
    *X=InfoPQ(P);
    if(NextPQ(P)==Nil) CreateEmptyPQ(Q);
    else HeadPQ(*Q)=NextPQ(P);
    DealokasiPQ(P);
}

// int main(){
//     PrioQueue Q;
//     infotypePQ X,Y;
//     char c[4]="iza",d[4]="uwu",e[4]="hmm";

//     CreateEmptyPQ(&Q);
//     strcpy(X.nama,c);
//     X.score=20;
//     AddPQ(&Q,X);
//     strcpy(X.nama,d);
//     X.score=9;
//     AddPQ(&Q,X);
//     strcpy(X.nama,e);
//     X.score=90;
//     AddPQ(&Q,X);

//     DelPQ(&Q,&Y);
//     printf("%s %d\n",Y.nama,Y.score);
//     DelPQ(&Q,&Y);
//     printf("%s %d\n",Y.nama,Y.score);
//     DelPQ(&Q,&Y);
//     printf("%s %d\n",Y.nama,Y.score);
// }
