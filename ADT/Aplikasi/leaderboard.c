#include <stdio.h>
#include "leaderboard.h"

char filename[63],*pemain,*sscore;
int score;
static FILE *file;

void addtolb(char* pemain,int score){
    file = fopen("../../Data/Leaderboard.csv", "a");
    fprintf(file, "%s,%d\n",pemain,score);
}

void printlb(){
    Queue Q;
    infotype X;

    STARTKATA("../../Data/Leaderboard.csv");
    CreateEmpty(&Q,1);
    while (CC!='\0'){
        X.info = CKata.TabKata;
        ADVKATA();
        X.prio = toint(CKata.TabKata);
        ADVKATA;
        Add(&Q,X);
        Q.MaxEl++;
    }

    printf("-------------------------------------------------------\n");
    printf("|                   Leaderboard                       |\n");
    printf("-------------------------------------------------------\n\n");
    for (int i=0;i<=Q.MaxEl;i++){
        printf("\t %d | \t %d \t %s \n", i, Q.T[i].prio, Q.T[i].info);
    }
    printf("_______________________________________________________\n\n");


}

int toint(char* x){
    char c;
    int nilai=0;
    
    c=GetCC();
    while(CC!='\0'){
        switch (CC)
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
    }
    return nilai;
}