#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 150//수식을 입력받을 배열의 크기
#define M 20//스택의 크기
#define K 30//배열 변수의 크기
#define RAD 3.141592 / 180.0//PI의 값

double calc(char *);//계산 함수

double pop_num();//숫자를 pop
void push_num(double);//숫자를 push
char pop_oper();//연산자 pop
void push_oper(char);//연산자 push
double math();//수학 함수를 호출하는 함수
void save(void);//데이터를 저장하는 함수
void load(void);//데이터를 불러오는 함수

char input[N] = {0};//수식을 입력받을 배열
char stack_oper[M];//연산자를 저장할 스택
double stack_num[M];//숫자를 저장할 스택
double A[2][26] = {0};//단일 변수가 저장될 배열
double AA[2][26][K] = {0};//배열 변수가 저장될 배열

int idx_input;//수식배열의 index값
int idx_oper;//연산자 스택의 index값
int idx_num;//숫자 스택의 index값
int ch = 1;//단일 변수나 배열 변수를 정의해줄때 출력을 위해 표시

int main()
{
        while(1)
        {
                double x;
                int i;

//전에 받았던 수식이 남아 있으므로 수식을 입력 받기 전에 input을 초기화 해준다
                for(i = 0; i < N; i++)
                        input[i] = 0;

//char형 input배열에 수식을 입력받음
                printf("수식 : ");
                scanf("%[^\n]", input);
                getchar();

//수식에 END, end 입력시 프로그램 종료
                if(strcmp(input, "END") == 0 || strcmp(input, "end") == 0)
                {
                        printf("Good Bye!!\n");
                        break;
                }

//수식이 배열의 길이보다 길경우 에러메세지 출럭
                if(strlen(input) >= N)
                {
                        printf("수식이 너무 깁니다.\n");
                        continue;
                }

                x = calc(input);

//calc 함수 호출후 결과값 출력
//단일 변수나 배열 변수의 값을 입력했을 경우는 출력하지 않음
                if(ch != 0)
                        printf("= %g\n", x);
        }
        return 0;
}


double calc(char input[N])
{
        int i;
        int sign_flag = 1;//'-' 가 입력되었을시 음수로 숫자를 저장하기 위한 표시
        int oper_flag = 1;//마지막으로 push된 것이 숫자인지 연산자인지 표시
        int cnt = 0;//push되어 있는 숫자의 개수

        ch = 1;//ch를 1로 초기화

//index값들 초기화
        idx_oper = -1;
        idx_num = -1;
        idx_input = 0;

//수식에서 공백이 있을 경우 한칸씩 앞으로 땡겨서 공백을 없앰
        for(i = 0; input[i] != '\0'; i++)
        {
                if(input[i] == ' ')
                        strcpy(input + i, input + i + 1);
//대문자를 소문자로 바꿔줌
                input[i] = tolower(input[i]);
        }
//수식이 끝날 때까지 idx_input을 증가시키며 실행
        for(; input[idx_input] != '\0'; idx_input++)
        {
                if(input[idx_input]=='-')
                {
                        idx_input++;
//피연산자가 스택에 있는경우 +를 push, 숫자는 음수로 push
                        if(oper_flag == 0)
                        {
                                push_oper('+');
                                oper_flag = 1;
                        }
                        sign_flag = -1;
                }
//피연산자가 없는경우 음수로 push
                else sign_flag = 1;

//숫자, 연산자, 함수를 판별 후 각각의 스택에 저장
//숫자이고 바로 전에 숫자가 push되지 않았을 경우
                if(isdigit(input[idx_input]) && oper_flag == 1)
                {
//atof 함수를 이용하여 double형으로 push
                        push_num(sign_flag * atof(input + idx_input));
                        oper_flag = 0;
                        ++cnt;
                }
//연산자일 경우
                else if(input[idx_input]=='+' || input[idx_input]=='*' || input[idx_input] == '/')
                {
//연산자를 스택에 push
                        push_oper(input[idx_input]);
                        oper_flag = 1;
                }
//소문자일 경우
                else if(islower(input[idx_input]))
                {
//변수에 해당하는 배열의 칸
                        int i = input[idx_input] - 'a';
//AA, BB와 같이 같은 알파벳이 연속으로 두개 있을 경우
                        if(input[idx_input] == input[idx_input+1])
                        {
//알파벳 뒤에 '(' 가 올 경우 배열 변수의 원소번호를 받음
                                if(input[idx_input+2] == '(')
                                {
//배열 변수의 원소번호를 j에 저장
                                        int j = atoi(input+idx_input+3);
                                        for(; input[++idx_input] != ')'; ) ;
//'=' 가 올 경우, 해당하는 배열에 값을 저장
                                        if(input[idx_input+1] == '=')
                                        {
                                                AA[1][i][j] = atof(input+idx_input+2);
                                                AA[0][i][j] = 1;
                                                ch = 0;
                                                return 0;
                                        }
                                        else//배열 변수를 출력 할 때
                                        {
//배열에 입력받은 값이 없을 경우 메세지 출력
                                                if(AA[0][i][j] == 0)
                                                {
                                                        printf("= undefined symbol\n");
                                                        ch = 0;
                                                        return 0;
                                                }
//배열의 원소번호에 저장된 값을 push
                                                else
                                                {
                                                        push_num(sign_flag * AA[1][i][j]);
                                                        oper_flag = 0;
                                                        cnt++;
                                                        ch = 1;
                                                }
                                        }
                                }
//배열 변수를 정의 할 때
                                else if(input[idx_input+2] == '=')
                                {
                                        int j = 0, cnt=0, p;
                                        idx_input += 3;//'=' 다음 까지 idx_input 증가

//받으려는 배열을 초기화 시켜줌
                                        for(p = 0; p < K; p++)
                                                AA[0][i][p] = 0;

//수식이 끝날 때 까지 idx_input을 증가시키면 반복
                                        for(; input[idx_input] != '\0'; idx_input++)
                                        {
//해당하는 배열에 값을 넣어주고 입력 받았다고 표시해줌
                                                AA[1][i][j] = atof(input+idx_input);
                                                AA[0][i][j] = 1;
                                                j++;
//','가 나올 때까지 idx_input을 증가, 수식이 끝날 경우에는 종료
                                                for(; input[idx_input]!=','; idx_input++)
                                                        if(input[idx_input]=='\0')
                                                                break;
                                        }
                                        ch = 0;
                                        return 0;
                                }
//배열 변수끼리의 사칙연산 일 경우
                                else if(input[idx_input+2]=='+'|| input[idx_input+2]=='-'||input[idx_input+2]=='*'||input[idx_input+2]=='/')
                                {
                                        int l, oper_cnt=0;
//i는 앞의 배열변수의 번호, j는 뒤의 배열변수의 번호
                                        int i = input[idx_input]-'a', j = input[idx_input+3]-'a';
                                        double result[N];
//연산자에 따라 계산해서 result배열에 저장
                                        switch(input[idx_input+2])
                                        {
                                        case '+':
                                                for(l = 0; AA[0][i][l] != 0 || AA[0][j][l] != 0; l++)
                                                        result[l] = sign_flag * AA[1][i][l] + AA[1][j][l];
                                                break;
                                        case '-':
                                                for(l = 0; AA[0][i][l] != 0 || AA[0][j][l] != 0; l++)
                                                        result[l] = sign_flag * AA[1][i][l] - AA[1][j][l];
                                                break;
                                        case '*':
                                                for(l = 0; AA[0][i][l] != 0 || AA[0][j][l] != 0; l++)
                                                        result[l] = sign_flag * AA[1][i][l] * AA[1][j][l];
                                                break;
                                        case '/':
                                                for(l = 0; AA[0][i][l] != 0 || AA[0][j][l] != 0; l++)
                                                        result[l] = sign_flag * AA[1][i][l] / AA[1][j][l];
                                                break;
                                        }
//result배열을 출력
                                        printf("= ");
                                        for(j = 0; j < l; j++)
                                        {
                                                printf("%g", result[j]);
                                                if(j+1 != l)
                                                        printf(", ");
                                        }
                                        ch = 0;
                                        printf("\n");
                                        return 0;
                                }
//배열변수의 원소들을 출력할 때
                                else
                                {
//배열변수가 정의되지 않은 경우 에러메세지 출력
                                        if(AA[0][i][0] == 0)
                                        {
                                                printf("= undefined symbol\n");
                                                ch = 0;
                                                return 0;
                                        }
//배열변수가 정의된 경우 배열변수의 원소들을 출력
                                        else
                                        {
                                                int j;

                                                printf("= ");
                                                for(j = 0; AA[0][i][j] != 0; j++)
                                                {
                                                        printf("%g", AA[1][i][j]);
                                                        if(AA[0][i][j+1] != 0)
                                                                printf(", ");
                                                }
                                                ch = 0;
                                                printf("\n");
                                                return 0;
                                        }
                                }
                        }
//단일변수를 정의 할 때
                        else if(input[idx_input+1] == '=')
                        {
//'=' 뒤의 수식을 가지고 calc함수를 호출한다
                                strcpy(input, input+idx_input+2);
                                A[1][i] = calc(input);
                                A[0][i] = 1;
                                ch = 0;
                                return 0;
                        }
//단일변수가 사용 될 때
                        else if(islower(input[idx_input+1]) == 0)
                        {
//단일변수가 정의되지 않은 경우 에러메세지 출력
                                if(A[0][i] == 0)
                                {
                                        printf("= undefined symbol\n");
                                        ch = 0;
                                        return 0;
                                }
//단일변수가 정의된 경우 단일변수의 값을 push 해서 계산
                                else
                                {
                                        push_num(sign_flag * A[1][i]);
                                        oper_flag = 0;
                                        cnt++;
                                        ch = 1;
                                }

                        }
//서로다른 영문자가 연속되어 입력되었을 때
                        else if(islower(input[idx_input]) && oper_flag == 1)
                        {
//입력받은 문자열을 확인한 후 그에 따른 함수들을 호출
                                if(strncmp(input+idx_input, "save", 4) == 0)
                                {
                                        save();
                                        return 0;
                                }
                                else if(strncmp(input+idx_input, "load", 4) == 0)
                                {
                                        load();
                                        return 0;
                                }
//배열변수의 원소들의 합을 계산해서 push
                                else if(strncmp(input+idx_input, "add", 3)==0)
                                {
                                        double x = 0;
                                        int j, i = input[idx_input+4] - 'a';
                                        idx_input += 6;

                                        for(j = 0; AA[0][i][j] != 0; j++)
                                                x += AA[1][i][j];

                                        push_num(sign_flag * x);
                                        cnt++;
                                        oper_flag = 0;
                                }
//배열변수의 원소들의 곱을 계산해서 push
                                else if(strncmp(input+idx_input, "mul", 3)==0)
                                {
                                        double x = 1;
                                        int j, i = input[idx_input+4] - 'a';
                                        idx_input += 6;

                                        for(j = 0; AA[0][i][j] != 0; j++)
                                                x = x*AA[1][i][j];

                                        push_num(sign_flag * x);
                                        cnt++;
                                        oper_flag = 0;
                                }
//배열변수의 원소들의 평균을 계산해서 push
                                else if(strncmp(input+idx_input, "avg", 3)==0)
                                {
                                        double x = 0;
                                        int j, i = input[idx_input+4] - 'a';
                                        idx_input += 6;

                                        for(j = 0; AA[0][i][j] != 0; j++)
                                                x += AA[1][i][j];

                                        push_num(sign_flag * (x / j));
                                        cnt++;
                                        oper_flag = 0;
                                }
//배열번수의 원소들의 표준편차를 계산해서 push
                                else if(strncmp(input+idx_input, "std", 3)==0)
                                {
                                        double x = 0;
                                        double ave, dev = 0;
                                        int n, j, i = input[idx_input+4] - 'a';
                                        idx_input += 6;

                                        for(n = 0; AA[0][i][n] != 0; n++)
                                                x += AA[1][i][n];

                                        ave = x / n;

                                        for(j = 0; j < n; j++)
                                                dev += pow(AA[1][i][j] - ave, 2);

                                        push_num(sign_flag * sqrt(dev/n));
                                        cnt++;
                                        oper_flag = 0;
                                }
//수학 함수일 경우 수학함수를 호출하여 값을 받아 push
                                else
                                {
                                        push_num(sign_flag * math());
                                        cnt++;
                                        oper_flag = 0;
                                }
                        }
                }

                if(oper_flag == 0 && cnt >= 2 && (stack_oper[idx_oper]=='/' || stack_oper[idx_oper]=='*'))
                {
//'*'와 '/'연산이 가능할 경우 연산 후 결과를 push
                        char opr;
                        double num1, num2;
                        num2 = pop_num();
                        num1 = pop_num();
                        opr = pop_oper();
                        switch(opr)
                        {
                        case '*': push_num(num1 * num2); break;
                        case '/': push_num(num1 / num2); break;
                        default: break;
                        }
//숫자스택에 저장된 개수를 하나 줄임
                        --cnt;
                }
        }
//남아있는 '+'연산을 실행
        for(i = 1; i < cnt; ++i)
        {
                char opr;
                double num1, num2;

                if(idx_num == -1)
                        break;
                num2 = pop_num();
                num1 = pop_num();
                opr = pop_oper();

                push_num(num1 + num2);
        }
        return pop_num();
}

//스택에서 숫자를 pop해주는 함수
double pop_num()
{
//if(idx_num == -1)
//{
//스택에 저장된 숫자가 없는 경우
//printf("스택이 비어있습니다.\n");
//return 0;
//}
//index를 하나 줄이고 숫자를 pop

//else
        return stack_num[idx_num--];
}

//스택에 숫자를 push해주는 함수
void push_num(double number)
{
        if(idx_num >= M)
        {
//숫자의 개수가 스택의 크기를 초과한 경우
                printf("스택이 가득 찼습니다.\n");
                exit(1);
        }
//index를 하나 증가시키고 숫자를 스택에 저장
        stack_num[++idx_num] = number;
}

//스택에서 연산자를 pop해주는 함수
char pop_oper()
{
        if(idx_oper == -1)
        {
//스택에 저장된 연산자가 없는 경우
                printf("스택이 비어있습니다.\n");
                return 0;
        }
//index를 하나 줄이고 연산자를 pop

        else return stack_oper[idx_oper--];
}

//스택에 연산자를 push해주는 함수
void push_oper(char operator)
{
        if( idx_num >= M)
        {
//연산자의 개수가 스택의 크기를 초과한 경우
                printf("스택이 가득 찼습니다.\n");
                exit(1);
        }
//index를 하나 증가시키고 연산자를 스택에 저장
        stack_oper[++idx_oper] = operator;
}

//math함수들을 호출해서 값을 리턴해주는 함수
double math()
{
        double x, y;

//각각의 함수들에 맞는 함수를 호출 후 그 값을 return
        if(strncmp(input+idx_input, "sin", 3)==0)
        {
                idx_input += 4;//'('다음까지 idx_input을 증가
                if(islower(input[idx_input]))
                {
//( )안에 입력된 것이 배열변수인지 단일변수인지 판별 후 값을 저장
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
//( )안에 입력된 것이 숫자일 경우 숫자를 저장
                else x = atof(input+idx_input);
//')'가 나올 때까지 idx_input값을 증가
                for(; input[++idx_input] != ')'; ) ;
//함수의 값을 return
                return sin(x * RAD);
        }
        else if(strncmp(input+idx_input, "cos", 3)==0)
        {
                idx_input += 4;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return cos(x * RAD);
        }
        else if(strncmp(input+idx_input, "tan", 3)==0)
        {
                idx_input += 4;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return tan(x * RAD);
        }
        else if(strncmp(input+idx_input, "acos", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return acos(x * RAD);
        }
        else if(strncmp(input+idx_input, "asin", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return asin(x * RAD);
        }
        else if(strncmp(input+idx_input, "atan", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return atan(x * RAD);
        }
        else if(strncmp(input+idx_input, "atan2", 5)==0)
        {
                idx_input += 6;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                y = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else y = A[1][input[idx_input] - 'a'];
                }
                else y = atof(input+idx_input);
                for(; input[idx_input++] != ','; ) ;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return atan2(y * RAD, x * RAD);
        }
        else if(strncmp(input+idx_input, "cosh", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return cosh(x * RAD);
        }
        else if(strncmp(input+idx_input, "sinh", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return sinh(x * RAD);
        }
        else if(strncmp(input+idx_input, "tanh", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return tanh(x * RAD);
        }
        else if(strncmp(input+idx_input, "exp", 3)==0)
        {
                idx_input += 4;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return exp(x);
        }
        else if(strncmp(input+idx_input, "log", 3)==0)
        {
                idx_input += 4;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return log(x);
        }
        else if(strncmp(input+idx_input, "log10", 5)==0)
        {
                idx_input += 6;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return log10(x);
        }
        else if(strncmp(input+idx_input, "ceil", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return ceil(x);
        }
        else if(strncmp(input+idx_input, "floor", 5)==0)
        {
                idx_input += 6;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return floor(x);
        }
        else if(strncmp(input+idx_input, "fabs", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return fabs(x);
        }
        else if(strncmp(input+idx_input, "fmod", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                y = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else y = A[1][input[idx_input] - 'a'];
                }
                else y = atof(input+idx_input);
                for(; input[idx_input++] != ','; ) ;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return fmod(y, x);
        }
        else if(strncmp(input+idx_input, "pow", 3)==0)
        {
                idx_input += 4;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                y = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else y = A[1][input[idx_input] - 'a'];
                }
                else y = atof(input+idx_input);
                for(; input[idx_input++] != ','; ) ;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return pow(y, x);
        }
        else if(strncmp(input+idx_input, "sqrt", 4)==0)
        {
                idx_input += 5;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return sqrt(x);
        }
        else if(strncmp(input+idx_input, "ldexp", 5)==0)
        {
                idx_input += 6;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                y = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else y = A[1][input[idx_input] - 'a'];
                }
                else y = atof(input+idx_input);
                for(; input[idx_input++] != ','; ) ;
                if(islower(input[idx_input]))
                {
                        if(input[idx_input] == input[idx_input+1])
                                x = AA[1][input[idx_input] - 'a'][atoi(input+idx_input+3)];
                        else x = A[1][input[idx_input] - 'a'];
                }
                else x = atof(input+idx_input);
                for(; input[++idx_input] != ')'; ) ;
                return ldexp(y, (int)x);
        }
        return 0;
}

//배열변수와 단일변수가 저장된 배열들을 파일에 저장하는 함수
void save(void)
{
        char name[20];

        FILE * fi;

        strcpy(name, input+idx_input+4);//입력 받은 파일의 이름을 name에 복사

        fi = fopen(name, "w");//파일을 쓰기용으로 open

        fwrite(A, sizeof(A), 1, fi);//파일에 A배열의 값을 write
        fwrite(AA, sizeof(AA), 1, fi);//파일에 AA배열의 값을 write

        fclose(fi);//파일을 close
        ch = 0;
}

//배열변수와 단일변수가 저장된 배열들을 파일에서 불러오는 함수
void load(void)
{
        char name[20];

        FILE * file;

        strcpy(name, input+idx_input+4);//입력 받은 파일의 이름을 name에 복사

        file = fopen(name, "r");//파일을 읽기용으로 open

        fread(A, sizeof(A), 1, file);//A배열의 값을 read
        fread(AA, sizeof(AA), 1, file);//AA배열의 값을 read

        fclose(file);//파일을 close
        ch = 0;
}
