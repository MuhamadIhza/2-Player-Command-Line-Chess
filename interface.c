#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "../Main/listlinier.h"


int kotak[8][8];

void papan_awal(ElmtList bidak)
{
    
}



void awal(int x1,int y1)
{
    int a,b;
    printf("Koordinat awal kuda adalah : %d,%d\n",(x1+1),(y1+1));
    printf("y  1   2   3   4   5   6   7   8   x\n");
    printf("   --- --- --- --- --- --- --- ---\n");    
    for(a=14;a>=0;a--)
    {
        if(a%2==1) printf("   --- --- --- --- --- --- --- ---\n");
        else{
            printf("%d ",(a+2)/2);
            for(b=0;b<=7;b++){
                printf("|");
                if(kotak[b][a/2]==1 && b==x1 && a/2==y1) printf(" o ");
                else printf("   ");
        }
            printf("|\n");
        }
    }
    printf("   --- --- --- --- --- --- --- ---\n");
    printf("\n");
    getch();
}

void sekarang(int x1,int y1)
{
int a,b;
//system("cls");
    printf("Koordinat kuda sekarang adalah : %d,%d\n",(x1+1),(y1+1));
    printf("y  1   2   3   4   5   6   7   8   x\n");
    printf("   --- --- --- --- --- --- --- ---\n");
    for(a=14;a>=0;a--){
        if(a%2==1) printf("   --- --- --- --- --- --- --- ---\n");
        else{
            printf("%d ",(a+2)/2);
            for(b=0;b<=7;b++){
                printf("|");
                if(kotak[b][a/2]==1 && b==x1 && a/2==y1) printf(" o ");
                else
                    if(kotak[b][a/2]==1) printf(" x ");
                    else printf("   "); }
            printf("|\n");
            }
        }
    printf("   --- --- --- --- --- --- --- ---\n");
    printf("\n");
    getch();
}


int main(void)
{
int x,y,x0,y0;
printf("Masukkan koordinat x awal kuda : ");
scanf("%d",&x);
printf("Masukkan koordinat y awal kuda : ");
scanf("%d",&y);
x0=x-1;
y0=y-1;
kotak[x0][y0]=1;
awal(x0,y0);
getch();
}

