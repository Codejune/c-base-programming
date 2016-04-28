/*
    사용자에게 연도를 입력받아 해당 연도가 윤년인지 아닌지 판별하는 프로그램을 작성하라.
    윤년은 4로 나누어져야하며 이중 100으로 나누어지지 않으면 윤년이고
    100으로 나누어지나 400으로도 나누어지면 윤년이다. 해당 프로그램은 다중 if-else문으로 작성하라.
*/
include "stdio.h"
int main(void){
    int year;
    
    printf("년도를 입력하세요 : ");
    scanf("%d", &year);
    
    if((year%4)==0&&(year%100)!=0){
        printf("%d년은 윤년입니다.", year);
    } else if((year%100)==0&&(year%400)==0) {
        printf("%d년은 윤년입니다.", year);
    } else {
        printf("%d년은 평년입니다.", year);
    }
    return 0;
}