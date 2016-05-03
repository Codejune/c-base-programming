/*
    2와 100사이에 있는 소수(prime number)를 찾는 프로그램을 작성하라.
    정수가 소수가 되려면 1과 자기 자신만을 약수로 가져야 한다.
*/
#include <stdio.h>
int main(void){
    int i, j;
    for( i = 1; i <= 100; i++ ) {
        for( j = 2; j <= i; j++ ) {
            if( i%j == 0 ) {
                if( i > j ){
                    break;
                } else {
                     printf("%d ", i);
                }
            }
        }
    }
    return 0;
}