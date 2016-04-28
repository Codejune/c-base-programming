/*
    9번 프로그램을 다음과 같이 수정하였다.
    즉 화씨온도를 계산하는 부분을 9 / 5 * C + 32에서 C * 9 / 5 + 32로 수정하였다.
    실행해보고 왜 9번 프로그램의 결과와 다른지 설명해보아라.
*/
#include "stdio.h"
int main(void){
    float C;
	printf("섭씨온도를 입력하세요 : ");
    scanf("%f", &C);
    printf("%.2f C = %.2f F\n", C , C*9/5+32);
    return 0;
}