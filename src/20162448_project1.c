#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define MAXSIZE 1000
#define LARGESIZE 100
#define MINSIZE 50
#define ALPHABET 26
#define NAMESIZE 20

void simple_calulator(void);
void complex_calculator(void);
void preprocessor(char *input);
void array_calculation(char *expression);
int simple_postfix(char *position, char *destination);
int complex_postfix(char *position, char *destination);
double math(char *function, char *argument);
void function_argument(char *position, char input_argument[][LARGESIZE], int count);
double calculation(char *position);
int operator_precedence(int operator);
double top(void);
double pop(void);
void push(double position);
void assignment_variable(int index, char *expression);
void init_stack(void);
void deallocation(void);
void save(char *position);
void load(char *position);
void print_menu(int select_menu);
void help(void);
void information(void);
void termianl_clear(void);
void process_pause(void);
void print_error(int type);
void remove_enter(void);

struct stack {
    int top;
    double space[MAXSIZE];
} stack;

struct variable {
    double *single[ALPHABET];
    double *array[ALPHABET];
} variable;

int main(void) {

    int select_function;

    do{
        print_menu(1);
        scanf("%d", &select_function);
        remove_enter();
        termianl_clear();
        switch (select_function) {
            case 1:
                simple_calulator();
                break;
            case 2:
                complex_calculator();
                break;
            case 3:
                help();
                break;
            case 0:
                break;
            default:
                print_error(0);
                break;
        }
    } while(select_function != 0);
    return 0;
}

void simple_calulator(void) {

    struct formular {
        char input[MAXSIZE];
        char postfix[MAXSIZE];
    } formular;

    print_menu(2);
    scanf("%[^\n]", formular.input);
    remove_enter();
    if(strcmp(formular.input,"END") == 0 || strcmp(formular.input,"end") == 0) {
        return;
    } else switch (simple_postfix(formular.input, formular.postfix)) {
        case -1:
            process_pause();
            return;
            break;
        default:
            printf(" = %g\n", calculation(formular.postfix));
            break;
    }
    process_pause();
    deallocation();
}

void complex_calculator(void) {

    struct formular {
        char input[MAXSIZE];
    } formular;

    print_menu(3);
    for( ; ; ) {
        printf(" 입력 : ");
        scanf("%[^\n]", formular.input);
        remove_enter();
        if(strcmp(formular.input,"END") == 0 || strcmp(formular.input,"end") == 0) {
            return;
        } else if(strncmp(formular.input, "SAVE", 4) == 0 || strncmp(formular.input, "save", 4) == 0) {
            save(formular.input);
        } else if(strncmp(formular.input, "LOAD", 4) == 0 || strncmp(formular.input, "load", 4) == 0) {
            load(formular.input);
        } else {
            preprocessor(formular.input);
        }
    }
    process_pause();
    deallocation();
}

void preprocessor(char *input) {

    struct formular {
        char postfix[MAXSIZE];
        double result;
        int destination;
    } formular;
    char *temp = input;

    while(*temp == ' ' || *temp == '\t') {
        temp++;
    }
    if((*temp >= 'a' && *temp <= 'z') || (*temp >= 'A' && *temp <= 'Z')){
        if(*temp >= 'a') {
            formular.destination = *temp-'a';
        } else {
            formular.destination = *temp-'A';
        }
        temp++;
        if(*temp == *(temp-1)) {
            temp++;
            while(*temp == ' ' || *temp == '\t') {
                temp++;
            }
            if(*temp == '='){
                temp++;
                assignment_variable(formular.destination, temp);
            } else if(*temp != '(') {
                array_calculation(input);
            } else {
                if(complex_postfix(input, formular.postfix) == -1) {
                    return;
                } else {
                    printf(" = %g\n", calculation(formular.postfix));
                }
            }
        } else {
            while(*temp == ' ' || *temp == '\t') {
                temp++;
            }
            switch(*temp) {
                case '=':
                    temp++;
                    if(complex_postfix(temp, formular.postfix) == -1) {
                        return;
                    } else {
                        formular.result = calculation(formular.postfix);
                        variable.single[formular.destination] = (double *)calloc(1,sizeof(double));
                        *variable.single[formular.destination] = formular.result;
                    }
                    break;
                default :
                    if(complex_postfix(input, formular.postfix) == -1) {
                        return;
                    } else {
                        printf(" = %g\n", calculation(formular.postfix));
                    }
                    break;
            }
        }
    } else switch (complex_postfix(input, formular.postfix)) {
        case -1:
            return;
            break;
        default:
            printf(" = %g\n", calculation(formular.postfix));
            break;
    }
}

void array_calculation(char *expression){

    struct formular {
        double result[MINSIZE];
        int operator;
    } formular;
    char temp[MINSIZE] = {0};
    int alphabet[2] = {-1, -1};
    int array_size = 0;
    int i = 0, j = 0;

    while(*expression != '\0'){
        while(*expression == ' ') {
            expression++;
        }
        if(*expression == *(expression+1)) {
            if(*expression >= 'a') {
                alphabet[i] = *expression-'a';
            } else {
                alphabet[i] = *expression-'A';
            }
            expression ++;
        } else if(*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/' || *expression == '^') {
            i++;
            formular.operator = *expression;
            expression++;
        } else {
            expression++;
        }
    }
    if(variable.array[alphabet[0]] == NULL) {
        print_error(1);
        return;
    } else {
        for(i = 0; i < variable.array[alphabet[0]][0]; i++) {
            formular.result[i] = variable.array[alphabet[0]][i+1];
        }
        if(alphabet[1] != -1){
            for(i = 0; i < variable.array[alphabet[1]][0]; i++) {
                switch(formular.operator) {
                    case '+':
                        formular.result[i] += variable.array[alphabet[1]][i+1];
                        break;
                    case '-':
                        formular.result[i] -= variable.array[alphabet[1]][i+1];
                        break;
                    case '*':
                        formular.result[i] *= variable.array[alphabet[1]][i+1];
                        break;
                    case '/':
                        formular.result[i] /= variable.array[alphabet[1]][i+1];
                        break;
                    case '^':
                        formular.result[i] = pow(formular.result[i], variable.array[alphabet[1]][i+1]);
                        break;
                }
            }
            if(variable.array[alphabet[0]][0] > variable.array[alphabet[1]][0]) {
                array_size = variable.array[alphabet[0]][0];
            } else {
                array_size = variable.array[alphabet[1]][0];
            }
        }
        if(array_size < variable.array[alphabet[0]][0]) {
            array_size = variable.array[alphabet[0]][0];
        } else {
            array_size = array_size;
        }
        printf(" = ");
        for(i = 0; i < array_size; i++) {
            if(i == array_size - 1) {
                printf("%g\n",formular.result[i]);
            } else {
                printf("%g, ",formular.result[i]);
            }
        }
    }
}

void assignment_variable(int index, char *expression) {

    double temp[MINSIZE] = {0};
    int size = 0;
    char *p;
    int i;

    p = strtok(expression, ",\0");
    while(p != NULL){
        temp[size] = atof(p);
        size++;
        p = strtok(NULL,",\0");
    }
    variable.array[index] = (double *)calloc(size + 1, sizeof(double));
    variable.array[index][0] = size;
    for(i = 1; i <= size; i++) {
        variable.array[index][i] = temp[i - 1];
    }
}

int simple_postfix(char *position, char *destination) {

    int negative = 1;
    struct parenthesis {
        int right_count;
        int left_count;
    } parenthesis;
    struct operation {
        int operator_count;
        int operand_count;
    } operation;
    int previous_token = 0;
    int variable_index = 0;

    parenthesis.right_count = 0;
    parenthesis.left_count = 0;
    operation.operator_count = 0;
    operation.operand_count = 0;
    init_stack();
    while(*position != '\0') {
        if((*position >='A' && *position <= 'Z') && (*(position+1) < 'A' || *(position+1) > 'Z' )) {
            if(*position >= 'A') {
                variable_index = *position - 'A';
            } else {
                variable_index = *position - 'a';
            }
            if(variable.single[variable_index] == NULL){
                printf(" ERROR : Cannot use symbol '%c'\n", *position);
                process_pause();
                return -1;
            } else {
                sprintf(destination, "%g", *variable.single[variable_index]);
                destination += strlen(destination);
                *destination = ' ';
                destination++;
                position++;
                negative = 0;
                operation.operand_count++;
                switch(previous_token) {
                    case 2:
                        print_error(2);
                        process_pause();
                        return -1;
                        break;
                    case 4:
                        print_error(3);
                        process_pause();
                        return -1;
                        break;
                    default:
                        previous_token = 4;
                }
            }
        } else if((*position >= 'A' && *position <= 'Z') && *(position+1) == *position) {
            printf(" ERROR : Cannot use symbol '%c'\n", *position);
            process_pause();
            return -1;
        } else if(*position >= 'A' && *position <= 'Z') {
            printf(" ERROR : Cannot use symbol '%c'\n", *position);
            process_pause();
            return -1;
        } else if(*position == '(') {
            printf(" ERROR : Cannot use symbol '%c'\n", *position);
            process_pause();
            return -1;
        } else if(*position == ')') {
            printf(" ERROR : Cannot use symbol '%c'\n", *position);
            process_pause();
            return -1;
        } else if(*position == '+' || (negative == 0 && *position == '-') || *position == '*' || *position == '/' || *position == '^') {
            while(stack.top != 0 && operator_precedence(top()) >= operator_precedence((int)*position)){
                *destination = (char)pop();
                destination++;
                *destination = ' ';
                destination++;
            }
            push((double)*position);
            position++;
            negative = 1;
            operation.operator_count++;
            switch(previous_token) {
                case 0:
                    print_error(4);
                    process_pause();
                    return -1;
                    break;
                case 3:
                    print_error(5);
                    process_pause();
                    return -1;
                    break;
                default:
                    previous_token = 3;
                    break;
            }
        } else if((negative == 1 && *position == '-') || (*position >= '0' && *position <= '9') || *position == '.') {
            do {
                *destination = *position;
                destination++;
                position++;
            } while((*position >= '0' && *position <= '9') || *position == '.');
            *destination = ' ';
            destination++;
            negative = 0;
            operation.operand_count++;
            switch(previous_token) {
                case 4:
                    print_error(3);
                    process_pause();
                    return -1;
                    break;
                default:
                    previous_token = 4;
                    break;
            }
        } else if(*position == ' ' || *position == '\t') {
            position++;
        } else {
            printf(" ERROR : Cannot use symbol '%c'\n", *position);
            process_pause();
            return -1;
        }
    }
    if(operation.operator_count + 1 > operation.operand_count) {
        print_error(6);
        process_pause();
        return -1;
    } else {
        while(stack.top != 0) {
            *destination = (char)pop();
            destination++;
            *destination = ' ';
            destination++;
        }
        destination--;
        *destination = '\0';
    }
    return 0;
}

int complex_postfix(char *position, char *destination) {

    int negative = 1;
    struct parenthesis {
        int right_count;
        int left_count;
    } parenthesis;
    struct operation {
        int operator_count;
        int operand_count;
    } operation;
    struct temp {
        int index;
    } temp;
    int previous_token = 0;
    int variable_index = 0;
    char temp_first[LARGESIZE] = {0};
    char temp_second[LARGESIZE] = {0};

    parenthesis.right_count = 0;
    parenthesis.left_count = 0;
    operation.operator_count = 0;
    operation.operand_count = 0;
    init_stack();
    while(*position != '\0') {
        if((*position >='A' && *position <= 'Z') && (*(position+1) < 'A' || *(position+1) > 'Z' )) {
            if(*position >= 'A') {
                variable_index = *position - 'A';
            } else {
                variable_index = *position - 'a';
            }
            if(variable.single[variable_index] == NULL) {
                printf(" ERROR : 변수 '%c'가 선언되지 않음\n", *position);
                process_pause();
                return -1;
            } else {
                sprintf(destination, "%f", *variable.single[variable_index]);
                destination += strlen(destination);
                *destination = ' ';
                destination++;
                position++;
                negative = 0;
                operation.operand_count++;
                switch(previous_token) {
                    case 2:
                        print_error(2);
                        process_pause();
                        return -1;
                        break;
                    case 4:
                        print_error(3);
                        process_pause();
                        return -1;
                        break;
                    default:
                        previous_token = 4;
                }
            }
        } else if((*position >= 'A' && *position <= 'A') && *(position+1) == *position) {
            if(*position >= 'A') {
                variable_index = *position - 'A';
            } else {
                variable_index = *position - 'a';
            }
            position += 3;
            temp.index = *position - '0';
            printf("%c",*position);
            position++;
            sprintf(destination, "%f", variable.array[variable_index][temp.index]);
            destination += strlen(destination);
            *destination = ' ';
            destination++;
            position++;
            negative = 0;
            operation.operand_count++;
            switch(previous_token) {
                case 2:
                    print_error(2);
                    process_pause();
                    return -1;
                    break;
                case 4:
                    print_error(3);
                    process_pause();
                    return -1;
                    break;
                default:
                    previous_token = 4;
            }
        } else if(*position >= 'A' && *position <= 'Z') {
            temp.index = 0;
            do {
                temp_first[temp.index] = *position;
                temp.index++;
                position++;
            } while(*position >= 'A' && *position <= 'Z');
            temp_first[temp.index] = '\0';
            if(*position != '(') {
                print_error(7);
                process_pause();
                return -1;
            } else {
                position++;
                temp.index=0;
                while(*position != ')') {
                    temp_second[temp.index] = *position;
                    temp.index++;
                    position++;
                }
                temp_second[temp.index] = '\0';
                sprintf(destination, "%f",math(temp_first, temp_second));
                destination += strlen(destination);
                *destination = ' ';
                destination++;
                position++;
                negative = 0;
                operation.operand_count++;
                switch(previous_token) {
                    case 2:
                        print_error(2);
                        process_pause();
                        return -1;
                        break;
                    case 4:
                        print_error(3);
                        process_pause();
                        return -1;
                        break;
                    default:
                        previous_token = 4;
                }
            }
        } else if(*position == '(') {
            push((int)*position);
            position++;
            negative = 1;
            parenthesis.left_count++;
            switch(previous_token) {
                case 2:
                    print_error(8);
                    process_pause();
                    return -1;
                    break;
                case 4:
                    print_error(9);
                    process_pause();
                    return -1;
                    break;
                default:
                    previous_token = 1;
            }
        } else if(*position == ')') {
            while(top() != '('){
                *destination = (char)pop();
                destination++;
                *destination = ' ';
                destination++;
            }
            pop();
            position++;
            negative = 0;
            parenthesis.right_count++;
            switch(previous_token) {
                case 0:
                    print_error(10);
                    process_pause();
                    return -1;
                    break;
                case 1:
                    print_error(11);
                    process_pause();
                    return -1;
                    break;
                case 3:
                    print_error(12);
                    process_pause();
                    return -1;
                    break;
                default:
                    previous_token = 2;
                    break;
            }
        } else if(*position == '+' || (negative == 0 && *position == '-') || *position == '*' || *position == '/' || *position == '^') {
            while(stack.top != 0 && operator_precedence(top()) >= operator_precedence((int)*position)){
                *destination = (char)pop();
                destination++;
                *destination = ' ';
                destination++;
            }
            push((double)*position);
            position++;
            negative = 1;
            operation.operator_count++;
            switch(previous_token) {
                case 0:
                    print_error(4);
                    process_pause();
                    return -1;
                    break;
                case 1:
                    print_error(13);
                    process_pause();
                    return -1;
                    break;
                case 3:
                    print_error(5);
                    process_pause();
                    return -1;
                    break;
                default:
                    previous_token = 3;
                    break;
            }
        } else if((negative == 1 && *position == '-') || (*position >= '0' && *position <= '9') || *position == '.') {
            do {
                *destination = *position;
                destination++;
                position++;
            } while((*position >= '0' && *position <= '9') || *position == '.');
            *destination = ' ';
            destination++;
            negative = 0;
            operation.operand_count++;
            switch(previous_token) {
                case 2:
                    print_error(2);
                    process_pause();
                    return -1;
                    break;
                case 4:
                    print_error(3);
                    process_pause();
                    return -1;
                    break;
                default:
                    previous_token = 4;
                    break;
            }
        } else if(*position == ' ' || *position == '\t') {
            position++;
        } else {
            printf(" ERROR : Cannot use symbol '%c'\n", *position);
            process_pause();
            return -1;
        }
    }
    if(parenthesis.left_count != parenthesis.right_count) {
        print_error(14);
        process_pause();
        return -1;
    } else if(operation.operator_count + 1 > operation.operand_count) {
        print_error(6);
        process_pause();
        return -1;
    } else {
        while(stack.top != 0) {
            *destination = (char)pop();
            destination++;
            *destination = ' ';
            destination++;
        }
        destination--;
        *destination = '\0';
    }
    return 0;
}

double math(char *function, char *argument) {

    struct temp {
        char first[2][LARGESIZE];
        int index;
    } temp;
    struct formular {
        char infix[LARGESIZE];
        double result;
    } formular;
    double x, y;
    int i;

    if(strcmp(function, "POW") == 0 || strcmp(function, "pow") == 0) {
        function_argument(argument, temp.first, 2);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            if(complex_postfix(temp.first[1],formular.infix) == -1) {
                return 0.0;
            } else {
                y = calculation(formular.infix);
                return pow(x,y);
            }
        }
    } else if(strcmp(function, "COS") == 0 || strcmp(function, "cos") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return cos(x);
        }
    } else if(strcmp(function, "SIN") == 0 || strcmp(function, "sin") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return sin(x);
        }
    } else if(strcmp(function, "TAN") == 0 || strcmp(function, "tan") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return tan(x);
        }
    } else if(strcmp(function, "SQRT") == 0 || strcmp(function, "sqrt") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return sqrt(x);
        }
    } else if(strcmp(function, "ACIS") == 0 || strcmp(function, "acis") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return acos(x);
        }
    } else if(strcmp(function, "EXP") == 0 || strcmp(function, "exp") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return exp(x);
        }
    } else if(strcmp(function, "LOG") == 0 || strcmp(function, "log") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return log(x);
        }
    } else if(strcmp(function, "CEIL") == 0 || strcmp(function, "ceil") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return ceil(x);
        }
    } else if(strcmp(function, "FLOOR") == 0 || strcmp(function, "floor") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return floor(x);
        }
    } else if(strcmp(function, "FABS") == 0 || strcmp(function, "fabs") == 0) {
        function_argument(argument, temp.first, 1);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            return fabs(x);
        }
    } else if(strcmp(function, "FMOD") == 0 || strcmp(function, "fmod") == 0) {
        function_argument(argument, temp.first, 2);
        if(complex_postfix(temp.first[0],formular.infix) == -1) {
            return 0.0;
        } else {
            x = calculation(formular.infix);
            if(complex_postfix(temp.first[1],formular.infix) == -1) {
                return 0.0;
            } else {
                y = calculation(formular.infix);
                return fmod(x,y);
            }
        }
    } else if(strcmp(function, "ADD") == 0 || strcmp(function, "add") == 0) {
        if(*argument >= 'a') {
            temp.index = *argument-'a';
        } else {
            temp.index = *argument-'A';
        }
        for(i = 0; i < variable.array[temp.index][0]; i++) {
            formular.result += variable.array[temp.index][i+1];
        }
        return formular.result;
    } else if(strcmp(function, "MUL") == 0 || strcmp(function, "mul") == 0) {
        if(*argument >= 'a') {
            temp.index = *argument-'a';
        } else {
            temp.index = *argument-'A';
        }
        formular.result = 1;
        for(i = 0; i < variable.array[temp.index][0]; i++) {
            formular.result *= variable.array[temp.index][i+1];
        }
        return formular.result;
    } else if(strcmp(function, "AVG") == 0 || strcmp(function, "avg") == 0) {
        if(*argument >= 'a') {
            temp.index = *argument-'a';
        } else {
            temp.index = *argument-'A';
        }
        formular.result = 0;
        for(i = 0; i < variable.array[temp.index][0]; i++) {
            formular.result += variable.array[temp.index][i+1];
        }
        return formular.result/variable.array[temp.index][0];
    } else if(strcmp(function, "STD") == 0 || strcmp(function, "std") == 0) {
        if(*argument >= 'a') {
            temp.index = *argument-'a';
        } else {
            temp.index = *argument-'A';
        }
        x = 0;
        for(i = 0; i < variable.array[temp.index][0]; i++) {
            x += pow(variable.array[temp.index][i+1],2);
        }
        x /= variable.array[temp.index][0];
        y = 0;
        for(i = 0; i < variable.array[temp.index][0]; i++) {
            y += variable.array[temp.index][i+1];
        }
        y /= variable.array[temp.index][0];
        y = pow(y,2);
        formular.result = x - y;
        formular.result = sqrt(formular.result);
        return formular.result;
    } else {
        return -1.0;
    }
}

void function_argument(char *position, char input_argument[][LARGESIZE], int count) {

    int i = 0, j = 0;

    for(i = 0; i < count; i++) {
        while(*position != ',' && *position != '\0') {
            input_argument[i][j] = *position;
            position++;
            j++;
        }
        input_argument[i][j] = '\0';
        position++;
    }
}

double calculation(char *position) {

    struct input {
        int decimal;
        int decimal_count;
        int negative;
    } input;

    double i, j, k, l;

    init_stack();// 스택 초기화
    while(*position != '\0'){
        if((*position >= '0' && *position <= '9') || (*position == '-' && *(position+1) >= '0' && *(position+1) <= '9')) {
            i = 0, k = 0, l = 0;
            if(*position == '-') {
                input.negative = 1;
                position++;
            }
            do {
                k = k * 10 + (*position - '0');
                position++;
            } while(*position >= '0' && *position <= '9');
            if(*position == '.') {
                input.decimal = 1;
                position++;
            }
            if(input.decimal == 1) {
                input.decimal_count = 1;
                do {
                    l += pow(0.1, input.decimal_count)*(*position - '0');
                    position++;
                    input.decimal_count++;
                } while(*position >= '0' && *position <= '9');
            }
            i = k + l;
            if(input.negative == 1) {
                i = 0 - i;
            }
            push(i);
            input.negative = 0;
            input.decimal = 0;
            input.decimal_count = 0;
        }  else switch (*position) {
            case '+':
                push(pop() + pop());
                position++;
                break;
            case '-':
                i = pop();
                push(pop() - i);
                position++;
                break;
            case '*':
                push(pop() * pop());
                position++;
                break;
            case '/':
                i = pop();
                push(pop() / i);
                position++;
                break;
            case '^':
                i = pop();
                push(pow(pop(), i));
                position++;
                break;
            default:
                position++;
                break;
        }
    }
    return pop();
}

int operator_precedence(int operator) {
    switch(operator) {
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        default:
            return 3;
            break;
    }
}

double top(void) {
    return stack.space[stack.top];
}

double pop(void) {
    return stack.space[stack.top--];
}

void push(double position) {
    stack.top++;
    stack.space[stack.top] = position;
}

void init_stack(void) {
    memset(stack.space, 0, sizeof(stack.space));
    stack.top = 0;
}

void deallocation(void) {

    int i;

    for(i = 0; i <ALPHABET; i++) {
        if(variable.single[i] != NULL) {
            free(variable.single[i]);
        }
        if(variable.array[i] != NULL) {
            free(variable.array[i]);
        }
    }
}

void save(char *position) {

    int i, j;
    struct file {
        char name[NAMESIZE];
    } file;
    FILE *output_file_pointer = NULL;

    strcpy(file.name, position+5);
    output_file_pointer = fopen(file.name, "wb");
    if(output_file_pointer != NULL) {
        for(i = 0; i < ALPHABET; i++) {
            if(variable.single[i] != NULL) {
                fprintf(output_file_pointer, "%lf\n", *variable.single[i]);
            } else {
                fprintf(output_file_pointer, "NULL\n");
            }
        }
        for(i = 0; i < ALPHABET; i++) {
            if(variable.array[i] != NULL) {
                for(j = 0; j <= *variable.array[i]; j++) {
                    fprintf(output_file_pointer, "%lf\n", *(variable.array[i] + j));
                }
            } else {
                fprintf(output_file_pointer, "NULL\n");
            }
        }
        fclose(output_file_pointer);
    } else {
        print_error(15);
    }
}

void load(char *position) {

        int i, j, k;
        struct file {
            char name[NAMESIZE];
            char buffer[MINSIZE];
            int size;
        } file;
        char *temp;
        FILE *input_file_pointer = NULL;

        strcpy(file.name, position+5);
        input_file_pointer = fopen(file.name, "rb");
        if(input_file_pointer != NULL) {
            for(i = 0; i < 2; i++) {
                for(j = 0; j < ALPHABET; j++) {
                    temp = fgets(file.buffer, MINSIZE, input_file_pointer);
                    temp[strlen(temp)-1] = '\0';
                    switch(i) {
                        case 0:
                            if(strcmp(temp, "NULL") == 0) {
                                free(variable.single[j]);
                                variable.single[j] = NULL;
                            } else {
                                if(variable.single[j] == NULL) {
                                    variable.single[j] = (double *)malloc(sizeof(double));
                                }
                                *variable.single[j] = atof(temp);
                            }
                            break;
                        case 1:
                            if(strcmp(temp, "NULL") == 0) {
                                variable.array[j] = NULL;
                            } else {
                                file.size = (int)atof(temp);
                                variable.array[j] = (double *)calloc((file.size + 1), sizeof(double));
                                for(k = 0; k <= (int)file.size; k++) {
                                    if(k == 0) {
                                        variable.array[j][k] = file.size;
                                    } else {
                                        temp = fgets(file.buffer, MINSIZE, input_file_pointer);
                                        temp[strlen(temp)-1] = '\0';
                                        variable.array[j][k] = atof(temp);
                                    }
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        } else {
            print_error(16);
        }
}

void termianl_clear(void) {
    system("clear");
}

void process_pause(void) {
    printf(" 아무 키나 입력하세요...\n");
    remove_enter();
    termianl_clear();
}

void remove_enter(void) {
    getchar();
}
void print_menu(int select_menu) {
    termianl_clear();
    information();
    switch(select_menu) {
        case 1:
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("┃ Scientific Calculator - Home               ┃\n");
            printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
            printf("┃                                            ┃\n");
            printf("┃ == Main Menu ============================= ┃\n");
            printf("┃                                            ┃\n");
            printf("┃ [1] 단순 연산                              ┃\n");
            printf("┃ [2] 수식 연산                              ┃\n");
            printf("┃ [3] 도움말                                 ┃\n");
            printf("┃ [0] 종료                                   ┃\n");
            printf("┃                                            ┃\n");
            printf("┃ ========================================== ┃\n");
            printf("┃                                            ┃\n");
            printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
            printf(" 입력 : ");
            break;
        case 2:
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("┃ Simple Scientific Calculator - Main        ┃\n");
            printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
            printf(" 입력 :  ");
            break;
        case 3:
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("┃ Formular Scientific Calculator - Main      ┃\n");
            printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
            break;
        default:
            printf(" ERROR : print_menu()'s parameter is not defined\n");
            break;
    }
}

void information(void) {
    printf("\n");
    printf(" ● University : Soongsil University \n");
    printf(" ● Major      : Computer Science & Engineering \n");
    printf(" ● Student ID : 20162448 \n");
    printf(" ● Name       : Kim Byoung June\n");
    printf("\n");
}

void help(void) {
    termianl_clear();
    information();
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃ Help - Main                                ┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃                                            ┃\n");
    printf("┃ ● 단순 연산                                ┃\n");
    printf("┃    ○ 일반 연산자(+, -, *, /, ^) 사용 가능  ┃ \n");
    printf("┃    ○ 일반 변수(A - Z) 사용 불가            ┃ \n");
    printf("┃    ○ 배열 변수(AA - ZZ) 사용 불가          ┃ \n");
    printf("┃    ○ 괄호 사용 가능                        ┃ \n");
    printf("┃    ○ 수학 함수(ADD, AVG, ETC..) 사용 불가  ┃ \n");
    printf("┃                                            ┃\n");
    printf("┃ ● 수식 연산                                ┃\n");
    printf("┃    ○ 일반 연산자(+, -, *, /, ^) 사용 가능  ┃ \n");
    printf("┃    ○ 일반 변수(A - Z) 사용 가능            ┃ \n");
    printf("┃    ○ 배열 변수(AA - ZZ) 사용 가능          ┃ \n");
    printf("┃    ○ 괄호 사용 가능                        ┃ \n");
    printf("┃    ○ 수학 함수(ADD, AVG, ETC..) 사용 가능  ┃ \n");
    printf("┃                                            ┃\n");
    printf("┃ ● 메뉴 이동                                ┃\n");
    printf("┃    ○ end(END) 입력시 홈으로 이동           ┃ \n");
    printf("┃                                            ┃\n");
    printf("┃ ● 저장 및 불러오기                         ┃\n");
    printf("┃    ○ 저장     : save(SAVE) 파일명          ┃ \n");
    printf("┃    ○ 불러오기 : load(LOAD) 파일명          ┃ \n");
    printf("┃                                            ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    process_pause();
}

void print_error(int type) {
    switch(type) {
        case 0:
            printf(" ERROR : 올바르지 않은 입력입니다\n");
            break;
        case 1:
            printf(" ERROR : 선언되지 않은 배열변수\n");
            break;
        case 2:
            printf(" ERROR : ')'바로 다음 피연산자 나올수 없음\n");
            break;
        case 3:
            printf(" ERROR : 피연산자는 연속으로 나올수 없음\n");
            break;
        case 4:
            printf(" ERROR : 연산의 처음에 연산자가 나올수 없음\n");
            break;
        case 5:
            printf(" ERROR : 연산자는 연속해서 나올수 없음\n");
            break;
        case 6:
            printf(" ERROR : 연산자와 피연산자 갯수가 매치되지 않음\n");
            break;
        case 7:
            printf(" ERROR : 올바른 함수형식이 아님'\n");
            break;
        case 8:
            printf(" ERROR : ')'다음 바로 '('가 나올수 없음\n");
            break;
        case 9:
            printf(" ERROR : 피연산자 바로 다음 '('가 나올수 없음\n");
            break;
        case 10:
            printf(" ERROR : 연산의 처음에 ')'나올수 없음\n");
            break;
        case 11:
            printf(" ERROR : '('바로다음 ')' 나올수 없음\n");
            break;
        case 12:
            printf(" ERROR : 연산자 바로다음 ')'나올수 없음\n");
            break;
        case 13:
            printf(" ERROR : '('바로 다음 연산자 나올수 없음\n");
            break;
        case 14:
            printf(" ERROR : 괄호 수가 틀립니다.\n");
            break;
        case 15:
            printf(" ERROR : 파일 저장 오류\n");
            break;
        case 16:
            printf(" ERROR : 파일 읽기 오류\n");
            break;
        default:
            printf(" ERROR : Unknown ERROR\n");
            break;
    }
}
