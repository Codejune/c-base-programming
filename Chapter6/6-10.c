/*
    다음은 무한루프에 빠진 프로그램이다.
    변수 i가 100이 될 경우 무한루프를 빠져나와 "무한루프 탈출" 이라는 printf()문이 실행 될 수 있도록 수정하라.
    단 for()문은 건들지 않는다.
    
    #include "stdio.h"
    int main(void){
        int i;
        for( ; ; i++){
            //여기에 들어갈 코드를 입력하세요.
        }
        printf("%d번 째에 무한루프 탈출\n", i);
        return 0;
    }
*/
#include "stdio.h"
int main(void){
    int i;
    for( ; ; i++){
        if(i==100){
            break;
        }
    }
    printf("%d번 째에 무한루프 탈출\n", i);
    return 0;
}
