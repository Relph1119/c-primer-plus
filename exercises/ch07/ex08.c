//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"
#include "ctype.h"
#define BASE_PAY1 8.75
#define BASE_PAY2 9.33
#define BASE_PAY3 10.00
#define BASE_PAY4 11.20
#define BASE_HRS 40
#define OVERTIME 1.5
#define AMT1 300
#define AMT2 150
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
void print_menu(void);
void calc(double base_pay, double hours);

int main(void) {
    int pay_level;
    double hours;

    print_menu();
    scanf_s("%d", &pay_level);
    if (pay_level > 0 && pay_level < 5) {
        printf("Enter the number of hours worked this week:");
        scanf_s("%lf", &hours);
        switch (pay_level) {
            case 1:
                calc(BASE_PAY1, hours);
                break;
            case 2:
                calc(BASE_PAY2, hours);
                break;
            case 3:
                calc(BASE_PAY3, hours);
                break;
            default:
                calc(BASE_PAY4, hours);
        }

    } else  {
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
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $%.2f/hr                            2) $%.2f/hr\n", BASE_PAY1, BASE_PAY2);
    printf("3) $%.2f/hr                           4) $%.2f/hr\n", BASE_PAY3, BASE_PAY4);
    printf("5) quit\n");
    printf("*****************************************************************\n");
}

void calc(double base_pay, double hours) {
    double gross, net, taxes;

    if (hours <= BASE_HRS) {
        gross = hours * base_pay;
    } else {
        gross = BASE_HRS * base_pay + (hours - BASE_HRS) * OVERTIME;
    }

    if (gross <= AMT1) {
        taxes = gross * RATE1;
    } else if (gross <= AMT1 + AMT2) {
        taxes = AMT1 * RATE1 + (gross - AMT2) * RATE2;
    } else {
        taxes = AMT1 * RATE1 + AMT2 * RATE2 + (gross - AMT1 - AMT2) * RATE3;
    }
    net = gross - taxes;

    printf("gross: $%.2f; taxes: $%.2f; net: $%.2f\n", gross, taxes, net);
}