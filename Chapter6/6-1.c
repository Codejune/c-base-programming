/*
    정수(n)을 입력받아 1부터 n까지 합을 구하는 프로그램을 작성하여라.
    단, while 문을 사용해야 하고, 음수가 입력되면 프로그램을 종료해야한다.
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
        total += i;
        i++;
    }
    printf("1부터 %d까지의 합은 %d입니다.", n, total);
    return 0;
}