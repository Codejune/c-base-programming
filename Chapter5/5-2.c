/*
	if문을 이용하여 사용자에게 입력받은 정수가 양수인지, 음수인지, 0인지 판별하는 프로그램을 작성하라.
*/
#include "stdio.h"
int main(void){
	int get_num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &get_num);

	if(get_num<0){
		printf("음수입니다");
	} else if(get_num==0){
		printf("0입니다");
	} else {
		printf("양수입니다");
	}
}	


