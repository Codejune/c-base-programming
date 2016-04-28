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
*/
#include "stdio.h"
#include "float.h"
int main(void){
	printf("%g\n", FLT_MIN);
	printf("%g\n", FLT_MAX);
	printf("%d\n", FLT_DIG);
	return 0;
}
