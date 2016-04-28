/*
    다음 프로그램은 환율을 계산하는 프로그램이다.
    프로그램의 용도를 알기 쉽도록 주석을 보고 각 변수명을 적절하게 변경하고, printf()도 수정하여라.
*/
#include "stdio.h"
int main(void){
    float a;    //원/달러 환율
    float b;    //달려화
    int c;      //원화
    
    printf("원/달러의 환율을 입력해주세요 : ");
    scanf("%f", &a);
    
    printf("변환할 원화를 입력해주세요 : ");
    scanf("%d", &c);
    
    b = c/a;
    printf("변환할 원화 : %d\n변환된 달러 : %f\n", c, b);
    return 0;
}