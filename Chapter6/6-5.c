/*
	반감기란 어떤 특정 방사성 핵종의 원자수가 방사성 붕괴에 의해서 원래의 수의 반으로 줄어드는데 걸리는 시간을 말한다.
	예를 들어 반감기가 10년인 어떤 물질의 처음양이 100이라고 할 때 이 물질의 양이 50이 되기 위해서는 10년이라는 시간이 필요하다.
	어떤 물질의 반감기가 23년이라고 할 때 처음 양의 1/20 이하로 줄어들기까지의 걸린 시간을 구하라.
*/
#include "stdio.h"
int main(void){
	int halflife;
	double initial;
	double current;
	int year = 0;
	
	printf("반감기를 입력하세요(년) : ");
	scanf("%d", &halflife);
	
	initial = 100.0;
	current = initial;
	
	while(current > initial/20.0){
		year += halflife;
		current = current / 2.0;
		printf("%d년 후에 남은 량 = %f\n", year, current);
		
	}	
	printf("1/20이하로 되기까지 걸린 시간 = %d년 후", year);
	return 0;
}