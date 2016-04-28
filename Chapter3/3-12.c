/*
    다음은 복합 배정연산자로 표현한 수식이다. 이 수식을 완전한 괄호로 표현하라.
    생각하는 답을 먼저 적고, 프로그램을 작성 후 확인하라.
    
    int x=8, y=6, z=3;
    x += y * z += 8;
*/
#include "stdio.h"
int main(void){
	int x=8, y=6, z=3;
	printf("%d",x += y *= z += 8);
	return 0;
}
