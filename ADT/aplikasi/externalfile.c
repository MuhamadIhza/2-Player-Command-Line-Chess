#include <stdio.h>
#include <string.h>
#include "externalfile.h"

char filename[63],*pemain,*sscore;
int score;
static FILE *file;

void addtolb(char* pemain,int score){
    file = fopen("../../Data/Leaderboard.txt", "a");    
    fprintf(file, "%s,%d\n",pemain,score);              // menuliskan data ke file external leaderboard
}

void printlb(){
    PrioQueue Q;
    infotype X;

    STARTKATA("../../Data/Leaderboard.txt");
    CreateEmpty(&Q);

    while (!EndKata) {
        strcpy(X.nama,CKata.TabKata);       // data nama pemain
        ADVKATA();
        X.score = toint(CKata.TabKata);     // data score pemain
        ADVKATA();
        Add(&Q,X);                          // menambahkan data ke Priority Queue
    }

    printf("+------------------------+\n");
    printf("|       Leaderboard      |\n");
    printf(" ------------------------ \n");
    int i=1;
    printf("|  No\t|  Nama\t Score \t |\n");
    printf(" ------------------------ \n");

    while (!IsEmpty(Q)){
        Del(&Q,&X);
        printf("|  %d \t|  %s \t %d \t |\n", i, X.nama, X.score);      // iterasi print data
        i++;
    }
    printf("+ ---------------------- +\n\n");


}

int toint(char* x){
    int nilai=0;
    
    int i=0;
    while(x[i]!='\0'){              //  iterasi pengubahan menuju angka untuk setiap karakternya
        switch (x[i])
        {
        case '0':
            nilai = nilai*10 + 0;
            break;
        case '1':
            nilai = nilai*10 + 1;
            break;
        case '2':
            nilai = nilai*10 + 2;
            break;
        case '3':
            nilai = nilai*10 + 3;
            break;
        case '4':
            nilai = nilai*10 + 4;
            break;
        case '5':
            nilai = nilai*10 + 5;
            break;
        case '6':
            nilai = nilai*10 + 6;
            break;
        case '7':
            nilai = nilai*10 + 7;
            break;
        case '8':
            nilai = nilai*10 + 8;
            break;
        case '9':
            nilai = nilai*10 + 9;
            break;
        }
        i++;
    }
    return nilai;
}
