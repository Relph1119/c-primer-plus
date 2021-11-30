//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

double harmean(double x, double y);

int main(void) {
    double x, y;

    // 提示用户输入两个double类型的数
    printf("Enter two double-type number:");
    while (scanf("%lf %lf", &x, &y) == 2) {
        // 检查是否为0
        if (x == 0 || y == 0) {
            printf("Enter two double-type number (other than 0):");
            continue;
        }
        // 打印结果
        printf("The harmean of (%g, %g) is %g\n", x, y, harmean(x, y));
        printf("Enter next double-type number (q to quit):");
    }

    return 0;
}

double harmean(double x, double y) {
    // 计算调和平均数：两个倒数的平均值的倒数
    return 1 / ((1.0 / 2.0) * (1 / x + 1 / y));
}
