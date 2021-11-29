//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>
// 单身的税金
#define AMT1 17850
// 户主的税金
#define AMT2 23900
// 已婚共有的税金
#define AMT3 29750
// 已婚离异的税金
#define AMT4 14875
#define RATE1 0.15
#define RATE2 0.28

void print_menu(void);

void calc(double amt, double salary);

int main(void) {
    // 税收等级
    int pay_level;
    // 应征税的收入
    double salary;
    // 税金标准
    double pay;

    // 打印菜单信息
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
        // 计算税金
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
        // 在基础收入之内
        taxes = salary * RATE1;
    } else {
        // 超过基础收入
        taxes = amt * RATE1 + (salary - amt) * RATE2;
    }
    printf("The net is $%.2f.\n", taxes);
}