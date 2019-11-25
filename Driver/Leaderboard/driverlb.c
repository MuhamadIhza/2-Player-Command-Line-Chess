/*Driver untuk modul Leaderboard*/

#include <stdio.h>
#include "externalfile.h"

int main(){
    char c[4],s[4];

    printf("masukkan nama : ");
    scanf("%s",c);
    printf("masukkan score : ");
    scanf("%s",s);

    addtolb(c,toint(s));

    printlb();

    main();
}

// gcc -o driverlb driverlb.c externalfile.c mesin_kata.c mesin_kar.c prioqueue.c