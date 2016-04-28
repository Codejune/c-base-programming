/*
    간단한 산술 계산기 프로그램을 작성하라. 산술꼐산기는 사용자에게 수식을 입력받으면 결과 값을 출력해주는 프로그램이다.
    또한 +, -, *, / 연산이 수행되어야 한다.
*/
#include "stdio.h"
int main(void){
    int a, b;
    char sign;
    
    printf("수식을 입력하세요(ex 2+4) : ");
    scanf("%d%c%d", &a, &sign, &a);
    
    if(sign=='+') {
        printf("%d + %d = %d", a, b, a+b);
    } else if(sign=='-') {
        printf("%d - %d = %d", a, b, a-b);
    } else if(sign=='*') {
        printf("%d * %d = %d", a, b, a*b);
    } else if(sign=='/') {
        printf("%d / %d = %d", a, b, a/b);
    } else {
        printf("수식을 다시 입력해주세요.");
    }
    return 0;
}