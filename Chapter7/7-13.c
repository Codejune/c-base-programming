/*
    어느 분식점의 음식가격이 다음과 같다.
    사용자가 음식 번호랑 수량을 입력하면 식대와 현재 매출액을 출력하는 프로그램을 작성하시오.
    단, 음식번호로 0과 수량에 0을 입력하기전까지 한 사람이 두개 이상의 음식을 계산하는 경우로 처리하여 식대의 누적값을 출력하고 음식 번호로 5와 수량에 0을 입력하면 프로그램을 종료한다.
    
    음식번호    음식      가격(원)
    1          김밥      2300
    2          라면      3300
    3          떡볶이    4000
    4          만두      3000
    
    $ ./a
    음식번호와 수량 입력 : 1 5
    가격 : 11500원
    음식번호와 수량 입력 2 3
    가격 : 21400원
    음식번호와 수량 입력 : 4 1
    가격 : 24400원
    음식번호와 수량 입력 : 1 4
    가격 : 33600원
    음식번호와 수량 입력 : 0 0
    가격 33600원
    현재 매출액 : 33600
    음식번호와 수량 입력 : 4 10
    가격 : 30000원
    음식번호와 수량 입력 : 3 200
    가격 : 830000원
    음식번호와 수량 입력 0 0
    가격 : 830000원
    현재 매출액 : 863600
    음식번호와 수량 입력 : 5 0
    가격 : 0원
    현재 매출액 863600
*/      
#include "stdio.h"
int main(void){
    int food_number, quantity, sales=0, total;
    while(1){
        printf("음식번호와 수량 입력 : ");
        scanf("%d %d", &food_number, &quantity);
        
        switch(food_number){
            case 1 : sales += 2300*quantity;
                     printf("가격 : %d원\n", sales);
                     break;
            
            case 2 : sales += 3300*quantity;
                     printf("가격 : %d원\n", sales);
                     break;
            
            case 3 : sales += 4000*quantity;
                     printf("가격 : %d원\n", sales);
                     break;
                     
            case 4 : sales += 3000*quantity;
                     printf("가격 : %d원\n", sales);
                     break;
        }
        
        if(food_number == 0 && quantity == 0){
            total += sales;
            printf("가격 : %d원\n", sales);
            printf("현재 매출액 : %d원\n", total);
           
            sales = 0;
        } else if(food_number == 5 && quantity == 0){
            printf("가격 : %d원\n", sales);
            printf("현재 매출액 : %d원\n", total);
            return 0;
        }
       
    }
    
}