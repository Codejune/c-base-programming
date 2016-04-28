/*
    다음 이차 방정식의 계수 a, b, c와 x 값을 읽어서 방정식 값을 구하는 프로그램을 작성하여라.
    f(x) = a * x^2 + b * x + c
*/
#include "stdio.h"
int main(void){
  int a, b, c, x;
  printf("Input a, b, and c : ");
  scanf("%d%d%d", &a, &b, &c);
  printf("Input x : ");
  scanf("%d", &x);
  printf("f(%d) = %d", x, a*(x*x)+b*x+c);
  return 0;
}
