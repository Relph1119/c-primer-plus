//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>
// 基本工资10美元/小时
#define BASE_PAY 10
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

int main(void) {
    double hours;
    double gross, net, taxes;

    // 提示用户输入一周工作的小时数
    printf("Enter the number of hours worked this week:");
    scanf("%lf", &hours);

    // 计算工资总额
    if (hours <= BASE_HRS) {
        gross = hours * BASE_PAY;
    } else {
        gross = BASE_HRS * BASE_PAY + (hours - BASE_HRS) * OVERTIME;
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

    return 0;
}

