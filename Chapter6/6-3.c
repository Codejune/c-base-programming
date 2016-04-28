/*
	2번 프로그램을 수정하여 1부터 n까지의 짝수의 합과 1부터 n까지의 홀수의 합을 출력하게 하여라.
	단 while 문은 하나만 사용해야 한다.
*/
#include "stdio.h"
int main(void){
	int n=0, i=1, even=0, odd=0;
	printf("정수를 입력하세요 : ");
	scanf("%d", &n);
	if(n<=0){
        return 0;
    }
	while(i<= n){
		if(i%2==0){
			even +=i;
		} else {
			odd += i;
		}
		i++;
	}
	printf("1부터 %d까지의 짝수의 합은 %d입니다. \n", n, even);
	printf("1부터 %d까지의 홀수의 합은 %d입니다. \n", n, odd);
	return 0;
}