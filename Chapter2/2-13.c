/*
    다음 프로그램을 실행해보아라
    
    (a) 7을 입력했을 때의 결과
    (b) 100을 입력했을 때의 결과
    (c) 10.23을 입력했을 때의 결과
    (d) 10abc를 입력했을 때의 결과
    (e) a를 입력한 결과
    (f) 위의 결과를 보고 scanf() 함수가 정수를 어떻게 입력받는지 설명하여라.
*/
#include "stdio.h"
int main(void){
  int num;
  printf("숫자를 입력하세요 : ");
  scanf("%d", &num);
  printf("%d의 거듭제곱은 %d 입니다.\n", num, num*num);
  return 0;
}
 