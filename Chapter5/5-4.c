/*
	사용자에게 성적을 입력받아 등급을 표시해주는 프로그램을 if-else문을 이용하여 작성하라.
	
	점수 				등급
	90<=score		 A
	80<=score<90	 B
	70<=score<80	 C
	60<=score<60	 D
	score<60		 F 
*/
#include "stdio.h"
int main(void){
	int get_score;
	printf("점수를 입력하세요 : ");
	scanf("%d", &get_score);
	if(get_score>=0){
		if(get_score>=90){
			printf("A등급입니다.");
		} else if(get_score>=80){
			printf("B등급입니다.");
		} else if(get_score>=70){
			printf("C등급입니다.");
		} else if(get_score>=60){
			printf("D등급입니다.");
		} else {
			printf("F등급입니다.");
		}
	} else {
		printf("양수만 입력해주세요.");
	}
	return 0;
}

