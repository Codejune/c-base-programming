/*
	사용자에게 양수 n을 입력받으면 n부터 1까지 n!(Factorial)을 구하는 프로그램을 for문을 이용하여 작성하라.
	ex) 5! : 5 * 4 * 3 * 2 * 1
	
	n을 입력하세요 : 6
	6! = 720
	5! = 120
	4! = 24
	3! = 6
	2! = 2
	1! = 1
*/
#include "stdio.h"
int main(void){
	int i, j, k = 1, n ;
	printf("n을 입력하세요 : ");
	scanf("%d", &n);

	for(;n>=1;n--){
		for(j=1;j<=n;j++){
			k *= j;
		}
		printf("%d! = %d\n", n, k);
		k=1;
	}
	return 0;
}