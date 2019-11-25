
#ifndef stack_H
#define stack_H

/* MODUL STACK
Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik
dan ukuran sama
TOP adalah alamat elemen puncak*/

#include "../def/point.h"
#include "../def/array.h"
#define false 0
#define true 1
//#define Nil 0
#define MaxEl 200

typedef int bool;
typedef TabEl infostack;
typedef int saddress;
typedef struct {
    infostack T[MaxEl];
    saddress TOP;
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
bool IsFullStack(Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infostack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop (Stack *S, infostack *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


#endif
