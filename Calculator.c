//
//  Schedulator
//
//  Created by Codejune on 2016. 5. 25.
//  Copyright © 2016년 Codejune. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


/** 전역 변수 **/

int top = -1;
double Alpha[26];
char Stack[1000] = {0};
char CalStack[BUFSIZ][1000] = {0};

/***********************************
 1. 스택 함수 구현
 2. Spush, Spop, Speek, IsEmpty
 ***********************************/

void Spush(char);

char Spop(void);

char Speek(void);

bool IsEmpty(void);

/**********************************
 Calculate에 필요한 함수 구현
 **********************************/

void Calculate(void); // 계산의 전반적인 과정을 처리하는 함수

void RemoveSpace(char []); // 공백 제거 함수

bool Input(char []); // Input 문자열 정리하는 함수

void Transformation(char []); // math 함수나 문자 상수 처리하는 함수

void Postfix(char []); // 후위연산 기법으로 문자열 처리하는 함수

int OperatorCmp(char op1,char op2); // 연산자 우선순위 판단

int OperatorReturn(char op); // 연산자 리턴값 설정

double Result(char []); // 계산

double CalReturn(char op,double num1,double num2); // 계산 결과 리턴

void ProgramExit(void);

/**********************************
 스케줄 관리 함수
 **********************************/

void Schedule(void);

int main(void)
{
    system("clear");
    char input;
    
    while(1)
    {
        printf("1. 공학용 계산기\n");
        printf("2. 스케줄 관리  \n");
        printf("3. 프로그램 종료\n");
        
        printf("\n입력 : ");
        scanf("%c", &input);
        getchar();
        
        if(input == '1')
        {
            Calculate();
        }
        else if(input == '2')
        {
            Schedule();
        }
        else if(input == '3')
        {
            system("clear");
            return 0;
        }
        else
        {
            printf("\n");
            system("clear");
        }
    }
}

/** Calculator **/

void Calculate(void)
{
    system("clear");
    char input[1000] = {0};
    int i,j = 65;
    
    while(1){
        while(1)
        {
            printf("Input : ");
            fgets(input,1000,stdin);
            input[strlen(input)-1] = '\0'; // 엔터 삭제용
            //RemoveSpace(input); // 공백 삭제 함수
            
            if(strcmp(input,"!@#$") == 0) // Calculate 함수 종료 명령어
            {
                system("clear");
                return;
            }
            if(Input(input) == true) // 연산자가 포함된 식이 입력되면 Transforming 시작
                break;
            else
                continue;
        }
        Transformation(input);
        Postfix(input);
        //
        
        printf("결과 : %.2lf", Result(input));
        for(i = 0; i < strlen(input); i++)
            for(j = 0; j < strlen(input); j++)
                CalStack[i][j] = '\0';
        printf("\n\nENTER 키를 누르십시요");
        while(getchar() != '\n');
        system("clear");
    }
}

void RemoveSpace(char input[])
{
    int i = 0,j = 0;
    
    while(input[i] != '\0')
    {
        if(input[i] == ' ')
        {
            for(j = i; j < strlen(input) - 1; j++)
                input[j] = input[j+1];
            input[strlen(input)-1] = '\0';
        }
        i++;
    }
}

/** STACK **/

void Spush(char input) // 연산자를 받아와 Push
{
    top += 1;
    Stack[top] = input;
}

char Spop(void) // 연산자를 뽑아내는 Pop
{
    if(IsEmpty())
    {
        printf("Stack is Empty!\n");
        exit(-1); // 비정상적인 종료를 알림
    }
    char re = Stack[top];
    Stack[top] = '\0';
    top--;
    return re;
}

char Speek(void)
{
    return Stack[top];
}

bool IsEmpty(void)
{
    return top == -1 ? true : false;
}

/**  Calculator **/

void ProgramExit(void)
{
    system("clear");
    printf("Syntax Error!\n");
    sleep(2);
    system("clear");
    return;
}

bool Input(char input[])
{
    int i = 0,j = 0;
    char temp[1000] = {0};
    
    RemoveSpace(input); // 공백 삭제 함수
    
    while(input[i] != '\0')
    {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^')
        {
            if((input[i+1] >= 65 && input[i+1] <= 90) || (input[i+1] >= 48 && input[i+1] <= 57))
                return true;
            else if(input[i+1] >= 97 && input[i+1] <= 122)
                return true;
            else
            {
                ProgramExit();
                return false;
            }
        }
        i++;
    }
    
    if(input[0] >= 65 && input[0] <= 90)
    {
        if(input[1] == '=' && (input[2] >= 48 && input[2] <= 57))
        {
            for(i = 2; i < strlen(input); i++)
                temp[j++] = input[i];
            Alpha[input[0]-65] = 0; // 수를 넣기 전 이전에 있을 수 있는 수 초기화
            Alpha[input[0]-65] = atof(temp);
            strcpy(temp,"0"); // 초기화
            for(i = 0; i < 1000; i++)
                input[i] = '\0';
        }
        else
            ProgramExit();
    }
    return false;
}

void Transformation(char input[]) // math 함수나 문자 상수 처리하는 함수
{
    int i = 0;
    int j = 0;
    unsigned long int k,l,m;
    char temp[100] = {0};
    
    printf("Transformation : %s\n", input);
    sleep(2);
    
    while(input[i] != '\0')
    {
        if(input[i] >= 65 && input[i] <= 90)
        {
            gcvt(Alpha[input[i]-65], 10, temp);
            //sprintf(temp,"%.1lf",Alpha[input[i]-65]);
            k = strlen(temp)-1;
            while(k != 0) // temp를 대입할 만큼 input배열을 늘린다.
            {
                for(l = strlen(input)-1; l >= i+1; l--)
                    input[l+1] = input[l];
                k--;
            }
            m = 0;
            l = i;
            
            for(k = 0; k < strlen(temp); k++)
            {
                input[l] = temp[m++];
                l++;
            }
            printf("Transformation : %s\n", input);
            sleep(2);
            for(j = 0; j < 100; j++)
                temp[j] = '\0';
        }
        i++;
    }
    
    i = 0;
    
    while(input[i] != '\0')
    {
        unsigned long int len;
        int n;
        double num1,num2;
        double result;
        
        if((input[i] >= 97 && input[i] <= 122) || input[i] == '^')
        {
            if(input[i] == '^')
            {
                n = 0;
                len = 1;
                j = i-1;
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-' && input[j] != '(')
                {
                    if(j < 0)
                        break;
                    len++;
                    j--;
                }
                k = j+1; // 숫자가 시작되는 지점의 index저장
                for(m = j+1; m < i; m++)
                    temp[n++] = input[m];
                num1 = atof(temp);
                n = 0;
                for(m = 0; m < 100; m++)
                    temp[m] = '\0';
                
                j = i+1;
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-' && input[j] != '\0')
                {
                    len++;
                    j++;
                }
                for(m = i+1; m < j; m++)
                    temp[n++] = input[m];
                num2 = atof(temp);
                for(m = 0; m < 100; m++)
                    temp[m] = '\0';
                result = pow(num1,num2);
                gcvt(result, 10, temp);
            }
            else if(input[i] == 'r' && input[i+1] == 'o' && input[i+2] == 'o' && input[i+3] == 't')
            {
                if(!(input[i+4] >= 48 && input[i+4] <= 57))
                {
                    ProgramExit();
                    return;
                }
                m = 0;
                len = 4;
                j = i+4;
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-')
                {
                    if(input[j] == '\0')
                        break;
                    temp[m++] = input[j];
                    len++;
                    j++;
                }
                k = i;
                result = sqrt(atof(temp));
                gcvt(result, 10, temp);
            }
            else if(input[i] == 'l' && input[i+1] == 'o' && input[i+2] == 'g')
            {
                if(!(input[i+3] >= 48 && input[i+3] <= 57))
                {
                    ProgramExit();
                    return;
                }
                m = 0;
                len = 3;
                j = i+3;
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-')
                {
                    if(input[j] == '\0')
                        break;
                    temp[m++] = input[j];
                    len++;
                    j++;
                }
                k = i;
                result = log10(atof(temp));
                gcvt(result, 10, temp);
            }
            else if((input[i] == 's' && input[i+1] == 'i' && input[i+2] == 'n') || (input[i] == 'c' && input[i+1] == 'o' && input[i+2] == 's') || (input[i] == 't' && input[i+1] == 'a' && input[i+2] == 'n')) // sin cos tan 결과값 에러 !
            {
                if(!(input[i+3] >= 48 && input[i+3] <= 57))
                {
                    temp[0] = '4';
                    temp[1] = '5';
                    temp[2] = '\0';
                }
                m = 0;
                len = 3;
                j = i+3;
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-')
                {
                    if(input[j] == '\0')
                        break;
                    temp[m++] = input[j];
                    len++;
                    j++;
                }
                k = i;
                if(input[i] == 's')
                    result = sin(atof(temp)*3.1415/180);
                else if(input[i] == 'c')
                    result = cos(atof(temp)*3.1415/180);
                else if(input[i] == 't')
                    result = tan(atof(temp)*3.1415/180);
                gcvt(result, 10, temp);
            }
            else
            {
                ProgramExit();
                for(i = 0; i < 1000; i++)
                    input[i] = '\0';
                return;
            }
            n = 0;
            while(len != 0)
            {
                for(m = k; input[m] != '\0'; m++)
                    input[m] = input[m+1];
                len--;
            }
            len = strlen(temp);
            while(len != 0)
            {
                for(m = strlen(input)-1; m >= k; m--)
                    input[m+1] = input[m];
                len--;
            }
            for(m = k; m < strlen(temp)+k; m++)
                input[m] = temp[n++];
            for(m = 0; m < 100; m++)
                temp[m] = '\0';
            printf("Transformation : %s\n", input);
            sleep(2);
        }
        i++;
    }
}

void Postfix(char input[]) // 후위연산 기법으로 문자열 처리하는 함수
{
    int i = 0,j = 0, width = 0,height = 0;
    int m;
    
    while(input[i] != '\0')
    {
        if((input[i] >= 48 && input[i] <= 57) || input[i] == '.' || input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-' || input[i] == '(' || input[i] == ')')
            i++;
        else // 예외 처리
        {
            printf("Syntax Error!\n");
            return;
        }
    }
    
    i = 0;
    
    if(input[1] >= 48 && input[1] <= 57 && input[0] == '-') // 단항 연산자 - 처리1
        CalStack[0][width++] = input[i++];
    
    while(input[i] != '\0')
    {
        if(input[i] == '(' && input[i+1] == '-') // 단항 연산지 - 처리2
        {
            width = 0;
            CalStack[height][width++] = input[i+1];
            
            for(j = i+1; j < strlen(input); j++) // 단항 연산자 - 제거용
                input[j] = input[j+1];
        }
        while(1)
        {
            if((input[i] >= 48 && input[i] <= 57) || input[i] == '.')
            {
                while((input[i] >= 48 && input[i] <= 57) || input[i] == '.')
                    CalStack[height][width++] = input[i++];
                width = 0;
                height++;
            }
            else
            {
                printf("Postfix notation : ");
                for(m = 0; CalStack[m][0] != '\0'; m++)
                    printf("%s ", CalStack[m]);
                printf("\n");
                sleep(2);
                break;
            }
        }
        if(input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-' || input[i] == '(' || input[i] == ')')
        {
            if(IsEmpty())
                Spush(input[i++]);
            else
            {
                if(OperatorCmp(Speek(),input[i]) >= 0)
                {
                    if((Stack[0] == '+' || Stack[0] == '-') && input[i] == ')' && (input[i+1] == '*' || input[i+1] == '/'))
                    {
                        while(Speek() != '(')
                        {
                            width = 0;
                            CalStack[height++][width] = Spop();
                        }
                        Spop();
                        i++;
                        printf("Postfix notation : ");
                        for(m = 0; CalStack[m][0] != '\0'; m++)
                            printf("%s ", CalStack[m]);
                        printf("\n");
                        sleep(2);
                        continue;
                    }
                    while(input[i] != '(' && !IsEmpty())
                    {
                        if(Speek() != '(' && Speek() != ')')
                        {
                            width = 0;
                            CalStack[height++][width] = Spop();
                        }
                        else
                            Spop();
                    }
                    printf("Postfix notation : ");
                    for(m = 0; CalStack[m][0] != '\0'; m++)
                        printf("%s ", CalStack[m]);
                    printf("\n");
                    sleep(2);
                    Spush(input[i++]);
                }
                else
                    Spush(input[i++]);
            }
        }
    }
    //
    while(!IsEmpty())
    {
        if(Speek() != '(' && Speek() != ')')
        {
            width = 0;
            CalStack[height++][width] = Spop();
        }
        else
            Spop();
    }
    printf("Postfix notation : ");
    for(m = 0; CalStack[m][0] != '\0'; m++){
        printf("%s ", CalStack[m]);
    }
    printf("\n");
    
    sleep(2);
}

int OperatorCmp(char op1,char op2) // 연산자 우선순위 판단
{
    if(OperatorReturn(op1) > OperatorReturn(op2))
        return 1;
    else if(OperatorReturn(op1) < OperatorReturn(op2))
        return -1;
    else
        return 0;
}

int OperatorReturn(char op) // 연산자 리턴값 설정
{
    switch(op)
    {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
        case ')':
            return 1;
        default:
            return -1;
    }
}

double CalReturn(char op,double num1,double num2) // 계산 결과 리턴
{
    switch(op)
    {
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        default:
            ProgramExit();
            return 0;
    }
}


double Result(char input[])
{
    int i = 0,j,k;
    int cnt = 0,num = 0;
    double result;
    
    while(CalStack[i][0] != '\0')
    {
        if(CalStack[i][0] == '*' || CalStack[i][0] == '/' || CalStack[i][0] == '+' || CalStack[i][0] == '-')
        {
            if(CalStack[i][0] == '-' && CalStack[i][1] >= 48 && CalStack[i][1] <= 57)
                num++;
            else
                cnt++;
        }
        else if(CalStack[i][0] >= 48 && CalStack[i][0] <= 57)
            num++;
        i++;
    }
    if(num != cnt + 1)
    {
        system("clear");
        printf("Syntax Error!\n");
        //return;
    }
    i = 0;
    while(cnt != 0)
    {
        if(CalStack[i][0] == '*' || CalStack[i][0] == '/' || CalStack[i][0] == '+' || CalStack[i][0] == '-')
        {
            if(CalStack[i][0] == '-' && CalStack[i][1] >= 48 && CalStack[i][1] <= 57)
            {
                i++;
                continue;
            }
            
            result = CalReturn(CalStack[i][0],atof(CalStack[i-2]),atof(CalStack[i-1]));
            sprintf(CalStack[i-2],"%.2lf",result);
            
            k = i+1;
            for(j = i-1; CalStack[k][0] != '\0'; j++)
                strcpy(CalStack[j],CalStack[k++]);
            i = 0;
            cnt--;
            continue;
        }
        else if(CalStack[i][0] < 48 || CalStack[i][0] > 57)
        {
            system("clear");
            printf("Syntax Error!\n");
            break;
        }
        i++;
    }
    return atof(CalStack[0]);
}

/** Schedule **/

void Schedule(void)
{
    system("clear");
}
