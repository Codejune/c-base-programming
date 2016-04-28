/*
    온스(oz)는 무게를 측정하는 단위이다.
    사용자에게 온스를 입력받아 킬로그램(kg)으로 환산하는 프로그램을 작성하라
    1oz는 0.02835kg이다.
*/
#include "stdio.h"
int main(void){
	float oz;
	printf("변환할 온스를 입력하세요 : ");
	scanf("%f", &oz);
	printf("온스 -> 킬로그램 : %fkg", oz*0.02835);
	return 0;
}
