//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

void larger_of(double *p1, double *p2);

int main(void) {
    double x, y;

    // 提示用户输入两个值
    printf("Enter tow number:");
    while (scanf("%lf %lf", &x, &y) == 2) {
        larger_of(&x, &y);
        printf("The modified values are %g and %g.\n", x, y);
        printf("Next two value (q to quit):");
    }

    printf("Bye!");
    return 0;
}

void larger_of(double *p1, double *p2) {
    // 将两个数中较大的值进行重新赋值
    *p1 = *p2 = *p1 > *p2 ? *p1 : *p2;
}
