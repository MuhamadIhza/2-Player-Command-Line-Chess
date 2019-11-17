#include <stdio.h>
#include "leaderboard.h"

char filename[63],*pemain,*sscore;
int score;
static FILE *file;

void addtolb(char* pemain,int score){
    file = fopen("../../Data/Leaderboard.csv", "a");
    fprintf(file, "%s %d\n",pemain,score);
}

void printlb(){
    PrioQueue Q;
    infotype X;

    STARTKATA("../../Data/Leaderboard.csv");

    while (CC!=EOF) {
        X.nama = CKata.TabKata;
        ADVKATA();
        X.score = toint(CKata.TabKata);
        ADVKATA();
        Add(&Q,X);
        printf("%s\n",InfoHead(Q).nama);
    }

    printf("+-----------------------------------------------------+\n");
    printf("|                   Leaderboard                       |\n");
<<<<<<< HEAD
    printf("-------------------------------------------------------\n\n");
    int i=1;
    while (!IsEmpty(Q)){
        Del(&Q,&X);
        printf(" %d | \t %d \t %s \n", i, X.score, X.nama);
=======
    printf("+-----------------------------------------------------+\n\n");
    for (int i=0;i<=Q.MaxEl;i++){
        printf("\t %d | \t %d \t %s \n", i, Q.T[i].prio, Q.T[i].info);
>>>>>>> b6c27f2fa2acbab843c4bbb985354cea1e9e0aaa
    }
    printf("_______________________________________________________\n\n");


}

int toint(char* x){
    int nilai=0;
    
    int i=0;
    while(x[i]!='\0'){
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