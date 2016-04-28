/*
    현재 시스템에서 char 형이 signed char형인지 아니면 unsigned char 형인지를 다음 프로그램으로 알아 볼 수 있다.
    출력 결과로 char 형이 어떤 형과 동일하다고 말할 수 있는가?
*/
#include "stdio.h"
int main(void){
	int value1=-1, value2=-1;
	char a=0xff;
	signed char b=0xff;
	unsigned char c = 0xff;
	value1 = a == b;
	value2 = a == c;
	printf("%d %d", value1, value2);
	return 0;
}
