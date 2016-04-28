/*
    컴퓨터 부품을 판매하는 회사의 품명과 가격이 다음과 같다고 할 때 품명번호와 수량을 입력하면 품명, 수량, 가격을 출력하는 프로그램을 작성하라.
    그 외의 번호를 입력하면 수량과 가격을 0으로 출력하라.
    
    품명번호    품명          가격(원)
    1         Monitor      204,000
    2         Hard Disk    97,000
    3         CPU          247,500
    4         Mother Board 134,200
    5         Keyboard     64,300
    6         Mouse        33,000
*/
#include "stdio.h"
int main(void){
    int list_number, item_count;

    printf("품명번호를 입력해주세요 : ");
    scanf("%d", &list_number);
    printf("수량을 입력해주세요 : ");
    scanf("%d", &item_count);

    if( list_number < 1 || list_number > 6) {
	    printf("품명 : Error\n수량 : 0개\n가격 : 0원\n");
    } else {
	    switch(list_number){
	        case 1 : printf("품명 : Monitor\n수량 : %d개\n가격 : %d원", item_count, item_count*204000);
		     break;
		 
	        case 2 : printf("품명 : Hard Disk\n수량 : %d개\n가격 : %d원", item_count, item_count*97000);
		     break;
         
            case 3 : printf("품명 : CPU\n수량 : %d개\n가격 : %d원", item_count, item_count*247500);
		     break;
        
            case 4 : printf("품명 : Mother Board\n수량 : %d개\n가격 : %d원", item_count, item_count*134200);
		     break;
         
            case 5 : printf("품명 : Keyboard\n수량 : %d개\n가격 : %d원", item_count, item_count*64300);
		     break;
        
            case 6 : printf("품명 : Mouse\n수량 : %d개\n가격 : %d원", item_count, item_count*33000);
		     break;
        }
    } 
    return 0;
}
    
