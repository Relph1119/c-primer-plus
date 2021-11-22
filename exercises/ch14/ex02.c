//
// Created by HRF on 2021/11/16.
//
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

int calc_days(int year, int month, int day);
int get_month_number(char *month);
char *s_gets(char *st, int n);

struct month {
    char name[10];
    char abbrev[4];
    int days;
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
    int day_total = 0;
    int month_number;

    printf("Enter a day:");
    while (scanf("%d", &day) == 1) {
        printf("Enter a month:");
        scanf("%s", month);
        printf("Enter a year:");
        scanf("%d", &year);

        month_number = get_month_number(month);

        day_total = calc_days(year, month_number, day);
        if (day_total > 0) {
            printf("There are %d days through %s %d, %d in the year of %d .\n", day_total, months[month_number - 1].abbrev, day, year, year);
        } else {
            printf("The day of %s %d, %d is not valid input.\n", month, day, year);
        }

        printf("Enter a day:");
    }

    printf("Bye.\n");
    return 0;
}

int calc_days(int year, int month, int day) {
    int total = 0;
    int i;

    if (month > 2 && year % 4 == 0) {
        total += 1;
    } else if ((month == 2 && day > 29 && year % 4 == 0) ||
               (month > 31) || month == 0) {
        return total;
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

    if (atoi(month) > 0 && atoi(month) <= 12) {
        month_number = atoi(month);
    } else {
        month[0] = toupper(month[0]);
        for (i = 1; month[i] != '\0'; i++) {
            month[i] = tolower(month[i]);
        }

        for (i = 0; i < 12; i++) {
            if (strcmp(month, months[i].name) == 0 || strcmp(month, months[i].abbrev) == 0) {
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