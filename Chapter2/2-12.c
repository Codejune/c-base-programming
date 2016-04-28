/*
    화씨온도를 입력받아 섭씨온도로 변화하는 프로그램을 작성하여라.
    화씨온도를 섭씨온도로 변환하는 수식은 다음과 같다.
    C = (F-32) * 5 / 9
*/
#include "stdio.h"
int main(void) {
    float F;
    printf("화씨온도를 입력하세요 : ");
    scanf("%f", &F);
    printf("%.1f F = %.1f C ", F, (F-32)*5/9);
}

