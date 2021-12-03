//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
// 调和平均数的计算
#define HMEAN(X, Y) (1 / ((1 / (X) + 1 / (Y)) / 2))

int main(void) {
    double f1, f2, ans;

    // 提示用户输入两个数
    printf("Enter a pair of numbers (q to quit):");
    while (scanf("%lf %lf", &f1, &f2) == 2 && f1 != 0 && f2 != 0) {
        // 计算两个数的调和平均数
        ans = HMEAN(f1, f2);
        printf("The harmonic mean of %g %g is %g\n", f1, f2, ans);
        // 提示用户再次输入
        printf("Enter next pair of numbers (q to quit):");
    }

    printf("Bye.\n");
    return 0;
}