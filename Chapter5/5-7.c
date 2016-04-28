/*
    6번 프로그램에서 사용한 다중 if-else문을 하나의 if-else문으로 변형하라.
*/
#include "stdio.h"
int main(void){
	int year;
	printf("연도를 입력하세요 : ");
	scanf("%d", &year);

	if((year%4==0 && year%100!=0) || (year%400==0)){
		printf("%d년은 윤년입니다.", year);
	} else {
		printf("%d년은 평년입니다.", year);
	}
	return 0;
}

