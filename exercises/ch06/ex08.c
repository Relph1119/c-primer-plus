//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void) {
    double n, m;
    double res;

    // 提示用户输入两个浮点数
    printf("Enter a pair of floating-point numbers:");

    while (scanf("%lf %lf", &n, &m) == 2) {
        // 计算两数之差除以两数乘积的结果
        res = (n - m) / (n * m);
        // 打印结果
        printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n", n, m, n, m, res);
        // 提示用户再次输入两个浮点数
        printf("Enter next pair (non-numeric to quit):");
    }

    return 0;
}