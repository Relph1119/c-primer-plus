//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

double power(double n, int p);

int main(void) {
    double x, xpow;
    int exp;

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
        if (n == 0)
            printf("0 to the 0 undefined; using 1 as the value\n");
        pow = 1.0;
    } else if (n == 0) {
        pow = 0.0;
    } else if (p > 0) {
        pow = n * power(n, p - 1);
    } else {
        pow = power(n, p + 1) / n;
    }

    return pow;
}