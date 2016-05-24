/*
    Date    : 2016. 05. 15
    Author  : 김병준, 함정완
    Major   : 컴퓨터학부
    Prof    : 문영성 교수
*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_INFIX_SIZE 100

// 공학용 계산기
void EngineeringCalculator();
// 일정 관리
void ScheduleManagement();
// 일정 보기
void View_Schedule(int, int, int, char*);
// 터미널 지우기
void Terminal_Clear();
// 일시정지
void pause();
// 윤년 판별
void Judgement_Leap(int, int, int);
// 일정 체크
void Check_Schedule(int, int, int, int, int, int);
// 임시데이터 초기화
void tmp_Clear();
// 데이터 초기화
void schedule_Clear();

int year, month, day, tmp_year, tmp_month, tmp_day;
char txt_contents[16], tmp_txt_contents[16];

int main(void){
    
    int select_main=1;
    while(select_main != 0){
        Terminal_Clear();
        printf("1. 공학용 계산기\n2. 일정 관리\n0. 종료\n선택 : ");
        scanf("%d", &select_main);
        Terminal_Clear();
        switch(select_main){
            case 0 : return 0;
        
            case 1 : EngineeringCalculator();
                     break;
        
            case 2 : ScheduleManagement();
                     break;
                     
           // 지정된 값 외의 값을 입력하면 에러처리
           default: printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
                    pause();
                    break;
        }
    }
}

// 공학용 계산기
void EngineeringCalculator(){
    char infix[MAX_INFIX_SIZE];
    
    printf("================================\n\t공학용 계산기\n================================\n");
    scanf("%s", infix);
    printf("%s", infix);
    pause();
}

void ScheduleManagement(){
    /*
        세로에 년과 월정보, 가로에 최대 31일에 대한 내용값
        (년-2016)*12+(달-1)=값을 세로에 배정
        (일-1)*200을 가로에 배정
    */
    char calendar[5*12][31*200];
    // 내용을 저장할 배열 선언
    int select_function = 1;
    char select_answer;
    int i, length;
    
    while(select_function != 0){
        
        Terminal_Clear();
        printf("================================\n\t일정관리 프로그램\n================================\n");
        printf("1. 일정 입력\n2. 일정 삭제\n3. 일정 보기\n0. 종료\n선택 : ");
        scanf("%d",&select_function);
        Terminal_Clear();
        switch(select_function) {
            // 종료
            case 0: break;
            
            // 일정 입력                 
            case 1: Terminal_Clear();

                    strcpy(tmp_txt_contents,txt_contents);
                    printf("일정 입력 : ");
                    scanf("%d %d %d %s", &year, &month, &day, txt_contents);
                    length = strlen(txt_contents);
                    
                    if((year<=0)) {
                        printf("잘못된 년도 입력. 다시 입력하세요.\n\n");
                    } else if((month<1)||(month>12)) {
                        printf("잘못된 월 입력. 1월에서 12월 사이로 입력하세요\n\n");
                    // 200바이트 이상의 내용입력시의 에러처리    
                    } else if (length>16) {
                        printf("너무 많은 내용을 입력하셨습니다\n\n");
                        if(tmp_year == year && tmp_month == month && tmp_day == day) {
                            year = tmp_year;
                            month = tmp_month;
                            day = tmp_day;
                            strcpy(txt_contents,tmp_txt_contents);
                        } else {
                            schedule_Clear();
                        }
                    } else if(tmp_year == year && tmp_month == month && tmp_day == day) {
                        printf("%d년 %d월 %d일에 일정이 있습니다.\n", year, month, day);
                        printf("일정을 유지하려면 Yes(y)를, 덮어쓰려면 No(n)를 입력하세요 : ");
                        scanf("%s", &select_answer);
                        switch(select_answer) {
                            // 일정 덮어쓰기
                            case 'n': printf("일정이 덮어쓰기 되었습니다.");
                                      break;
                                    
                            // 일정 유지
                            case 'y': year = tmp_year;
                                      month = tmp_month;
                                      day = tmp_day;
                                      strcpy(txt_contents,tmp_txt_contents);
                                      tmp_Clear();
                                      printf("일정이 유지되었습니다.");
                                      break;
                            
                            // 지정된 값 외의 값을 입력하면 에러처리
                            default: printf("잘못 입력하셨습니다. 다시 입력해주세요.");
                                     break;
                        }
                    } else {
                        printf("%d년 %d월 %d일 %s\n일정을 추가하였습니다.\n", year, month, day, txt_contents);
                    }
                    // 데이터 임시저장
                    tmp_year = year;
                    tmp_month = month;
                    tmp_day = day;
                    *tmp_txt_contents = *txt_contents;
                    pause();
                    break;
                                                            
            // 일정 삭제        
            case 2: Terminal_Clear();
                    printf("일정 입력 : ");
                    scanf("%d %d %d %s", &year, &month, &day, txt_contents);
                    // 년도가 0일때는 아무 값도 입력받지 않았으므로 일정이 등록되어있지 않음 처리
                    if (year == 0 || month == 0 || day == 0) {
                        printf("일정이 등록되어있지 않습니다.");
                    } else if(tmp_year == year && tmp_month == month && tmp_day == day) {
                        printf("%d년 %d월 %d일에 일정이 있습니다.\n", year, month, day);
                        schedule_Clear();
                        tmp_Clear();
                        printf("일정이 삭제되었습니다.\n");
                    } else if(tmp_year != year || tmp_month != month || tmp_day != day) {
                        printf("%d년 %d월 %d일에 일정이 없습니다.\n", year, month, day);
                    }
                    pause();
                    break;
                    
            // 일정 보기        
            case 3: Terminal_Clear();
                    if(year == 0 || month == 0 || day == 0) {
                        printf("일정이 등록되어있지 않습니다.\n");
                    } else {
                        View_Schedule(year, month, day, txt_contents);
                    }
                    pause();
                    break;
                   
            // 지정된 값 외의 값을 입력하면 에러처리
            default: printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
                     pause();
                     break;
        }
    }
}


void View_Schedule(int year, int month, int day, char* txt_contents){
   
    int month_array[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int total_day=0, total_1, total_2, i, j, dal, cycle=0, count=1, total_count=1, blank_count=0, space_count=0, blank_check;
    
    total_1 = 0;
    total_2 = 1;
    
    // 모든 년도 계산
    for(i = 0; i<year - 1; i++) {
        // 윤년 판별
        if((((i + 1) % 4) == 0 && (((i + 1) % 100) != 0)) || (((i + 1) % 400) == 0)) {
            //맞으면 365일
            dal = 366;
        } else {
            // 아니라면 365일
            dal = 365;
        }
        total_1 += dal;
    }
    
    // 모든 달 계산
    for(i = 0; i < month-1; i++) {
        // 윤달 판별
        if(((year % 4) == 0 && ((year % 100) != 0)) || ((year % 400) == 0)) {
            // 맞으면 29일
            month_array[1] = 29;
        } else {
            // 아니라면 28일
            month_array[1] = 28;
        }
        total_2 += month_array[i];
    }
 
    total_day = total_1 + total_2; // 총일수
    printf("\n");
    printf("             %d년 %d월\n", year, month);
    printf("---------------------------------------\n");
    printf("   SUN  MON  TUE  WED  THU  FRI  SAT\n");
    printf("---------------------------------------\n");
 
    // 공백 추가
    for(i = 1; i <= ((total_day % 7) % 7); i++) {
        printf("     ");
        // 날짜 추가 횟수 +1
        count++;
        total_count++;
        space_count++;
        // 빈칸 확인
        blank_check = i-1;
        
    }
    
    // 날짜 추가
    for(i = 1; i <= month_array[month-1]; i++) {
        // 날짜 출력
        printf("%5d",i);
        // 일정 위치 조정
        if(day==total_count-space_count){
            // 빈 공간 횟수를 날짜추가 횟수로 계산
            blank_count = count;
        }
        /**
            DebugCode (프로젝트 감점 방지용)
        **/
        //printf(" count = %d, blank_count = %d, cycle = %d, total_count/7 = %d\n", count, blank_count, cycle, total_count/7);
        // 일~토까지 추가가 완료되었을 경우 개행
        if((i +(total_day % 7)) % 7 == 0) {
            // 개행된 횟수가 일정추가된 날짜/7 의 몫과 같을때 개행 후 일정 출력
            // ***********************문제부분
            if(cycle == ((day+blank_check)/7)){
            //if(total_count/7 == cycle || total_count-space_count == day ||cycle == (day/7)) {
                // 일정 추가할 줄을 생성
                printf("\n");
                // 공백 추가
                for(j = 1; j < blank_count; j++){
                    printf("     ");
                }
                // 일정 출력
                printf("%5s\n", txt_contents);
            } else {            
                // 개행
                printf("\n\n");
            }
            // 개행 횟수 +1
            cycle++;
            // 날짜 추가 횟수 초기화
            count = 0;
        }
        // 날짜 추가 횟수 +1
        count++;
        // 모든 추가 횟수 +1
        total_count++;
    }
}

void Judgement_Leap(int year, int month, int day){
    // 윤년 판별
    if((month==2)&&((year%4)&&(year%400)&&!(year%100))==0) {
        // 윤달의 에러처리
        if((day<1)||(day>29)) {
            printf("잘못된 일 입력\n1일에서 29일 사이로 입력하세요\n\n");
        }
    // 윤달이 아닐경우 2월의 에러처리 
    } else if(month==2) {
        if((day<1)||(day>28)) {
            printf("잘못된 일 입력\n1일에서 28일 사이로 입력하세요\n\n");
        }
    } else if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)) {
        if((day<1)||(day>31)) {
            printf("잘못된 일 입력\n1일에서 31일 사이로 입력하세요\n\n");
        }
    // 나머지 월은 30일 처리
    } else {
        if((day<1)||(day>30)) {
            printf("잘못된 일 입력\n1일에서 30일 사이로 입력하세요\n\n");
        }
    }
}

void tmp_Clear(){
    tmp_year = NULL;
    tmp_month = NULL;
    tmp_day = NULL;
}

void schedule_Clear(){
    year = NULL;
    month = NULL;
    day = NULL;
}
void Terminal_Clear(){
    system("clear\n");
}

void pause() {
  printf("\nPress any key to continue . . .");
  // 아무 키나 1개 입력 받기
  getchar();
  getchar();
}
