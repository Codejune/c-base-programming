/*
    다음 코드의 출력을 생각하여 적어보고, 프로그램을 실행한 후 그 결과를 설명해보아라.
*/
#include "stdio.h"
int main(void){
    char c = 'A';
    printf("sizeof(c) = %lu\n", sizeof(c));
    printf("sizeof('A') = %lu\n", sizeof('A'));
    printf("sizeof(c+c) = %lu\n", sizeof(c+c));
    printf("sizeof(c='A') = %lu\n", sizeof(c='A'));
    return 0;
}