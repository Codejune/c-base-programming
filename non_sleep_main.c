/****************************************************
 *   School     : Soongsil University               *
 *   Major      : Computer Science                  *
 *   Subject    : Progeamming1 & Practice           *
 *   Prof       : Mun Young Song                    *
 *   Student ID : 20162448                          *
 *   Author     : Kim Byoung June                   *
 *   Date       : 2016. 06. 09 (thr)                *
 ****************************************************/

/****************************************************
 *                  Include Header                  *
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


/****************************************************
 *                  Global Variables                *
 ****************************************************/

int top = -1;                       // Remove Null Value

int ccnt = 0;

double Variable[26];                // Variable Value

char Stack[1000] = {0};             // Operand Stack

char CalStack[BUFSIZ][1000] = {0};  // Operator Stack


/****************************************************
 *                  Stack Function                  *
 ****************************************************/

void Spush(char);   // Push Operator to Stack

char Spop(void);    // Pull Operator from Stack

char Speek(void);   // Top of Stack

bool IsEmpty(void); // Check Stack is Empty


/****************************************************
 *          Scientific Calculate Function           *
 ****************************************************/

void ScientificCalculate(void);         // Main Function of Scientific Calculator

void RemoveSpace(char []);              // Remove Space

bool Input(char []);                    // Organize Input String

void Transformation(char []);           // Dipose of Math Function or Character Variable

void Postfix(char []);                  // Organize Input to Postfix Formular

int OperatorCmp(char, char);            // Judgement Operator Precedence

int OperatorReturn(char);               // Define Operator Return Value

double Result(char []);                 // Calculate

double CalReturn(char, double, double); // Return Calculate Result


/****************************************************
 *            Schedule Management Function          *
 ****************************************************/

void ScheduleManagement(void);                          // Main Function of Schedule Management

void SortSchedule(int (*)[100], char (*)[100], int);    // Ascending Sort Schedule

void ViewSchedule(int (*)[100], char (*)[100], int);    // View Schedule on Calendar

void ClearSchedule(int (*)[100], char (*)[100], int);   // Reset Schedule


/****************************************************
 *             Other Function(ETC, Debug)           *
 ****************************************************/

void TerminalClear(void);   // Clear Terminal

void Pause(void);           // Pause Program

void SyntaxError(void);     // Syntax Error

/****************************************************
 *                  Main Function                   *
 ****************************************************/

int main(void) {
    char select_function;
    while(1)
    {
        TerminalClear();
        printf("1. 공학용 계산기\n");
        printf("2. 스케줄 관리  \n");
        printf("3. 프로그램 종료\n");
        printf("입력 : ");
        scanf("%c", &select_function);
        getchar();
        TerminalClear();
        if(select_function == '1') {
            ScientificCalculate();
        } else if(select_function == '2') {
            ScheduleManagement();
        } else if(select_function == '3') {
            return 0;
        } else {
            printf("잘못 입력하였습니다. 다시 입력해주세요.\n");
            Pause();
        }
    }
}


/****************************************************
 *                      Spush                       *
 ****************************************************/

void Spush(char input)
{
    top += 1;
    Stack[top] = input;
}


/****************************************************
 *                       Spop                       *
 ****************************************************/

char Spop(void)
{
    if(IsEmpty())
    {
        printf("Stack is Empty!\n");
        // Alram Abnormal Termination
        exit(-1);
    }
    char re = Stack[top];
    Stack[top] = '\0';
    top--;
    return re;
}


/****************************************************
 *                      Speek                       *
 ****************************************************/

char Speek(void)
{
    return Stack[top];
}


/****************************************************
 *                      IsEmpty                     *
 ****************************************************/

bool IsEmpty(void)
{
    return top == -1 ? true : false;
}


/****************************************************
 *                ScientificCalculate               *
 ****************************************************/

void ScientificCalculate(void){
    
    char input[1000] = {0};
    int i,j = 65;
    
    while(1){
        while(1){
            printf("Input : ");
            fgets(input,1000,stdin);
            
            // Remove Enter Buffer
            input[strlen(input)-1] = '\0';
            
            // Function Exit
            if(strcmp(input,"!@#$") == 0) {
                TerminalClear();
                return;
            }
            
            // Judgement Formular
            if(Input(input) == true) {
                break;
            } else {
                continue;
            }
        }
        
        Transformation(input);
        Postfix(input);
        
        printf("결과 : %.2lf", Result(input));
        for(i = 0; i < strlen(input); i++) {
            for(j = 0; j < strlen(input); j++) {
                CalStack[i][j] = '\0';
            }
        }
        printf("\n\nPress Enter Key...");
        while(getchar() != '\n');
        TerminalClear();
    }
}


/****************************************************
 *                   RemoveSpace                    *
 ****************************************************/

void RemoveSpace(char input[]) {
    
    int i=0, j=0;
    
    while(input[i] != '\0'){
        if(input[i] == ' '){
            for(j = i; j < strlen(input) - 1; j++) {
                input[j] = input[j+1];
            }
            input[strlen(input)-1] = '\0';
        }
        i++;
    }
}


/****************************************************
 *                      Input                       *
 ****************************************************/

bool Input(char input[])
{
    int i = 0,j = 0;
    char temp[1000] = {0};
    
    RemoveSpace(input);
    
    while(input[i] != '\0') {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^') {
            if((input[i+1] >= 65 && input[i+1] <= 90) || (input[i+1] >= 48 && input[i+1] <= 57)) {
                return true;
            } else if(input[i+1] >= 97 && input[i+1] <= 122) {
                return true;
            } else {
                SyntaxError();
                return false;
            }
        }
        i++;
    }
    
    if(input[0] >= 65 && input[0] <= 90) {
        if(input[1] == '=' && (input[2] >= 48 && input[2] <= 57)) {
            for(i = 2; i < strlen(input); i++) {
                temp[j++] = input[i];
            }
            
            // Reset Variable
            Variable[input[0]-65] = 0;
            
            // Set Variable
            Variable[input[0]-65] = atof(temp);
            
            // Reset Temp
            strcpy(temp,"0");
            for(i = 0; i < 1000; i++)
                input[i] = '\0';
        } else {
            SyntaxError();
        }
    }
    return false;
}


/****************************************************
 *                  Transformation                  *
 ****************************************************/

void Transformation(char input[]) {
    int i = 0, j = 0;
    unsigned long int k = 0, l = 0, m = 0;
    char temp[100] = {0};
    
    printf("Transformation : %s\n", input);
    //sleep(2);
    
    while(input[i] != '\0') {
        if(input[i] >= 65 && input[i] <= 90) {
            gcvt(Variable[input[i]-65], 10, temp);
            k = strlen(temp)-1;
            
            // Increase Input Array as Temp Size
            while(k != 0) {
                for(l = strlen(input)-1; l >= i+1; l--) {
                    input[l+1] = input[l];
                }
                k--;
            }
            
            m = 0;
            l = i;
            
            for(k = 0; k < strlen(temp); k++) {
                input[l] = temp[m++];
                l++;
            }
            printf("Transformation : %s\n", input);
            //sleep(2);
            for(j = 0; j < 100; j++) {
                temp[j] = '\0';
            }
        }
        i++;
    }
    i = 0;
    
    while(input[i] != '\0') {
        
        unsigned long int len;
        int n;
        double num1, num2, result;
        
        if((input[i] >= 97 && input[i] <= 122) || input[i] == '^') {
            if(input[i] == '^') {
                n = 0;
                len = 1;
                j = i-1;
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-' && input[j] != '(') {
                    if(j < 0) {
                        break;
                    }
                    len++;
                    j--;
                }
                
                // Save Start Number Index(position)
                k = j+1;
                for(m = j+1; m < i; m++) {
                    temp[n++] = input[m];
                }
                
                num1 = atof(temp);
                n = 0;
                
                for(m = 0; m < 100; m++) {
                    temp[m] = '\0';
                }
                
                j = i+1;
                
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-' && input[j] != '\0') {
                    len++;
                    j++;
                }
                for(m = i+1; m < j; m++) {
                    temp[n++] = input[m];
                }
                
                num2 = atof(temp);
                
                for(m = 0; m < 100; m++) {
                    temp[m] = '\0';
                }
                
                result = pow(num1,num2);
                gcvt(result, 10, temp);
                
            } else if(input[i] == 'r' && input[i+1] == 'o' && input[i+2] == 'o' && input[i+3] == 't') {
                if(!(input[i+4] >= 48 && input[i+4] <= 57)) {
                    SyntaxError();
                    return;
                }
                
                m = 0;
                len = 4;
                j = i+4;
                
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-')
                {
                    if(input[j] == '\0') {
                        break;
                    }
                    
                    temp[m++] = input[j];
                    len++;
                    j++;
                }
                
                k = i;
                result = sqrt(atof(temp));
                gcvt(result, 10, temp);
            } else if(input[i] == 'l' && input[i+1] == 'o' && input[i+2] == 'g') {
                if(!(input[i+3] >= 48 && input[i+3] <= 57)) {
                    SyntaxError();
                    return;
                }
                
                m = 0;
                len = 3;
                j = i+3;
                
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-') {
                    if(input[j] == '\0') {
                        break;
                    }
                    
                    temp[m++] = input[j];
                    len++;
                    j++;
                }
                
                k = i;
                result = log10(atof(temp));
                gcvt(result, 10, temp);
                
            } else if((input[i] == 's' && input[i+1] == 'i' && input[i+2] == 'n') || (input[i] == 'c' && input[i+1] == 'o' && input[i+2] == 's') || (input[i] == 't' && input[i+1] == 'a' && input[i+2] == 'n')) {
                if(!(input[i+3] >= 48 && input[i+3] <= 57)) {
                    temp[0] = '4';
                    temp[1] = '5';
                    temp[2] = '\0';
                }
                
                m = 0;
                len = 3;
                j = i+3;
                
                while(input[j] != '*' && input[j] != '/' && input[j] != '+' && input[j] != '-') {
                    if(input[j] == '\0') {
                        break;
                    }
                    
                    temp[m++] = input[j];
                    len++;
                    j++;
                }
                k = i;
                if(input[i] == 's') {
                    result = sin(atof(temp)*3.1415/180);
                } else if(input[i] == 'c') {
                    result = cos(atof(temp)*3.1415/180);
                } else if(input[i] == 't') {
                    result = tan(atof(temp)*3.1415/180);
                }
                
                gcvt(result, 10, temp);
            } else {
                SyntaxError();
                for(i = 0; i < 1000; i++) {
                    input[i] = '\0';
                }
                
                return;
            }
            
            n = 0;
            
            while(len != 0) {
                for(m = k; input[m] != '\0'; m++) {
                    input[m] = input[m+1];
                }
                
                len--;
            }
            
            len = strlen(temp);
            while(len != 0) {
                for(m = strlen(input)-1; m >= k; m--) {
                    input[m+1] = input[m];
                }
                
                len--;
            }
            
            for(m = k; m < strlen(temp)+k; m++) {
                input[m] = temp[n++];
            }
            
            for(m = 0; m < 100; m++) {
                temp[m] = '\0';
            }
            
            printf("Transformation : %s\n", input);
            //sleep(2);
        }
        i++;
    }
}


/****************************************************
 *                      Postfix                     *
 ****************************************************/

void Postfix(char input[]) {
    
    int i=0, j=0, width=0, height=0;
    int m;
    
    while(input[i] != '\0') {
        if((input[i] >= 48 && input[i] <= 57) || input[i] == '.' || input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-' || input[i] == '(' || input[i] == ')') {
            i++;
        } else {
            printf("Syntax Error!\n");
            return;
        }
    }
    
    i = 0;
    
    // Unary Operator - Dispose 1
    if(input[1] >= 48 && input[1] <= 57 && input[0] == '-') {
        CalStack[0][width++] = input[i++];
    }
    
    // Unary Operator - Dispose 2
    while(input[i] != '\0') {
        if(input[i] == '(' && input[i+1] == '-') {
            
            width = 0;
            CalStack[height][width++] = input[i+1];
            
            // Unary Operator - Remove
            for(j = i+1; j < strlen(input); j++) {
                input[j] = input[j+1];
            }
        }
        
        while(1) {
            if((input[i] >= 48 && input[i] <= 57) || input[i] == '.') {
                while((input[i] >= 48 && input[i] <= 57) || input[i] == '.') {
                    CalStack[height][width++] = input[i++];
                }
                width = 0;
                height++;
            }
            else
            {
                printf("Postfix notation : ");
                for(m = 0; CalStack[m][0] != '\0'; m++)
                    printf("%s ", CalStack[m]);
                printf("\n");
                //sleep(2);
                break;
            }
        }
        
        if(input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-' || input[i] == '(' || input[i] == ')') {
            if(IsEmpty()) {
                Spush(input[i++]);
            } else {
                if(OperatorCmp(Speek(),input[i]) >= 0) {
                    if((Stack[0] == '+' || Stack[0] == '-') && input[i] == ')' && (input[i+1] == '*' || input[i+1] == '/')) {
                        while(Speek() != '(') {
                            width = 0;
                            CalStack[height++][width] = Spop();
                        }
                        
                        Spop();
                        i++;
                        printf("Postfix notation : ");
                        
                        for(m = 0; CalStack[m][0] != '\0'; m++) {
                            printf("%s ", CalStack[m]);
                        }
                        
                        printf("\n");
                        //sleep(2);
                        continue;
                    }
                    
                    while(input[i] != '(' && !IsEmpty()) {
                        if(Speek() != '(' && Speek() != ')') {
                            width = 0;
                            CalStack[height++][width] = Spop();
                        } else {
                            Spop();
                        }
                    }
                    
                    printf("Postfix notation : ");
                    for(m = 0; CalStack[m][0] != '\0'; m++)
                        printf("%s ", CalStack[m]);
                    printf("\n");
                    //sleep(2);
                    Spush(input[i++]);
                } else {
                    Spush(input[i++]);
                }
            }
        }
    }
    //
    while(!IsEmpty()) {
        if(Speek() != '(' && Speek() != ')') {
            width = 0;
            CalStack[height++][width] = Spop();
        } else {
            Spop();
        }
    }
    
    printf("Postfix notation : ");
    for(m = 0; CalStack[m][0] != '\0'; m++){
        printf("%s ", CalStack[m]);
        ccnt++;
    }
    
    printf("\n");
    
    //sleep(2);
}


/****************************************************
 *                     OperatorCmp                  *
 ****************************************************/
int OperatorCmp(char op1,char op2) {
    if(OperatorReturn(op1) > OperatorReturn(op2)) {
        return 1;
    } else if(OperatorReturn(op1) < OperatorReturn(op2)) {
        return -1;
    } else {
        return 0;
    }
}


/****************************************************
 *                  OperatorReturn                  *
 ****************************************************/
int OperatorReturn(char op) {
    switch(op) {
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


/****************************************************
 *                      CalReturn                   *
 ****************************************************/
double CalReturn(char op,double num1,double num2) {
    switch(op) {
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        default:
            SyntaxError();
            return 0;
    }
}


/****************************************************
 *                      Result                      *
 ****************************************************/
double Result(char input[]) {
    int i = 0,j,k, m, l;
    int cnt = 0,num = 0;
    double result;
    char temp[100] = {0};
    
    while(CalStack[i][0] != '\0') {
        if(CalStack[i][0] == '*' || CalStack[i][0] == '/' || CalStack[i][0] == '+' || CalStack[i][0] == '-') {
            if(CalStack[i][0] == '-' && CalStack[i][1] >= 48 && CalStack[i][1] <= 57) {
                num++;
            } else {
                cnt++;
            }
        } else if(CalStack[i][0] >= 48 && CalStack[i][0] <= 57) {
            num++;
        }
        i++;
    }
    if(num != cnt + 1) {
        system("clear");
        printf("Syntax Error!\n");
    }
    i = 0;
    while(cnt != 0) {
        if(CalStack[i][0] == '*' || CalStack[i][0] == '/' || CalStack[i][0] == '+' || CalStack[i][0] == '-') {
            if(CalStack[i][0] == '-' && CalStack[i][1] >= 48 && CalStack[i][1] <= 57) {
                i++;
                continue;
            }
            
            result = CalReturn(CalStack[i][0],atof(CalStack[i-2]),atof(CalStack[i-1]));
            
            gcvt(result, 10, CalStack[i-2]);
            
            k = i+1;
            
            for(j = i-1; CalStack[k][0] != '\0'; j++) {
                strcpy(CalStack[j],CalStack[k++]);
                i++;
            }
            ccnt-=2;
            
            printf("Postfix notation : ");
            for(m = 0; m < ccnt; m++){
                printf("%s ", CalStack[m]);
            }
            printf("\n");
            i = 0;
            cnt--;
            continue;
        } else if(CalStack[i][0] < 48 || CalStack[i][0] > 57) {
            printf("Syntax Error!\n");
            break;
        }
        i++;
    }
    return atof(CalStack[0]);
}


/****************************************************
 *                 ScheduleManagement               *
 ****************************************************/

void ScheduleManagement(void) {
    
    /***
     *              ---------------------- ... 100
     *   year     | [0][0]  [0][1]  [0][2]
     *   month    | [1][0]  [1][1]  [1][2]
     *   day      | [2][0]  [2][1]  [2][2]
     *            3
     ***/
    int date[3][100];
    
    /***
     *                 ---------------------- ... 100
     *   content[0]  | [0][0]  [0][1]  [0][2]
     *   content[1]  | [1][0]  [1][1]  [1][2]
     *   content[2]  | [2][0]  [2][1]  [2][2]
     *           .
     *           .
     *           .
     *          100
     ***/
    char content[100][100] = {0};
    char tmp_content[100] = {0};
    int select_function = 1, i = 0, j = 0, k = 0;
    int tmp_year, tmp_month, tmp_day;
    unsigned long int len = 0;
    char select_answer;
    
    while(select_function != 0){
        
        TerminalClear();
        printf("1. 스케줄 입력\n");
        printf("2. 스케줄 삭제\n");
        printf("3. 스케줄 보기\n");
        printf("4. Main menu\n");
        printf("메뉴 : ");
        scanf("%d",&select_function);
        
        TerminalClear();
        switch(select_function) {
            case 1:
                printf("입력 : ");
                scanf("%d %d %d %s", &date[0][i], &date[1][i], &date[2][i], content[i]);
                printf("출력 : %d %d %d %s\n", date[0][i], date[1][i], date[2][i], content[i]);
                
                // Check Leap
                if((date[1][i]==2 && (date[0][i] % 4 == 0 && date[0][i] % 100 != 0)) || date[0][i] % 400 == 0) {
                    if((date[2][i]<1)||(date[2][i]>29)) {
                        printf("잘못된 일을 입력하였습니다. 1일에서 29일 사이로 입력하세요\n\n");
                        ClearSchedule(date, content, i);
                        SortSchedule(date, content, i);
                        i++;
                        Pause();
                        break;
                    }
                } else if(date[1][i] == 2) {
                    if(date[2][i] < 1 || date[2][i] > 28) {
                        printf("잘못된 일을 입력하였습니다. 1일에서 28일 사이로 입력하세요\n\n");
                        ClearSchedule(date, content, i);
                        SortSchedule(date, content, i);
                        i++;
                        Pause();
                        break;
                    }
                } else if(date[1][i] ==1 || date[1][i] == 3 || date[1][i] == 5 || date[1][i] == 7 || date[1][i] == 8 || date[1][i] == 10 || date[1][i] == 12) {
                    if(date[2][i] < 1 || date[2][i] > 31) {
                        printf("잘못된 일을 입력하였습니다. 1일에서 31일 사이로 입력하세요\n\n");
                        ClearSchedule(date, content, i);
                        SortSchedule(date, content, i);
                        i++;
                        Pause();
                        break;
                    }
                } else {
                    if(date[2][i] < 1 || date[2][i] > 30) {
                        printf("잘못된 일을 입력하였습니다. 1일에서 30일 사이로 입력하세요\n\n");
                        ClearSchedule(date, content, i);
                        SortSchedule(date, content, i);
                        i++;
                        Pause();
                        break;
                    }
                }
                
                len = strlen(content[i]);
                if((date[0][i] <= 0)) {
                    printf("잘못된 년도를 입력하였습니다. 다시 입력하세요.\n\n");
                    ClearSchedule(date, content, i);
                } else if(date[1][i] < 1 || date[1][i] > 12) {
                    printf("잘못된 월을 입력하였습니다. 1월에서 12월 사이로 다시 입력하세요.\n\n");
                    ClearSchedule(date, content, i);
                } else if(date[2][i] <= 0 || date[2][i] >= 32) {
                    printf("잘못된 일을 입력하였습니다. 다시 입력하세요.\n\n");
                    ClearSchedule(date, content, i);
                } else if (len > 16) {
                    printf("너무 많은 내용을 입력하셨습니다\n\n");
                    ClearSchedule(date, content, i);
                } else {
                    if(i==0){
                        printf("일정을 추가하였습니다.\n");
                    }
                    for(j = 0; j < i; j++){
                        if(date[0][i] == date[0][j] && date[1][i] == date[1][j] && date[2][i] == date[2][j]){
                            while(1){
                                printf("%d년 %d월 %d일에 일정이 있습니다.\n", date[0][i], date[1][i], date[2][i]);
                                printf("일정을 추가하려면 Yes를, 덮어쓰려면 No를 입력하세요 : ");
                                scanf("%s", &select_answer);
                                // Add Schedule
                                switch (select_answer) {
                                    case 'y':
                                        strcat(content[j], ".");
                                        strcat(content[j], content[i]);
                                        ClearSchedule(date, content, i);
                                        printf("일정을 추가하였습니다.\n");
                                        break;
                                        
                                        
                                    case 'Y':
                                        strcat(content[j], ".");
                                        strcat(content[j], content[i]);
                                        ClearSchedule(date, content, i);
                                        printf("일정을 추가하였습니다.\n");
                                        break;
                                        
                                        
                                        // Override Schedule
                                    case 'n':
                                        ClearSchedule(date, content, j);
                                        printf("일정을 덮어쓰기하였습니다.\n");
                                        break;
                                        
                                        
                                    case 'N':
                                        ClearSchedule(date, content, j);
                                        printf("일정을 덮어쓰기하였습니다.\n");
                                        break;
                                        
                                        
                                    default:
                                        printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
                                        Pause();
                                        break;
                                }
                                break;
                            }
                            break;
                        } else {
                            if(j == i-1){
                                printf("일정을 추가하였습니다.\n");
                                break;
                            }
                        }
                    }
                }
                
                SortSchedule(date, content, i);
                
                i++;
                
                Pause();
                break;
                
                // Delete Schedule
            case 2:
                printf("입력 : ");
                scanf("%d %d %d %s", &tmp_year, &tmp_month, &tmp_day, tmp_content);
                int equality_date = false;
                for(j=0; j<100; j++){
                    if(date[0][j] == tmp_year && date[1][j] == tmp_month && date[2][j] == tmp_day){
                        
                        int equality_content = false;
                        for(k=0; k<=strlen(content[j]); k++){
                            if(content[j][k] == tmp_content[k]){
                                equality_content = true;
                            } else {
                                equality_content = true;
                                break;
                            }
                        }
                        
                        if(equality_content == true){
                            printf("%d년 %d월 %d일에 일정을 삭제하였습니다.\n", tmp_year, tmp_month, tmp_day);
                            ClearSchedule(date, content, j);
                            equality_date = true;
                            
                        } else {
                            equality_date = false;
                        }
                    }
                }
                if(equality_date == false){
                    printf("%d년 %d월 %d일에 일정이 없습니다.\n", tmp_year, tmp_month, tmp_day);
                }
                Pause();
                break;
                
                // View Schedule
            case 3:
                getchar();
                if(date[0][i-1] != 0 && date[1][i-1] != 0 && date[2][i-1] != 0){
                    ViewSchedule(date, content, i);
                } else {
                    printf("등록된 일정이 없습니다.\n");
                    Pause();
                }
                break;
                
                
                // Exit Function
            case 4:
                getchar();
                return;
                
            default:
                printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
                Pause();
                break;
        }
    }
}


/****************************************************
 *                   ClearSchedule                  *
 ****************************************************/

void ClearSchedule(int (*date)[100], char (*content)[100], int i){
    
    int j = 0;
    
    date[0][i] = 0;
    date[1][i] = 0;
    date[2][i] = 0;
    for(j = 0; j <= strlen(content[i]); j++){
        content[i][j] = '\0';
    }
}


/****************************************************
 *                    ViewSchedule                  *
 ****************************************************/

void ViewSchedule(int (*date)[100], char (*content)[100], int cnt){
    int month_array[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i = 0, j = 0, k = 0, l = 0;
    int total_year, total_month, total_day;
    int cycle, count, total_count, blank_count, space_count, blank_check;
    int dal;
    
    for(i = 0; i <= cnt; i++){
        if(date[0][i] == 0 || date[1][i] == 0 || date[2][i] == 0){
            
        } else {
            
            TerminalClear();
            total_year = 0;
            total_month = 1;
            cycle = 0;
            count = 1;
            total_count = 1;
            blank_count = 0;
            space_count = 0;
            blank_check = 0;
            total_day = 0;
            
            // Calculate All of Year
            for(j = 0; j<date[0][i] - 1; j++) {
                // Judge Leap Year
                if((((j + 1) % 4) == 0 && (((j + 1) % 100) != 0)) || (((j + 1) % 400) == 0)) {
                    dal = 366;
                } else {
                    dal = 365;
                }
                total_year += dal;
            }
            
            // Calculate All of Month
            for(j = 0; j < date[1][i]-1; j++) {
                // Judge Leap Month
                if(((date[0][i] % 4) == 0 && ((date[0][i] % 100) != 0)) || ((date[0][i] % 400) == 0)) {
                    month_array[1] = 29;
                } else {
                    month_array[1] = 28;
                }
                total_month += month_array[j];
            }
            
            total_day = total_year + total_month;
            
            printf("\n");
            printf("             %d년 %d월\n", date[0][i], date[1][i]);
            printf("---------------------------------------\n");
            printf("   SUN  MON  TUE  WED  THU  FRI  SAT\n");
            printf("---------------------------------------\n");
            
            count = 1;
            // Add Start Space
            for(j = 1; j <= ((total_day % 7) % 7); j++) {
                printf("     ");
                count++;
                total_count++;
                space_count++;
                blank_check = j-1;
                
            }
            
            
            // Add Day
            for(j = 1; j <= month_array[date[1][i]-1]; j++) {
                printf("%5d",j);
                
                if(date[2][i]==total_count-space_count){
                    blank_count = count;
                }
                
                if((j +(total_day % 7)) % 7 == 0) {
                    if(cycle == ((date[2][i]+blank_check)/7)){
                        printf("\n");
                        // Add Space
                        for(k = 1; k < blank_count; k++){
                            printf("     ");
                        }
                        for(k = 0; k < strlen(content[i]); k++){
                            if(content[i][k] == '.'){
                                printf("\n");
                                for(l = 1; l < blank_count; l++){
                                    printf("     ");
                                }
                            } else {
                                printf("%c", content[i][k]);
                            }
                        }
                        printf("\n");
                        
                    } else {
                        printf("\n\n");
                    }
                    cycle++;
                    // Reset Add Day Count
                    count = 0;
                }
                count++;
                total_count++;
            }
            
            // Last Line Content Check
            if(cycle == ((date[2][i]+blank_check)/7)){
                printf("\n");
                // Add Space
                for(k = 1; k < blank_count; k++){
                    printf("     ");
                }
                for(k = 0; k < strlen(content[i]); k++){
                    if(content[i][k] == '.'){
                        printf("\n");
                        for(l = 1; l < blank_count; l++){
                            printf("     ");
                        }
                    } else {
                        printf("%c", content[i][k]);
                    }
                }
                printf("\n");
                
            } else {
                printf("\n\n");
            }
            printf("\n");
            printf("아무 키나 입력하세요...");
            getchar();
        }
    }
    printf("표시할 일정이 더이상 없습니다.\n");
    printf("아무 키나 입력하세요...");
    getchar();
}


/****************************************************
 *                  SortSchedule                  *
 ****************************************************/

void SortSchedule(int (*date)[100], char (*content)[100], int i){
    int j = 0, k = 0, l = 0;
    // Bubbble Sort Schedule
    if(i != 0){
        for(j = 0; j < i; j++){
            for(k=0; k < i-j; k++){
                
                // Sort Year
                if(date[0][k] > date[0][k+1]){
                    int tmp_year, tmp_month, tmp_day;
                    char tmp_content[100] = {0};
                    
                    tmp_year = date[0][k];
                    tmp_month = date[1][k];
                    tmp_day = date[2][k];
                    strcpy(tmp_content, content[k]);
                    date[0][k] = date[0][k+1];
                    date[1][k] = date[1][k+1];
                    date[2][k] = date[2][k+1];
                    for(l = 0; l <= strlen(content[k+1]); l++){
                        content[k][l] = content[k+1][l];
                    }
                    
                    date[0][k+1] = tmp_year;
                    date[1][k+1] = tmp_month;
                    date[2][k+1] = tmp_day;
                    for(l = 0; l <= strlen(content[k+1]); l++){
                        content[k+1][l] = tmp_content[l];
                    }
                }
                
                // Sort Month
                if(date[0][k] <= date[0][k+1]){
                    if(date[1][k] > date[1][k+1]){
                        int tmp_year, tmp_month, tmp_day;
                        char tmp_content[100] = {0};
                        
                        tmp_year = date[0][k];
                        tmp_month = date[1][k];
                        tmp_day = date[2][k];
                        strcpy(tmp_content, content[k]);
                        date[0][k] = date[0][k+1];
                        date[1][k] = date[1][k+1];
                        date[2][k] = date[2][k+1];
                        for(l = 0; l <= strlen(content[k+1]); l++){
                            content[k][l] = content[k+1][l];
                        }
                        
                        date[0][k+1] = tmp_year;
                        date[1][k+1] = tmp_month;
                        date[2][k+1] = tmp_day;
                        for(l = 0; l <= strlen(content[k+1]); l++){
                            content[k+1][l] = tmp_content[l];
                        }
                    }
                }
                
                // Sort Day
                if(date[0][k] <= date[0][k+1]){
                    if(date[1][k] <= date[1][k+1]){
                        if(date[2][k] > date[2][k+1]){
                            int tmp_year, tmp_month, tmp_day;
                            char tmp_content[100] = {0};
                            
                            tmp_year = date[0][k];
                            tmp_month = date[1][k];
                            tmp_day = date[2][k];
                            strcpy(tmp_content, content[k]);
                            date[0][k] = date[0][k+1];
                            date[1][k] = date[1][k+1];
                            date[2][k] = date[2][k+1];
                            for(l = 0; l <= strlen(content[k+1]); l++){
                                content[k][l] = content[k+1][l];
                            }
                            
                            date[0][k+1] = tmp_year;
                            date[1][k+1] = tmp_month;
                            date[2][k+1] = tmp_day;
                            for(l = 0; l <= strlen(content[k+1]); l++){
                                content[k+1][l] = tmp_content[l];
                            }
                        }
                    }
                }
                
                // Sort Month
                if(date[0][k] <= date[0][k+1]){
                    if(date[1][k] > date[1][k+1]){
                        int tmp_year, tmp_month, tmp_day;
                        char tmp_content[100] = {0};
                        
                        tmp_year = date[0][k];
                        tmp_month = date[1][k];
                        tmp_day = date[2][k];
                        strcpy(tmp_content, content[k]);
                        date[0][k] = date[0][k+1];
                        date[1][k] = date[1][k+1];
                        date[2][k] = date[2][k+1];
                        for(l = 0; l <= strlen(content[k+1]); l++){
                            content[k][l] = content[k+1][l];
                        }
                        
                        date[0][k+1] = tmp_year;
                        date[1][k+1] = tmp_month;
                        date[2][k+1] = tmp_day;
                        for(l = 0; l <= strlen(content[k+1]); l++){
                            content[k+1][l] = tmp_content[l];
                        }
                    }
                }
                
                // Sort Year
                if(date[0][k] > date[0][k+1]){
                    int tmp_year, tmp_month, tmp_day;
                    char tmp_content[100] = {0};
                    
                    tmp_year = date[0][k];
                    tmp_month = date[1][k];
                    tmp_day = date[2][k];
                    strcpy(tmp_content, content[k]);
                    date[0][k] = date[0][k+1];
                    date[1][k] = date[1][k+1];
                    date[2][k] = date[2][k+1];
                    for(l = 0; l <= strlen(content[k+1]); l++){
                        content[k][l] = content[k+1][l];
                    }
                    
                    date[0][k+1] = tmp_year;
                    date[1][k+1] = tmp_month;
                    date[2][k+1] = tmp_day;
                    for(l = 0; l <= strlen(content[k+1]); l++){
                        content[k+1][l] = tmp_content[l];
                    }
                }
            }
        }
    }
}

/****************************************************
 *                  TerminalClear                  *
 ****************************************************/

void TerminalClear(void){
    // UNIX Shell
    system("clear");
    // Windows Power Shell
    //system("cls");
}


/****************************************************
 *                       Pause                      *
 ****************************************************/

void Pause(void){
    printf("아무 키나 입력하세요...\n");
    getchar();
    getchar();
    TerminalClear();
}


/****************************************************
 *                      SyntaxError                 *
 ****************************************************/

void SyntaxError(void) {
    TerminalClear();
    printf("Syntax Error!\n");
    //sleep(2);
    TerminalClear();
    return;
}
