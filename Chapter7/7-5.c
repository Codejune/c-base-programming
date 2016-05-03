/*
    while 문과 rand() 함수를 사용하여 10개의 무작위 수를 생성하여 출력하는 프로그램을 작성하여라.
*/    
#include "stdio.h"
#include "stdlib.h"
int main(void){
    int i=1;
    while(i<=10){
        printf("%d번째 난수 : %d\n", i, rand());
        i++;
    }
    return 0;
}