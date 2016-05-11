/*
    <limits.h> 헤더 파일은 정수형 기본 자료형의 범위에 관한 매크로를 정의하고 있다.
    각 매크로가 어떤 것인지는 매크로 이름을 보면 금방 이해할 수 있을 것이다.
    
    기본형                 매크로         값                       변환명세
    char                 CHAR_MIN      -128                    %d
                         CHAR_MAX      127                     %d
    signed char          SCHAR_MIN     -128                    %d
                         SCHAR_MAX     127                     %d
    unsigned char        UCHAR_MAX     255                     %u
    short                SHRT_MIX      -32768                  %hd
                         SHRT_MAX      32767                   %hd
    unsigned short       USHRT_MAX     65535                   %hu
    int                  INT_MIN       -2147483648             %d
                         INT_MAX       2147483647              %d
    unsigned int         UINT_MAX      4294967295              %u
    long                 LONG_MIN      -9223372036854775808    %ld
                         LONG_MAX      9223372036854775807     %ld
    unsigned long        ULONG_MAX     18446744073709551615    %lu
    long long            LLONG_MIN     -9223372036854775808    %lld
                         LLONG_MAX     9223372036854775807     %lld
    unsigned long long   ULLONG_MAX    18446744073709551615    %llu
    
    이 표를 다음과 같은 프로그램을 사용해서 완성하여라.
    프로그램을 사용할 경우 printf()의 변환 문자를 적절히 사용해야 올바른 값이 출력될것이다.
    수업시간에 설명한 각 자료형별 변환명세를 참조하여라.
    
    # 기본 변환명세
    변환명세                      출력형식
    %[-][width]c                문자 출력 (char)
    %[-][width]s                문자열 출력 (char)
    %[-][width]d                10진수 부호있는 정수 출력 (short, int, long, long long)
    %[-][#][width]x             16진수 정수 출력, #은 0x를 앞에 붙임
    %[-][#][width]o             8진수 정수 출력, #은 0dmf 앞에 붙임
    %[-][#][width]p             16진수 포인터값 출력
    %[-][width]ld               10진수 long형 출력
    %[-][width]lld              10진수 long long형 출력
    %[-][width][conversion]u    10진수 부호없는 정수 출력 (unsigned)
    %[-][width][.precision]f    소수의 실수 출력
    %[-][width][.precision]lf   double형 소수의 실수 출력
    %[-][width][.precision]e    지수형 실수 출력
    ============================================================
    *[-]는 좌측 정렬을 의미
    *[width]는 출력 할 폭
    *[conversion]은 변환명세
    *[.precision]는 소숫자릿수
    ============================================================
    
    # 특수한 자료형의 변환명세
    unsigned자료형은 int형과 숫자를 저장하는 구조(최상위비트)가 다르므로 따로 변환명세를 %u로 써야 하며, %d를 쓰면 안된다.
    short자료형은 변환명세로 %hd, %od 둘다 써도 무방하다.
    (%hd, %od는 가시적으로 short형이다 라는것을 보여주기 위한 것 이기 때문)
    
    # 자동 변환명세
    %C : %c
    %i : %d
    %E : e대신 E로 출력 
    %g : 크기가 작으면 %f, 크기가 크면 %e
    %G : 크기가 작으면 %f, 크기가 크면 %E
    %x : 16진수 정수 소문자, 0~9, a~f
    %X : 16진수 정수 대문자 : 0~9, A~F
    %% : % 출력
*/
#include "stdio.h"
#include "limits.h"
int main(void){
    printf("CHAR_MIN : %d\n", CHAR_MIN);
    printf("CHAR_MAX : %d\n", CHAR_MAX);
    return 0;
}
                     