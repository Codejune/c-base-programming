/*
    피보나치 수열은 다음과 같다.
    f1 = 1, f2 = 1 → fi+1 = fi + fi-1 (i ≥ 2)
    피보나치 수열에서는 앞의 2개의 원소를 합하여 뒤의 원소를 만든다.
    사용자에게 항의 개수를 받아 피보나치 수열을 생성하여 출력하는 프로그램을 작성하라.
*/    
#include <stdio.h>
int main(void)
{
    int i, a=0, b=1, c, n;
    
    printf("n을 입력하세요 : ");
    scanf("%d", &n);
    printf("f1 = %d\n", a+b);
    for(i = 2; i <= n; i++)
    {
        c = a+b; // 변수 a와 b를 더하여 변수 c에 대입한다.
        printf("f%d = %d\n", i, c);
        a = b; // 변수 b의 값을 변수 a로 옮긴다.
        b = c; // 변수 c의 값을 변수 b로 옮긴다.
    }
    return 0;
}