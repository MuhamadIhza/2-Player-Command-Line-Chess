#include <stdio.h>
#define   VALUE_PAWN      1
#define   VALUE_KNIGHT    2
#define   VALUE_BISHOP    4
#define   VALUE_ROOK      4
#define   VALUE_QUEEN     8
#define   VALUE_KING      10

#define   MATE            20

/* written by Muhamad Hudan Widzamil*/
/* 18218003 */
/* Information Systems and Technology ITB 2018 */

void main_menu();

int main(){
  main_menu();
  return 0;
}

void main_menu(){
  int selection;
  char username1,username2;
  printf("-------------------------------------------------------\n");
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("-------------------------------------------------------\n\n");
  printf("              ___        ___ _____ _____               \n");
  printf("             |    |___| |___ |___  |___                \n");
  printf("             |___ |   | |___ ____| ____|               \n\n");
  printf("            /////////////////////////////              \n\n");
  printf("                     © CGI 2019                        \n\n");
  printf("-------------------------------------------------------\n");
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("-------------------------------------------------------\n\n");
  printf("Select menu below\n");
  printf("1. New Game\n");
  printf("2. Load Game\n");
  printf("3. Leaderboard\n");
  scanf("%d",&selection);
  if (selection == 1) {
    printf("Masukkan username player 1 : ");
    scanf("%c \n\n",&username1);
    printf("Masukkan username player 2 : ");
    scanf("%c \n",&username2);}
}
