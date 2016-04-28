/*
	if-else문을 이용하여 사용자에게 입력받은 정수가 홀수인지 짝수인지 판별하는 프로그램을 작성하라.
*/
#include "stdio.h"
int main(void){
	int get_num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &get_num);

	if(get_num%2==1){
		printf("홀수입니다");
	}else{
		printf("짝수입니다");
	}
	return 0;
}


