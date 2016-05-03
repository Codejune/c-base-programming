/*
	서로 다른 n개에서 r개를 택하여 일렬로 나열하는 방법의 수를 순열(permutation)이라 하고, nPr로 표시한다.
	사용자에게 n값과 r값을 받아 순열을 구하는 프로그램을 작성하라.
	
	nPr = n(n-1)(n-2)....(n-r+1)
*/	
#include<stdio.h>
int main(void){
	int n, r, i, nPr = 1;
	printf("n의 값 : ");
	scanf("%d", &n);
	printf("r의 값 : ");
	scanf("%d", &r);
	for (i = n; i >= (n - r + 1); i--){
		nPr = nPr*i;
	}
	printf("순열의 값은 %d 입니다.\n", nPr);
	return 0;
}