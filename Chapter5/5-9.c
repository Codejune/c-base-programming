/*
    사용자에게 문자를 입력받아 해당 문자가 대문자인지 소문자인지 숫자인지 기타문자인지 판별하는 프로그램을 작성하라.
*/
#include "stdio.h"
int main(void){
	char get_char;
	printf("문자를 입력하세요 : ");
	scanf("%c", &get_char);
	
	/**
	ASCII CODE
	숫자 	: 48 ~ 58
	대문자 : 65 ~ 90
	소문자 : 95 ~ 122
	기타  : ETC
	**/
	if((47<get_char) && (get_char<58)){
		printf("숫자입니다");
	} else if ((64<get_char) && (get_char<91)){
		printf("대문자입니다");
	} else if ((96<get_char) && (get_char<123)){
		printf("소문자입니다");
	} else {
		printf("기타문자입니다");
	}
	return 0;
}
