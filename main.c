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
  printf("2. Leaderboard\n");
  scanf("%d",&selection);

}
