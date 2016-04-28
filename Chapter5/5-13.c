/*
    한우 등심의 등급별 가격이 100g당 다음과 같다고 할 때, 등급과 g량을 입력하면 가격을 출력하는 프로그램을 작성하라.
	단, 가격은 1원단위까지만 출력하고, 대소문자 구분없이 동작되게 하라.
	
	구분			A등급			B등급			C등급			D등급
	100g당 가격   12,000원		10,000원		7,000원		 5,000원
*/
#include "stdio.h"
int main(void){
	char item_grade;
	int item_price, item_gram;

	printf("고기의 등급을 입력하세요(A~D) : ");
	scanf("%c", &item_grade);
	printf("고기의 그램을 입력하세요 : ");
	scanf("%d", &item_gram);
	if(item_grade == 'A' || item_grade == 'a')
		item_price = item_gram * (12000/100);
	else if(item_grade == 'B' || item_grade == 'b')
		item_price = item_gram * (10000/100);
	else if(item_grade == 'C' || item_grade == 'c')
		item_price = item_gram * (7000/100);
	else if(item_grade =='D' || item_grade == 'd')
		item_price = item_gram * (5000/100);

	printf("가격은 %d원 입니다.", item_price);
	return 0;
}


	
