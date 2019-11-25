#include <stdio.h>
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    (*S).TOP = 0;
}


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    return (S.TOP == 0);
}

bool IsFullStack(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return (S.TOP == MaxEl);
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infostack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    (*S).TOP+=1;
    (*S).T[(*S).TOP-1]=X;
}
void Pop (Stack *S, infostack *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = (*S).T[(*S).TOP-1];
    (*S).TOP-=1;
}
