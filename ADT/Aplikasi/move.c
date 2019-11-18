#include "../Main/stacklist.h"
#include "board.h"

Stack getPionMove(POINT x0);
Stack getHorseMove(POINT x0);


Stack getPionMove(POINT x0){
  Stack S;
  CreateEmpty(&S);
  POINT x1;
  x1 = PlusDelta(x0,0,1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  return S;
}

Stack getHorseMove(POINT x0){
  Stack S;
  CreateEmpty(&S);
  POINT x1;
  x1 = PlusDelta(x0,2,1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,2,-1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,-2,1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  x1 = PlusDelta(x0,-2,-1);
  if (IsPointValid(x1)) {
    Push(&S,x1);
  }
  return S;
}
