/* 
    교재의 프로그램 5.11을 확장하여 파일 크기, 파일에 있는 알파벳 문자의 개수, 숫자의 개수, 행 수, 공백 문자나 탭 문자와 같은 여백 문자의 개수를 출력하게 하여라.
    단 출력이 다음과 같이 되도록 하여라.
    파일 크기, 파일 줄 수, 알파벳 문자 수 등은 작성된 소스파일에 따라 다를 수 있다.
    
    $ ./a < 3.c
    파일 크기 : 332 바이트
    파일 줄 수 :  32 행
    알파벳 문자 수 : 260
    숫자 문자 수 : 11
    여백 문자 수 : 30
*/
#include <stdio.h>
int main(void)
{
    int c, total_byte = 0, line_count = 0, alphabet_count=0, number_count=0, space_count = 0;
    while ((c = getchar()) != EOF){ //EOF = End Of File
        total_byte++;
        if (c == '\n'){
      	    ++line_count;
        }
        if (c == ' '){ 
            ++space_count;
        }
        if ('a'<=c && c<='z' || 'A'<=c && c<='Z'){
		    ++alphabet_count;
        }
        if ('0'<= c && c <= '9'){
    		++number_count;
        }
    }
    printf("파일 크기 : %d 바이트\n", total_byte);
    printf("파일 줄 수 : %d 행\n", line_count);
    printf("알파벳 문자 수 : %d\n", alphabet_count);
    printf("숫자 문자 수 : %d\n", number_count);
    printf("여백 문자 수 : %d\n", space_count);
    return 0;
}
