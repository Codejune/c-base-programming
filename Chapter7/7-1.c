/*
    구구단(입력한 정수의 단부터 9단까지)을 출력하는 프로그램을 작성하여라.
    즉, 4를 입력하면 4단부터 9단까지 출력한다.
*/      
#include "stdio.h"
int main(void){
    int n, i, j;
    
    printf("정수를 입력하세요 : ");
    scanf("%d", &n);
    
    for(i=n; i<=9; i++){
        for(j=1; j<=9; j++){
            printf("%d * %d = %d\n", i, j, i*j);
          
        }
    }
    return 0;
}