//
//  Schedulator
//
//  Created by Codejune on 2016. 5. 25.
//  Copyright © 2016년 Codejune. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 100

// 공학용 계산기
void EngineeringCalculator(void);
void SaveVariable(char*);
void Transformation(char*);

// 일정 관리
void ScheduleManagement(void);

// 기타 함수
void Pause(void);
void Terminal_Clear(void);

// 전역 변수
double variable[26];


// Project :: 메인 함수
int main(void) {
    int select_function=TRUE;
    while(select_function != 0){
        Terminal_Clear();
        printf("프로그래밍 및 실습 프로젝트\n");
        printf("[1] 공학용 계산기\n");
        printf("[2] 일정 관리\n");
        printf("[0] 프로그램 종료\n");
        printf("선택 : ");
        scanf("%d", &select_function);
        // 버퍼초기화
        getchar();
        Terminal_Clear();
        switch (select_function) {
            case 0:
                Terminal_Clear();
                return 0;
                
            case 1:
                EngineeringCalculator();
                break;
                
            case 2:
                ScheduleManagement();
                break;
                
            default:
                printf("잘못 입력하셨습니다. 다시 입력해주세요\n");
                Pause();
                break;
        }
    }
    return 0;
}

// 공학용 계산기 :: 메인
void EngineeringCalculator(void){
    char formular[MAX_STACK_SIZE];
    int judgeFormular=FALSE;
    int i;
    
    while(1){
        printf("Input : ");
        // 버퍼초기화
        //getchar();
        //scanf("%[^\n]", formular);
        fgets(formular,100,stdin);
        formular[strlen(formular)-1] = '\0';
        
        // 수식 판단
        for(i=0; formular[i] != '\0'; i++){
            if(formular[i]=='='){
                judgeFormular = TRUE;
                break;
            } else {
                judgeFormular = FALSE;
            }
        }
        
        switch (judgeFormular) {
            case 0 :
                Transformation(formular);
                break;
                
            case 1 :
                SaveVariable(formular);
                break;
                
            default:
                break;
        }
    }
}

// 공학용 계산기 :: 변수 지정
void SaveVariable(char* formular){
    int total_count = 0, i, j;
    char value[10];
    
    // Debug Code :: Formular Check
    //printf("Debug Log(Formular) : %s\n", formular);
    // ' ' 제거
    for(i=0; formular[i] != '\0'; i++){
        if(formular[i] == ' '){
            // 스택 재정렬
            for(j=i; formular[j] != '\0'; j++) {
                formular[j] = formular[j+1];
            }
        }
    }
    // Debug Code :: Formular Check
    //printf("Debug Log(Remove ' ') : %s\n", formular);
    
    // '=' 문자 제거
    for(i=0;i<formular[i] != '\0'; i++){
        if(formular[i]=='='){
            for(j=i; formular[j] != '\0'; j++) {
                formular[j] = formular[j+1];
            }
        }
        total_count++;
    }
    
    // Debug Code :: Formular Check
    //printf("Debug Log(Remove '=') : %s\n", formular);
    
    if('A' <= formular[0] && formular[0]<='Z'){
        for(i=1, j=0; i<=total_count; i++){
            value[j++] = formular[i];
            // 변수 값 저장
            variable[formular[0]-65] = atof(value);
        }
        // Debug Code :: AtoF Value Check
        //printf("Debug Log(AtoF Value) : %f\n", atof(value));
        
        
        // Debug Code :: Check Variable
        //printf("Debug Log(Variable) : variable[%d] = %d\n", formular[0]-65, variable[formular[0]-65]);
        
    } else {
        printf("변수는 A~Z로 입력해주세요\n");
        Pause();
        Terminal_Clear();
    }
    
    // 배열 초기화
    for(i=0;i<total_count; i++){
        formular[i] = '\0';
    }
    
    // Debug Code :: Check Variable
    /*
     for(i=0; i<26; i++){
     printf("Debug Log(Variable) : %c = %f\n", i+65, variable[i]);
     }
     */
}

// 공학용 계산기 :: 수식 인식
void Transformation(char* formular){
    int i = 0;
    int j = 0;
    unsigned long int k, l, m;
    char temp[100] = {0};
    
    printf("Transformation : %s\n", formular);
    //sleep(2);
    
    while(formular[i] != '\0')
    {
        if(formular[i] >= 65 && formular[i] <= 90)
        {
            sprintf(temp,"%.2lf",variable[formular[i]-65]);
            k = strlen(temp)-1;
            while(k != 0) // temp를 대입할 만큼 input배열을 늘린다.
            {
                for(l = strlen(formular)-1; l >= i+1; l--)
                    formular[l+1] = formular[l];
                k--;
            }
            m = 0;
            l = i;
            
            for(k = 0; k < strlen(temp); k++)
            {
                formular[l] = temp[m++];
                l++;
            }
            printf("Transformation : %s\n", formular);
            //sleep(2);
            for(j = 0; j < 100; j++)
                temp[j] = '\0';
        }
        i++;
    }
    
    i = 0;
    
    while(formular[i] != '\0')
    {
        unsigned long int len;
        int n;
        double num1,num2;
        double result;
        
        if((formular[i] >= 97 && formular[i] <= 122) || formular[i] == '^')
        {
            if(formular[i] == '^')
            {
                n = 0;
                len = 1;
                j = i-1;
                while(formular[j] != '*' && formular[j] != '/' && formular[j] != '+' && formular[j] != '-' && formular[j] != '(')
                {
                    if(j < 0)
                        break;
                    len++;
                    j--;
                }
                k = j+1; // 숫자가 시작되는 지점의 index저장
                for(m = j+1; m < i; m++)
                    temp[n++] = formular[m];
                num1 = atof(temp);
                n = 0;
                for(m = 0; m < 100; m++)
                    temp[m] = '\0';
                
                j = i+1;
                while(formular[j] != '*' && formular[j] != '/' && formular[j] != '+' && formular[j] != '-' && formular[j] != '\0')
                {
                    len++;
                    j++;
                }
                for(m = i+1; m < j; m++)
                    temp[n++] = formular[m];
                num2 = atof(temp);
                for(m = 0; m < 100; m++)
                    temp[m] = '\0';
                result = pow(num1,num2);
                sprintf(temp,"%.2f", result);
            }
            else if(formular[i] == 'r' && formular[i+1] == 'o' && formular[i+2] == 'o' && formular[i+3] == 't')
            {
                if(!(formular[i+4] >= 48 && formular[i+4] <= 57))
                {
                    //ProgramExit();
                    return;
                }
                m = 0;
                len = 4;
                j = i+4;
                while(formular[j] != '*' && formular[j] != '/' && formular[j] != '+' && formular[j] != '-')
                {
                    if(formular[j] == '\0')
                        break;
                    temp[m++] = formular[j];
                    len++;
                    j++;
                }
                k = i;
                result = sqrt(atof(temp));
                sprintf(temp,"%.2f", result);
            }
            else if(formular[i] == 'l' && formular[i+1] == 'o' && formular[i+2] == 'g')
            {
                if(!(formular[i+3] >= 48 && formular[i+3] <= 57))
                {
                    return;
                }
                m = 0;
                len = 3;
                j = i+3;
                while(formular[j] != '*' && formular[j] != '/' && formular[j] != '+' && formular[j] != '-')
                {
                    if(formular[j] == '\0')
                        break;
                    temp[m++] = formular[j];
                    len++;
                    j++;
                }
                k = i;
                result = log10(atof(temp));
                sprintf(temp,"%.2f", result);
            }
            else if((formular[i] == 's' && formular[i+1] == 'i' && formular[i+2] == 'n') || (formular[i] == 'c' && formular[i+1] == 'o' && formular[i+2] == 's') || (formular[i] == 't' && formular[i+1] == 'a' && formular[i+2] == 'n')) // sin cos tan 결과값 에러 !
            {
                if(!(formular[i+3] >= 48 && formular[i+3] <= 57))
                {
                    temp[0] = '4';
                    temp[1] = '5';
                    temp[2] = '\0';
                }
                m = 0;
                len = 3;
                j = i+3;
                while(formular[j] != '*' && formular[j] != '/' && formular[j] != '+' && formular[j] != '-')
                {
                    if(formular[j] == '\0')
                        break;
                    temp[m++] = formular[j];
                    len++;
                    j++;
                }
                k = i;
                if(formular[i] == 's')
                    result = sin(atof(temp)*3.1415/180);
                else if(formular[i] == 'c')
                    result = cos(atof(temp)*3.1415/180);
                else if(formular[i] == 't')
                    result = tan(atof(temp)*3.1415/180);
                sprintf(temp,"%.2f", result);
            }
            else
            {
                for(i = 0; i < 1000; i++)
                    formular[i] = '\0';
                return;
            }
            n = 0;
            while(len != 0)
            {
                for(m = k; formular[m] != '\0'; m++)
                    formular[m] = formular[m+1];
                len--;
            }
            len = strlen(temp);
            while(len != 0)
            {
                for(m = strlen(formular)-1; m >= k; m--)
                    formular[m+1] = formular[m];
                len--;
            }
            for(m = k; m < strlen(temp)+k; m++)
                formular[m] = temp[n++];
            for(m = 0; m < 100; m++)
                temp[m] = '\0';
            printf("Transformation : %s\n", formular);
            //sleep(2);
        }
        i++;
    }
    
}


// 일정 관리 :: 메인
void ScheduleManagement(void){
    printf("일정 관리\n");
    Pause();
}

// 기타 함수 :: 일시정지
void Pause(void){
    printf("아무키나 입력하세요...\n");
    getchar();
}

// 기타 함수 :: 터미널 지우기
void Terminal_Clear(void){
    system("clear");
}