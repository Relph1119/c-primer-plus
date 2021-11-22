//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>
#define AMT1 17850
#define AMT2 23900
#define AMT3 29750
#define AMT4 14875
#define RATE1 0.15
#define RATE2 0.28

void print_menu(void);
void calc(double amt, double salary);

int main(void) {
    int pay_level;
    double salary;
    double pay;

    print_menu();
    while ((scanf("%d", &pay_level)) == 1 && pay_level != 5) {
        if (pay_level == '\n')
            continue;

        switch (pay_level) {
            case 1:
                pay = AMT1;
                break;
            case 2:
                pay = AMT2;
                break;
            case 3:
                pay = AMT3;
                break;
            case 4:
                pay = AMT4;
                break;
            default:
                printf("Please enter choice 1~5 .\n");
                print_menu();
                continue;
        }
        printf("Enter your salary:");
        scanf("%lf", &salary);
        calc(pay, salary);

        print_menu();
    }

    printf("Bye.");
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