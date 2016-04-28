/*
    다음 프로그램에는 오류가 존재한다. 컴파일 및 실행 시 올바른 결과가 나오도록 프로그램을 수정하여라.
    
    #include "stdio.h"
    int main(void){
        printf("Input a number : ");
        scanf("%d", num);
        printf("Result : %d", num);
        return 0;
    }
*/
#include "stdio.h"
int main(void){
  int num;
  printf("Input a number : ");
  scanf("%d", &num);
  printf("Result : %d", num);
  return 0;
}
