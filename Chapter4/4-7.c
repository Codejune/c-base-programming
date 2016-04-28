/*
    <limits.h> 헤더 파일은 정수형 기본 자료형의 범위에 관한 매크로를 저으이하고 있다.
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
*/
#include "stdio.h"
#include "limits.h"
int main(void){
    printf("CHAR_MIN : %d\n", CHAR_MIN);
    printf("CHAR_MAX : %d\n", CHAR_MAX);
    return 0;
}
                     