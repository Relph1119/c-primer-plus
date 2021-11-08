//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"
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
    double pay;

    print_menu();
    while ((scanf("%d", &pay_level)) == 1 && pay_level != 5) {
        if (pay_level == '\n')
            continue;

        switch (pay_level) {
            case 1:
                pay = BASE_PAY1;
                break;
            case 2:
                pay = BASE_PAY2;
                break;
            case 3:
                pay = BASE_PAY3;
                break;
            case 4:
                pay = BASE_PAY4;
                break;
            default:
                printf("Please enter choice 1~5 .\n");
                print_menu();
                continue;
        }
        printf("Enter the number of hours worked this week:");
        scanf("%lf", &hours);
        calc(pay, hours);

        print_menu();
    }

    printf("Bye.");
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