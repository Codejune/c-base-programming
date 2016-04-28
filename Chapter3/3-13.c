/*
    다음 프로그램을 실행하기 전에 자신이 생각하는 답을 한법 작성해보고, 프로그램을 실행해 보아라.
    결과값에 대한 설명을 하라.
    (연산자는 우선순위에서 관계 연산자(<, >, >=, <=)가 논리 연산자(&&, ||)보다 높다.
    논리곱(&&)연산은 논리합(||) 연산보다 우선순위가 높다.)
*/
#include "stdio.h"
int main(void){
	int a = 0, b = 0;
	int result;
	result = 2 > 3 || 6 > 7;
	printf("%d\n", result);
	result = 2 || 3 || 3 > 2;
	printf("%d\n", result);
	result = a = b = 1;
	printf("%d\n", result);
	result = - ++a + b--;
	printf("%d\n", result);
	return 0;
}
