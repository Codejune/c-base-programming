/*
    섭씨온도를 화씨온도로 변환하는 수식은 다음과 같다.
    F = 9 / 5 * C + 32
    이 수식을 바탕으로 해서 다음과 같은 프로그램을 작성하였다.
    
    #include "stdio.h"
    int main(void){
        float C;
        printf("섭씨온도를 입력하세요 : ");
        scanf("%f", &C);
        printf("%.2f C = %.2f F\n", C, 9/5*C+32);
        return 0;
    }
    
    이 프로그램을 실행하고 32를 입력했을 때 89.6이 나와야 한다.
    만일 64.0이 나온다면 프로그램을 수정해야 한다.
    무엇이 잘못됐는지 설명하고, 캐스트 연산자를 이용하여 프로그램을 수정하여라.
    수식을 변경해서는 안된다.
*/
#include "stdio.h"
int main(void){
	float C;
	printf("섭씨온도를 입력하세요 : ");
	scanf("%f", &C);
	printf("%.2f C = %.2f F\n", C , (float)9/5*C+32);
	return 0;
}
