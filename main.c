#include <stdio.h>
#include "ADT/aplikasi/board.h"
#include "ADT/aplikasi/externalfile.h"
#include <string.h>

/* written by Muhamad Hudan Widzamil*/
/* 18218003 */
/* Information Systems and Technology ITB 2018 */

int main(){
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
  printf("3. Exit\n");
  printf("Input : ");
  int selection;
  boolean gamestop = false;
  scanf("%d",&selection);
  while (selection<1 || selection>3)
  {
    printf("Input not valid \n");
    printf("Input : ");
    scanf("%d",&selection);
  }
  if (selection ==1)
  {
    TabEl T;
    List L1,L2;
    int poinP1 =0;
    int poinP2 =0;
    Queue Q1;
    char cmdinput[15];
    Stack S;
    char player1[10],player2[10];


    CreateEmptyStack(&S);
    initboard(&L1,&L2);
    T = board(L1,L2);

    printf("\nRunning a new game\n");
    printf("\nMasukkan nama Player 1 : ");
    scanf("%s",player1);
    printf("Masukkan nama Player 2 : ");
    scanf("%s",player2);

    printf("\nKondisi awal papan\n");  
    printarray(T);
    printf("\n");
    inisialisasi_Urutan(&Q1);
    while (!(IsEmptyQueue(Q1))&&!gamestop){
      printf("Masukkan command : ");
      scanf("%s",cmdinput);
      while ((strcmp(cmdinput,"MOVE")!=0)&&(strcmp(cmdinput,"SPECIAL_MOVE")!=0)&&(strcmp(cmdinput,"UNDO")!=0))
      {
        printf("Available command: MOVE/SPECIAL_MOVE/UNDO\n");
        printf("Command salah, masukkan lagi : ");
        scanf("%s",cmdinput);
      }
      
      if (strcmp(cmdinput,"MOVE")==0)
      {
        infostack inputstack;
        inputstack.Poin1 = poinP1;
        inputstack.Poin2 = poinP2;
        inputstack.T = T;
        Push(&S,inputstack);
        if(InfoHead(Q1) == '1'){
            printf("Giliran Player 1 untuk memindahkan bidaknya !\n");
            move(&L1,&L2,&T,&poinP1);
            if (!SearchBidak(L1,'k')||!SearchBidak(L2,'K'))
            {
              gamestop = true;
            }
            if (IsCheckMate(SearchKing(L2),&L2,&L1))
            {
              printf("Skakmat\n");
              poinP1+=20;
              gamestop = true;
            }
            
        } else { /*(InfoHead(Q1) == '2')*/
            printf("Giliran Player 2 untuk memindahkan bidaknya !\n");
            move2(&L1,&L2,&T,&poinP2);
            if (!SearchBidak(L1,'k')||!SearchBidak(L2,'K'))
            {
              gamestop = true;
            }
            if (IsCheckMate(SearchKing(L1),&L1,&L2))
            {
              printf("Skakmat\n");
              poinP2+=20;
              gamestop = true;
            }
          
        }
        Del(&Q1,&InfoHead(Q1));
      } else if (strcmp(cmdinput,"SPECIAL_MOVE")==0)
      {
        infostack inputstack;
        inputstack.Poin1 = poinP1;
        inputstack.Poin2 = poinP2;
        inputstack.T = T;
        Push(&S,inputstack);
        if(InfoHead(Q1) == '1'){
            printf("Giliran Player 1 untuk memindahkan bidaknya !\n");
            ShowSpecialMove(&L1,&L2,&T);
            if (!SearchBidak(L1,'k')||!SearchBidak(L2,'K'))
            {
              gamestop = true;
            }
            
      
            
        } else { /*(InfoHead(Q1) == '2')*/
            printf("Giliran Player 2 untuk memindahkan bidaknya !\n");
            ShowSpecialMove2(&L1,&L2,&T);
            if (!SearchBidak(L1,'k')||!SearchBidak(L2,'K'))
            {
              gamestop = true;
            }
        }
        Del(&Q1,&InfoHead(Q1));
      }else /*UNDO*/
      {
        if (IsEmptyStack((S))||S.TOP == 1){
        printf("Perintah Undo belum dapat dijalankan.\n");
        }else
        {
          
            infostack outputstack;
            Pop(&S,&outputstack);
            T = outputstack.T;
            poinP1 = outputstack.Poin1;
            poinP2 = outputstack.Poin2;
            Pop(&S,&outputstack);
            T = outputstack.T;
            poinP1 = outputstack.Poin1;
            poinP2 = outputstack.Poin2;
            TabToList(T,&L1,&L2);
            if (InfoHead(Q1) == '1')
            {
              Add(&Q1,'1');
              Add(&Q1,'2');
            }else
            {
              Add(&Q1,'2');
              Add(&Q1,'1');
            }
          }
          printarray(T);          
        
        
      } 
    }
    printf("Game telah berakhir\n");
    printf("Poin Player 1 (%s) : %d\n",player1,poinP1);
    printf("Poin Player 2 (%s) : %d\n",player2,poinP2);
    addtolb(player1,poinP1);
    addtolb(player2,poinP2);
    main();   /*balik lagi ke awal*/

  }else if (selection==2)
  {
    printlb();
    main();   /*balik lagi ke awal*/
  }else
  {
    printf("Thank you for playing\n© CGI 2019\n");
    return 0;
  }
}
