/*
    7번 프로그램을 조건부 연산자를 이용하는 프로그램으로 변형하여라.
*/
#include "stdio.h"
int main(void){
	int year;
	printf("년도를 입력하세요 : ");
	scanf("%d", &year);

	((year%4==0 && year%100!=0) || (year%400==0)) ? printf("%d년은 윤년입니다.", year) : printf("%d년은 평년입니다.", year);
	return 0;
}
