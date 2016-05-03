/*
    while문과 rand() 함수를 사용하여 1에서 100 중 임의의 숫자를 고른 후 사용자에게 숫자를 맞추는 게임을 작성하라.
    단, rand() 함수를 이용하여 고른 숫자는 매번 다른 숫자가 선택되어야 한다.
    
    $./a
    정답을 예측해보세요 : 13
    제시한 정수가 낮습니다.
    정답을 예측해보세요 : 20
    제시한 정수가 높습니다.
    정답을 예측해보세요 : 18
    제시한 정수가 높습니다.
    정답을 예측해보세요 : 17
    정답입니다. 시도횟수 : 4 
*/    
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main(void){
    int n, random, count=0;
    srand(time(NULL));
    random = rand()%100+1;
    while(1){
        printf("정답을 예측해보세요 : ");
        scanf("%d", &n);
        if(n>random){
            printf("제시한 정수가 높습니다.\n");
        } else if(n<random){
            printf("제시한 정수가 낮습니다.\n");
        } else {
            printf("정답입니다. 시도횟수 : %d", count);
            return 0;
        }
        count++;
    }
}