/*
	재테크 중 중요한 법칙 중의 하나가 바로 복리이다.
	복리는 이자 계산 방법의 하나로서 일정 기간마다 이자를 원금에 더해 이것을 새로운 원금으로 계산하는 방법이다.
	복리계산식을 이용하여 n년 후 원리금을 구하는 프로그램을 작성하라.
	복리계산식은 다음과 같다.
	
	원리합계 = 원금 * (1 + 이율)^기간
	
	원금 : 100000
	이자율 : 15
	기간(년) : 5
	연도		원리금
	1		 115000.00
	2		 132250.00
	3		 152087.50
	4		 174900.62
	5		 201135.72
*/
#include "stdio.h"
int main(void){
	int i, original_money, year;
	float interest_rate, principal_money;

	printf("원금 : ");
	scanf("%d", &original_money);
	printf("이자율 : ");
	scanf("%f", &interest_rate);
	printf("기간(년) : ");
	scanf("%d", &year);

	interest_rate = interest_rate/100;
	principal_money += original_money*(1+interest_rate);
	printf("연도	원리금\n");
	for(i=1;i<=year;i++){
		printf("%d	%.2f\n", i, principal_money);
		principal_money = principal_money*(1+interest_rate);
	}
	return 0;
}


