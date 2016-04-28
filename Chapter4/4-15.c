/*
    물리학에서 운동에너지는 E = m * v^2 / 2 으로 계산된다.
    사용자로부터 질량(m)과 속도(v)를 입력받아 운동에너지(E)를 계산하는 프로그램을 작성하라.
    모든 변수는 double형을 사용하고, 소숫점 4번째 자리까지 출력하라.
*/
#include "stdio.h"
int main(void){
	double gram;
	double speed;
	printf("질량과 속도를 입력하세요 : ");
	scanf("%lf %lf", &gram, &speed);
	printf("질량 : %lf, 속도 : %lf, E = %.4lf", gram, speed, gram*(speed*speed)/2);
	return 0;
}
