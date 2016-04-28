/*
	다음과 같이 printf() 문장이 세 개 있다.
	printf("statement_1\n");
	printf("statement_2\n");
	printf("statement_3\n");
	
	위의 세 printf() 문 앞 또는 뒤에 if나 if-else를 적절히 삽입하여 i값에 따라 화면에 다음과 같이 출력되도록 하여라.
	(각 printf() 문은 한번만 사용할 수 있다.)
	
	i 		출력
	1		statement_1
	2		statement_2
	3		statement_3		
*/
#include "stdio.h"
int main(void){
	int get_i;
	printf("값을 입력하세요(1,2,3) : ");
	scanf("%d", &get_i);
	if(get_i==1)
		printf("statement_1\n");
	if(get_i==2)
		printf("statement_2\n");
	if(get_i==3){
		printf("statement_3\n");
	return 0;
}
