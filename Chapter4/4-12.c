/*
    C99는 부동형의 특성을 기술하는 매크로들을 <float.h>에 정의하고 있다.
    아래 표를 채워라.
    각 매크로의 의미는 매크로 이름을 보면 금방 이해할 수 있을 것이다.
    다만 FLT_DIG, DBL_DIG, LDBL_DIG는 각 형의 정밀도를 의미한다.
    
    기본형         매크로     값               변환명세
    flaot        FLT_MIN   1.17549e-13     %g
                 FLT_MAX   3.40282e+38     %g
                 FLT_DIG   6               %d
    double       DBL_MIN   2.22507e-308    %g
                 DBL_MAX   1.79769e+308    %g
                 DBL_DIG   15              %d
    long double  LDBL_MIN  3.3621e-4932    %Lg
                 LDBL_MAX  1.18973e+4932   %Lg
                 LDBL_DIG  18              %Ld
                 
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
#include "float.h"
int main(void){
	printf("%g\n", FLT_MIN);
	printf("%g\n", FLT_MAX);
	printf("%d\n", FLT_DIG);
	return 0;
}
