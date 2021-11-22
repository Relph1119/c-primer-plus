//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>
#define BASE_PAY 10
#define BASE_HRS 40
#define OVERTIME 1.5
#define AMT1 300
#define AMT2 150
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void) {
    double hours;
    double gross, net, taxes;

    printf("Enter the number of hours worked this week:");
    scanf("%lf", &hours);

    if (hours <= BASE_HRS) {
        gross = hours * BASE_PAY;
    } else {
        gross = BASE_HRS * BASE_PAY + (hours - BASE_HRS) * OVERTIME;
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

    return 0;
}

