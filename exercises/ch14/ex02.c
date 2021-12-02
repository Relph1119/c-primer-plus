//
// Created by HRF on 2021/11/16.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// 得到月份号
int get_month_number(char *month);
// 检查日期是否正确
bool check(int year, int month, int day);
// 计算截至到这一天的总天数
int calc_days(int year, int month, int day);
char *s_gets(char *st, int n);

struct month {
    // 月份名
    char name[10];
    // 月份缩写
    char abbrev[4];
    // 月份天数
    int days;
    // 月份号
    int month_number;
};

const struct month months[12] = {
        {"January",   "Jan", 31, 1},
        {"February",  "Feb", 28, 2},
        {"March",     "Mar", 31, 3},
        {"April",     "Apr", 30, 4},
        {"May",       "May", 31, 5},
        {"June",      "Jun", 30, 6},
        {"July",      "Jul", 31, 7},
        {"August",    "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October",   "Oct", 31, 10},
        {"November",  "Nov", 30, 11},
        {"December",  "Dec", 31, 12}
};

int main(void) {
    int day;
    char month[20];
    int year;
    int day_total;
    int month_number;

    // 提示用户输入日、月和年
    printf("Enter a day:");
    while (scanf("%d", &day) == 1) {
        printf("Enter a month:");
        scanf("%s", month);
        printf("Enter a year:");
        scanf("%d", &year);

        // 获取月份号
        month_number = get_month_number(month);

        // 检测日期是否正确
        if (check(year, month_number, day)) {
            // 计算截至到这一天的总天数
            day_total = calc_days(year, month_number, day);
            printf("There are %d days through %s %d, %d in the year of %d .\n", day_total,
                   months[month_number - 1].abbrev, day, year, year);
        } else {
            printf("The day of %s %d, %d is not valid input.\n", months[month_number - 1].abbrev, day, year);
        }

        printf("Enter a day (q to quit):");
    }

    printf("Bye.\n");
    return 0;
}

bool check(int year, int month, int day) {
    if (day < 0 || day > 31) {
        // 日期不正确
        return false;
    } else if (month <=0 || month > 12) {
        // 月份不正确
        return false;
    } else if (day > months[month - 1].days) {
        // 当月的日期不正确
        return false;
    } else if (year % 4 == 0 && month == 2 && day > 29) {
        // 闰年2月的日期不正确
        return false;
    } else {
        return true;
    }
}

int calc_days(int year, int month, int day) {
    int total = 0;
    int i;
    // 如果是闰年，且月份号大于2月份，则加1天
    if (month > 2 && year % 4 == 0) {
        total += 1;
    }

    for (i = 0; i < month - 1; i++) {
        total += months[i].days;
    }
    total += day;

    return total;
}

int get_month_number(char *month) {
    int month_number = 0;
    int i;

    // 如果能转换成int类型，则返回月份号
    if (atoi(month) > 0 && atoi(month) <= 12) {
        month_number = atoi(month);
    } else {
        // 将首字母转成大写
        month[0] = toupper(month[0]);
        // 将其他字母转成小写
        for (i = 1; month[i] != '\0'; i++) {
            month[i] = tolower(month[i]);
        }

        // 循环匹配月份名或月份缩写
        for (i = 0; i < 12; i++) {
            if (strcmp(month, months[i].name) == 0 || strcmp(month, months[i].abbrev) == 0) {
                // 找到月份号
                month_number = months[i].month_number;
                break;
            }
        }
    }
    return month_number;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}