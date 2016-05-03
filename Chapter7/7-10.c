/*
    시그마 k=1부터 n까지 50000을 넘지 않는 가장 큰 값과 그 때의 n의 값을 구하는 프로그램을 작성하라.
*/    
#include "stdio.h"
int main(void){
    int n = 1, sum = 0;
    while(1){
        sum += n;
        if( sum > 50000 ){
            sum -= n;
            printf( "1부터 n까지의 합 중에서 50000 넘지않는 가장 큰 합은 n이 %d일때 %d이다n", n-1, sum );
            return;
        }
        n++;
    }
}
