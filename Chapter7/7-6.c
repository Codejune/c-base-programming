/*
    5번 프로그램을 여러 번 수행해도 매번 출력 내용이 같을 것이다.
    그 이유는 rand() 함수는 seed라는 값을 바탕으로 무작위 수를 생성하는데 프로그램이 시작될 때 매던 같은 값으로 seed가 초기화되기 때문이다.
    seed 값을 다른 값으로 초기화하려면 srand() 함수를 사용하면 된다.
    seed의 초기 값은 프로그램이 실행될 때마다 매번 다른 값이 되어야 하기 때문에 보통 현재 시간을 알려주는 time() 함수를 사용하여 seed를 초기화한다.
    앞에서 작성한 프로그램의 while 문 앞에 다음 문장을 삽입한 후 프로그램을 다시 실행하여 매번 다른 무작위 수가 생성되는지 확인해보아라.
    
    srand(time(NULL));
    
    참고 : srand()와 rand()를 사용하기 위해서는 #include "stdio.h" 다음에 #include "stdlib.h"를 추가해야 하고, time()을 사용하기 위해서는 #include "time.h"를 추가해야 한다.
*/    
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main(void){
    int i=1;
    srand(time(NULL));
    while(i<=10){
        printf("%d번째 난수 : %d\n", i, rand());
        i++;
    }
    return 0;
}