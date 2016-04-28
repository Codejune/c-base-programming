/*
    다음 if-else문을 보고 조건부 연산자를 이용하여 제대로 결과가 출력되도록 프로그램을 작성하라.
	
	if(d==0)
		printf("0으로 나눌 수 없습니다.\n");
	else{
		result = n/d;
		printf("결과는 %d입니다.\n", result);
	}	
*/
#include "stdio.h"
int main(void){
	int a,b;
	printf("분자와 분모를 입력하세요 : ");
	scanf("%d %d", &a, &b);
	(a==0)?printf("0으로 나눌 수 없습니다."):printf("결과는 %d입니다.", a/b);
	return 0;
}
