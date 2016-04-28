/*
    음주 운전자에 대해 혈중 알코올 농도에 따라 다음과 같은 처벌기준을 정했다고 한다.
    혈중 알코올 농도를 입력하면 처벌 내용을 출력하는 프로그램을 작성하시오.
    (힌트 : if-else문을 사용하라)
    
    혈중 알코올 농도               처벌 내용
    0    ~ 0.049%              훈방 조치
    0.05 ~ 0.099%              면허 정지, 벌금 100만원
    0.1  ~ 0.19%               면허 취소, 벌금 300만원
    0.2% 이상                   면허 취소, 구속
*/
#include "stdio.h"
int main(void){
    float alchol_density;
    
    printf("혈중 알코올 농도를 입력하세요 : ");
    scanf("%f", &alchol_density);
    
    if(alchol_density >= 0){
        if(alchol_density<= 0.049){
            printf("훈방 조치 입니다.");
        } else if(alchol_density <= 0.099) {
            printf("면허 정지 및 벌금 100만원 입니다.");
        } else if(alchol_density <= 0.19){
            printf("면허 취소 및 벌금 300만원입니다.");
        } else {
            printf("면허 취소 및 구속입니다.");
        }
    } else {
         printf("알코올 농도를 정확히 입력해주세요");
    }
    return 0;
}
