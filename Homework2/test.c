#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DAYS 31
#define MAX_CONTENT 100
#define FILENAME "schedule.txt"

typedef struct
{
    int day;
    char content[MAX_CONTENT];
} Schedule;

Schedule schedules[MAX_DAYS + 1]; // in computer index begin 0, but day begin 1
int days_in_month;

// check leep year(윤년)
int is_leap_year(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

//  get start day of month 1년 1일을 월요일로 계산함
int get_start_day(int year, int month)
{
    int total_days = 0;
    for (int y = 1; y < year; y++)
    {
        total_days += is_leap_year(y) ? 366 : 365;
    }
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year))
        month_days[1] = 29;
    for (int m = 1; m < month; m++)
    {
        total_days += month_days[m - 1];
    }
    return (total_days + 1) % 7; // sunday=0, monday=1, tuesday=2 .... saturday=6
    // plus 1 because sunday=0 -> arcording 1/1/0001 is monday so must + 1
}

// calculate month from 1 to 12,    2->28(29 if it's leap year)
int get_days_in_month(int year, int month)
{
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year))
        month_days[1] = 29;
    return month_days[month - 1];
}

// print calender
void print_calendar(int year, int month)
{
    int start = get_start_day(year, month);
    days_in_month = get_days_in_month(year, month);

    printf("\t    %d년 %d월\n", year, month);
    printf("\n  Sun Mon Tue Wed Thu Fri Sat\n");

    int day = 1;
    for (int i = 0; i < start; i++)
        printf("    ");
    for (int i = start; day <= days_in_month; i++)
    {
        if (schedules[day].day != 0)
            printf("  *%d", day);
        else
            printf("  %2d", day);
        if (i % 7 == 6)
            printf("\n");
        day++;
    }
    if ((start + days_in_month) % 7 != 0) // if last row not finish at saturday then newline by 수공
        printf("\n");
}

// save data into file
void save_to_file(int year, int month)
{
    FILE *fp = fopen(FILENAME, "w");
    for (int i = 1; i <= days_in_month; i++)
    {
        if (schedules[i].day != 0) // check schedule day*
        {
            fprintf(fp, "%d %d %d %s\n", year, month, i, schedules[i].content);
        }
    }
    fclose(fp);
}

// read data from file
void load_from_file(int year, int month)
{
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) // fp == null
        return;
    int y, m, d;
    char buf[MAX_CONTENT];
    while (fscanf(fp, "%d %d %d ", &y, &m, &d) != EOF)
    {
        if (y == year && m == month)
        {
            fscanf(fp, "%[^\n]\n", buf);
            schedules[d].day = d;
            strcpy(schedules[d].content, buf);
        }
    }
    fclose(fp);
}

// enter 일정의 calender
void input_schedule()
{
    int d;
    while (1)
    {
        printf("날짜를 입력하세요 : ");
        scanf("%d", &d);
        if (d == 0)
        {
            break;
        }
        if (d < 1 || d > days_in_month || schedules[d].day != 0)
        {
            printf("이미 일정이 있거나 잘못된 날짜입니다.\n");
            continue;
        }
        printf("일정을 입력하세요 : ");
        getchar(); // remote \n
        scanf("%[^\n]", schedules[d].content);
        getchar(); // remote '\n' in 남은 stdin'
        schedules[d].day = d;
        break;
    }
}

// delete 일정의 calender
void delete_schedule()
{
    int d;
    while (1)
    {
        printf("날짜를 입력하세요 : ");
        scanf("%d", &d);
        if (d == 0)
        {
            break;
        }
        else if (d < 1 || d > days_in_month || schedules[d].day == 0)
        {
            printf("해당 날짜에 일정이 없습니다.\n");
            continue;
        }
        schedules[d].day = 0;           // mark this day = empty
        schedules[d].content[0] = '\0'; // 삭제 내용
        break;
    }
}

// 일정 보기
void view_schedule(int year, int month)
{
    int d;
    while (1)
    {
        printf("날짜를 입력하세요 : ");
        scanf("%d", &d);
        if (d == 0)
        {
            break;
        }
        if (d < 1 || d > days_in_month || schedules[d].day == 0)
        {
            printf("해당 날짜에 일정이 없습니다.\n");
            continue;
        }
        printf("%d년 %d월 %d일 일정은 %s입니다.\n", year, month, d, schedules[d].content);
        break;
    }
}

int main()
{
    int year, month, menu;
    printf("년을 입력하세요: ");
    scanf("%d", &year);
    printf("월을 입력하세요: ");
    scanf("%d", &month);
    load_from_file(year, month);
    print_calendar(year, month);
    system("clear");
    while (1)
    {
        print_calendar(year, month);
        printf("\n1. 일정 입력\t2. 일정 삭제\t3. 일정 확인\t4. 종료\n\n");
        printf("메뉴를 입력하세요 : ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            input_schedule();
            system("clear");
            break;
        case 2:
            delete_schedule();
            system("clear");
            break;
        case 3:
            view_schedule(year, month);
            getchar(); // delete '\n'
            printf("enter to exit");
            getchar(); // enter키보드 입력 기다려
            system("clear");
            break;
        case 4:
            save_to_file(year, month);
            return 0;
        default:
            printf("잘못된 입력입니다.\n\n");
            getchar(); // delete '\n'
            printf("enter to back menu");
            getchar(); // enter키보드 입력 기다려
            system("clear");
        }
    }

    return 0;
}
