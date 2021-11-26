//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    // 年利率
    const double RATE_YEAR = 0.08;

    int year = 0;
    // 总金额
    double chuckie = 100;

    // 打印账户记录
    printf("Here is Chuckie's account recode:\n");
    printf("%5s %6s\n", "Year", "Account");
    do {
        // 年利率计算
        chuckie = chuckie + chuckie * RATE_YEAR;
        // 每年最后一天取10万美元
        chuckie -= 10;
        year++;
        printf("%4d %8.2f\n", year, chuckie > 0 ? chuckie : 0);
    } while (chuckie > 0);

    // 打印结果
    printf("%d years later, Chuckie's account is ZERO.\n", year);
    return 0;
}