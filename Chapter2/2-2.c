/*
    구구단의 단을 입력받아 그 단의 전체를 출력하는 프로그램을 작성하라.
    출력은 다음과 같이 하되, 반복문(for, while)은 사용하지 말고 printf문을 여러개를 이용하여 나타내라.
*/
#include "stdio.h"
int main(void){
  int num;
  printf("단을 입력하세요 : ");
  scanf("%d", &num);
  printf("\n%d * 1 = %d", num, num*1);
  printf("\n%d * 2 = %d", num, num*2);
  printf("\n%d * 3 = %d", num, num*3);
  printf("\n%d * 4 = %d", num, num*4);
  printf("\n%d * 5 = %d", num, num*5);
  printf("\n%d * 6 = %d", num, num*6);
  printf("\n%d * 7 = %d", num, num*7);
  printf("\n%d * 8 = %d", num, num*8);
  printf("\n%d * 9 = %d", num, num*9);
  return 0;
}
