//
// Created by HRF on 2021/11/16.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calc_days(char *month);

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
    char input[20];
    int day_total;

    // 提示用户输入月份名
    printf("Enter the name of a month:");
    while (scanf("%s", input) == 1 && input[0] != 'q') {
        // 得到截至到当月的总天数
        day_total = calc_days(input);
        if (day_total > 0) {
            // 打印截至到当月的总天数
            printf("There are %d days through %s.\n", day_total, input);
        } else {
            printf("%s is not valid input.\n", input);
        }

        printf("Enter next month (q to quit):");
    }
    puts("bye.");

    return 0;
}

int calc_days(char *month) {
    int total = 0;
    int month_number = 0;
    int i;

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

    if (month_number == 0) {
        total = -1;
    } else {
        // 计算截至到当月的总天数
        for (i = 0; i < month_number; i++) {
            total += months[i].days;
        }
    }

    return total;
}