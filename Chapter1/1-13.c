/*
    다음 프로그램을 작성하고 컴파일하고 실행하여 보아라.
    (컴파일 예 : gcc test.c)
*/
#include <stdio.h>
#define TRUE 1
int main(void){
	int i=0, total=0;
	while(TRUE){
			total += i;
			if(i == 10)
				break;
			i++;
	}
	printf("1부터 10까지의 합은 %d입니다.\n", total);
    
	total /= 2;
	printf("totla / 2 = %d입니다.\n", total);
    
	total += 20;
	printf("(total / 2) + 20 = %d입니다.\n", total);
    
	total %= 3;
	printf("((total / 2) + 20) %% 3 = %d입니다.\n", total);
    
    return 0;
}
			
			
					
