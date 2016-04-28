/*
    다음 프로그램을 작성하고 컴파일하고 실행하여 보아라.
    (컴파일 예 : gcc test.c)
*/
#include "stdio.h"
int main(void){
	int i, total=0;
	for(i=1; i<=100; i++)
		total += i;
	printf("1부터 100까지의 합은 %d입니다.\n", total);
	return 0;
}
