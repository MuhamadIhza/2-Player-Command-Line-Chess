#include <stdio.h>
#include "listlinier.h"

#define   PAWN    0
#define   KNIGHT  1
#define   BISHOP  2
#define   ROOK    3
#define   QUEEN   4
#define   KING    5
#define   EMPTY   6

/* written by Ichsan Sholeh Abdurrahim*/
/* 18218026 */
/* Information Systems and Technology ITB 2018 */

void position();

void position(){
    List bidak;
    CreateEmpty(&bidak);
    InsVFirst(&bidak,'R');
    InsVFirst(&bidak,'H');
    InsVFirst(&bidak,'B');
    InsVFirst(&bidak,'Q');
    InsVFirst(&bidak,'K');
    InsVFirst(&bidak,'B');
    InsVFirst(&bidak,'H');
    InsVFirst(&bidak,'R');
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(&bidak,'P');
    }
    for (int i = 1; i <= 32; i++)
    {
        InsVFirst(&bidak,'_');
    }
    for (int i = 1; i <= 8; i++)
    {
        InsVFirst(&bidak,'p');
    }
    InsVFirst(&bidak,'r');
    InsVFirst(&bidak,'h');
    InsVFirst(&bidak,'b');
    InsVFirst(&bidak,'q');
    InsVFirst(&bidak,'k');
    InsVFirst(&bidak,'b');
    InsVFirst(&bidak,'h');
    InsVFirst(&bidak,'r');
    PrintBoard(bidak);
    printf("\n");
}