/*
    1부터 100사이의 모든 3의 배수의 합을 계산하여 출력하는 프로그램을 while문, for문, do-while문으로 작성하라.
    (while, for, do-while 모두 사용해볼 것)
*/    
#include "stdio.h"
int main(void){
    int i, sum;
    for(i=1; i<=100; i++){
        if(i%3==0){
            sum+=i;
        }
    }
    printf("1부터 100까지의 3의 배수의 합은 %d입니다.", sum);
    return 0;
}