/*
	대부분의 프로그램은 하나의 함수만 존재하는 것이 아니다.
	따라서 다양한 함수가 합쳐져서 하나의 프로그램을 이루는데 사용자가 원하는 함수를 구현하기 위해서는 메뉴가 필요하다.
	왜냐하면 사용자에게 메뉴를 보여주고 선택하게 함으로써 사용자가 원하는 프로그램을 실행할 수 있기 때문이다.
	다양한 함수 대신 printf()로 이루어진 메뉴를 작성해 보아라.
	(do-while문을 이용하여 종료 할 때까지 반복)
*/
#include "stdio.h"
int main(void){
	int num;
	do{
		printf("1. 새로만들기\n2. 이어만들기\n3. 실행하기\n4. 종료\n");
		printf("숫자를 입력해주세요 : ");
		scanf("%d", &num);
		if(num==1){
			printf("새로만들기\n");
		} else if(num==2){
			printf("이어만들기\n");
		} else if(num==3){
			printf("실행하기\n");
		} else if(num==4){
			printf("종료\n");
		}
	} while(num!=4);
	return 0;
}