/*
    사용자에게 반자름의 길이를 정수로 입력받아 해당 원의 넓이를 구하는 프로그램을 작성하라.
*/
#include <stdio.h>
int main(void){
    int r;
    float s;
    printf("반지름을 입력하세요 : ");
    scanf("%d", &r);
    s = r*r*3.14;
    printf("반지름 : %f", r*r*3.14);
    return 0;
}
