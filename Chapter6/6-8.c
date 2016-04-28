/*
	3^n을 구하는 프로그램을 작성하라.
	n은 사용자에게 받으며 음수, 0, 양수를 받을 수 있어야 한다.
*/
#include "stdio.h"
int main(void){
	int i, n;
	float result = 1.0;
	printf("n을 입력하세요 : ");
	scanf("%d", &n);
	if(n>0){
		for(i=1; i<=n; i++){
			result = result * 3;
		}
	} else {
		n = n*-1;
		for(i=1; i<=n; i++){
			result /= 3;
		}
	}
	printf("%f", result);
	return 0;
}