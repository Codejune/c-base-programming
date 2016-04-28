/*
    다음 프로그램은 정상적으로 컴파일 되는가?
    아니면 오류 메시지를 쓰고 오류가 왜 발생하는지 설명하여라.
*/
#include "stdio.h"
int main(void){
	int a = 0x9G7;
	int b = 088;
	int c = 0123C;
	printf("a=%d b=%d c=%d\n", a, b, c);
	return 0;
}
