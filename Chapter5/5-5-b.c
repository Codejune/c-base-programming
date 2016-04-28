/*
	다음과 같이 printf() 문장이 세 개 있다.
	printf("statement_1\n");
	printf("statement_2\n");
	printf("statement_3\n");
	
	위의 세 printf() 문 앞 또는 뒤에 if나 if-else를 적절히 삽입하여 i값에 따라 화면에 다음과 같이 출력되도록 하여라.
	(각 printf() 문은 한번만 사용할 수 있다.)
	
	i 		출력
	1		statement_2
	2		statement_1
			statement_3	
	3		statement_1	
*/
#include "stdio.h"
int main(void){
	int i;
	printf("숫자를 입력하세요(1,2,3) : ");
	scanf("%d", &i);

	if(i==2||i==3)
		printf("statement_1\n");
	if(i==1)
		printf("statement_2\n");
	if(i==2)
		printf("statement_3\n");
	return 0;
}
