//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"
#include "ctype.h"
#define AMT1 17850
#define AMT2 23900
#define AMT3 29750
#define AMT4 14875
#define RATE1 0.15
#define RATE2 0.28
void print_menu(void);
void calc(double base_pay, double hours);

int main(void) {
    int pay_level;
    double salary;

    print_menu();
    scanf_s("%d", &pay_level);
    if (pay_level > 0 && pay_level < 5) {
        printf("Enter your salary:");
        scanf_s("%lf", &salary);
        switch (pay_level) {
            case 1:
                calc(AMT1, salary);
                break;
            case 2:
                calc(AMT2, salary);
                break;
            case 3:
                calc(AMT3, salary);
                break;
            default:
                calc(AMT4, salary);
        }

    } else {
        while (isdigit(pay_level) && (pay_level > 5 || pay_level <= 0)) {
            printf("Please enter correct number (1 ~ 5).\n");
            print_menu();
            scanf_s("%d", &pay_level);
        }
    }
    return 0;
}

void print_menu(void) {
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the category or action:\n");
    printf("1) unmarried                            2) householder\n");
    printf("3) married, owned by all                4) married, divorced\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");
}

void calc(double amt, double salary) {
    double taxes;

    if (salary < amt) {
        taxes = salary * RATE1;
    } else {
        taxes = amt * RATE1 + (salary - amt) * RATE2;
    }
    printf("The net is $%.2f.\n", taxes);
}