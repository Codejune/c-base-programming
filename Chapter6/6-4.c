/*
	while문을 이용하여 두 개의 정수를 사용자에게 입력받아 최대공약수를 구하는 프로그램을 작성하라.
*/
#include "stdio.h"
int main(void){
	int x, y, r;
	printf("두개의 정수를 입력하세요 : ");
	scanf("%d%d", &x, &y);
	if(x>y){
		while(y != 0){
			r = x % y;
			x = y;
			y = r;
		}
		printf("최대 공약수는 %d 입니다.\n", x);
	}else{
		while (x != 0){
			r = y%x;
			y = x;
			x = r;
		}
		printf("최대 공약수는 %d 입니다.\n", y);
	}
	return 0;
}