//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

#define BASE_PAY1 8.75
#define BASE_PAY2 9.33
#define BASE_PAY3 10.00
#define BASE_PAY4 11.20
// 加班超过40小时
#define BASE_HRS 40
// 加班超过40小时为1.5倍
#define OVERTIME 1.5
// 前300美元
#define AMT1 300
// 续150美元
#define AMT2 150
// 前300美元的税率15%
#define RATE1 0.15
// 续150美元的税率为20%
#define RATE2 0.20
// 余下的税率为25%
#define RATE3 0.25

void print_menu(void);

void calc(double base_pay, double hours);

int main(void) {
    int pay_level;
    double hours;
    double pay;

    // 打印菜单
    print_menu();
    // 读取用户选择
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
        // 提示用户输入工作的小时数
        printf("Enter the number of hours worked this week:");
        scanf("%lf", &hours);
        // 计算并打印工资总额、税金和净收入
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

    // 计算工资总额
    if (hours <= BASE_HRS) {
        gross = hours * base_pay;
    } else {
        gross = BASE_HRS * base_pay + (hours - BASE_HRS) * OVERTIME;
    }

    // 计算税率
    if (gross <= AMT1) {
        taxes = gross * RATE1;
    } else if (gross <= AMT1 + AMT2) {
        taxes = AMT1 * RATE1 + (gross - AMT2) * RATE2;
    } else {
        taxes = AMT1 * RATE1 + AMT2 * RATE2 + (gross - AMT1 - AMT2) * RATE3;
    }

    // 计算净收入
    net = gross - taxes;

    // 打印工资总额、税金和净收入
    printf("gross: $%.2f; taxes: $%.2f; net: $%.2f\n", gross, taxes, net);
}