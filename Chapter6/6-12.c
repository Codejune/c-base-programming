/*
	반복문을 이용하여 간단한 정수 계산기 프로그램을 작성하라.
	각각의 연산자는 메뉴 형식으로 입력받아 처리하며 Exit를 누를 때 까지 반복되어야 한다.
	
	1. Add
	2. Sub
	3. Mul
	4. Div
	5. Exit
	명령을 입력하세요 : 1
	두 수를 입력하세요 : 10 2
	결과는 12 입니다.
	1. Add
	2. Sub
	3. Mul
	4. Div
	5. Exit
	명령을 입력하세요 : 4
	두 수를 입력하세요 : 8 2
	결과는 4 입니다.
	1. Add
	2. Sub
	3. Mul
	4. Div
	5. Exit
	명령을 입력하세요 : 5
*/
#include "stdio.h"
int main(void){
	int num, i, j;
	while(1){
	printf("1. Add\n2. Sub\n3. Mul\n4. Div\n5. Exit\n명령을 입력하세요 : ");
	scanf("%d", &num);
	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &i, &j);
	switch(num){
		case 1 : printf("결과는 %d입니다.\n", i + j);
				 break;
				 
		case 2 : printf("결과는 %d입니다.\n", i - j);
				 break;
				 
		case 3 : printf("결과는 %d입니다.\n", i * j);
				 break;
				 
		case 4 : printf("결과는 %d입니다.\n", i / j);
				 break;
				 
	  	case 5 : return 0;
		}
	}
}
