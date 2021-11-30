//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

double power(double n, int p);

int main(void) {
    double x, xpow;
    int exp;

    // 提示用户输入
    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2) {
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}

double power(double n, int p) {
    double pow;

    if (p == 0) {
        // 0的0次幂未定义
        if (n == 0) {
            printf("0 to the 0 undefined; using 1 as the value\n");
        }
        // 任何数的0次幂都是1
        return 1.0;
    }

    // 0的任何次幂等于0
    if (n == 0) {
        return 0.0;
    }

    if (p > 0) {
        // 计算正整数次幂
        pow = n * power(n, p - 1);
    } else {
        // 计算负整数次幂
        pow = power(n, p + 1) / n;
    }

    return pow;
}