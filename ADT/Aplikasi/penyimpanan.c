#include <stdio.h>
#include "penyimpanan.h"

char filename[63];
static FILE *file;

void save(){
    printf(" Masukkan nama file penyimpanan : ");
    scanf("%s",filename);
    file = fopen(filename, "w");
    fprintf(file, "%s");
    
}

void load(){
    printf(" Masukkan nama file penyimpanan : ");
    scanf("%s",filename);
    file = fopen(filename, "r");

}