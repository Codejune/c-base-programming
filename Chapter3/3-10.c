/*
    다음 프로그램의 출력 결과를 설명하여라.
*/
#include "stdio.h"
int main(void){
	int a, b = 0, c = 0;
	a = ++b + ++c;
	printf("%d %d %d \n",a, b, c);
	a= b++ + c++;
	printf("%d %d %d \n", a, b, c);
	a = ++b + c++;
	printf("%d %d %d\n", a, b, c);
	a = b-- + --c;
	printf("%d %d %d\n", a, b, c);
	return 0;
}
