/*
    1번 프로그램을 수정하여 1부터 n 사이의 짝수만 더하여 출력하여라.
*/
#include "stdio.h"
int main(void){
    int i=0, n, total;
    printf("정수를 입력하세요 : ");
    scanf("%d", &n);
    if(n<=0){
        return 0;
    }
    total = i;
    while(i<=n){
        if(i%2==0){
            total += i;
        }
        i++;
    }
    printf("1부터 %d까지의 짝수의 합은 %d입니다.", n, total);
    return 0;
}