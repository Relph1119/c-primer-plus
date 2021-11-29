//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    int n;
    double even_sum = 0;
    int even_count = 0;
    double odd_sum = 0;
    int odd_count = 0;

    // 提示用户输入整数，直到0结束
    printf("Please input integer numbers (0 to quit):\n");
    while (scanf("%d", &n) == 1 && n != 0) {
        // 计算偶数的个数、偶数和
        if (n % 2 == 0) {
            even_sum += n;
            even_count++;
        } else {
            // 计算奇数的个数、奇数和
            odd_sum += n;
            odd_count++;
        }
    }

    // 打印偶数个数
    printf("Number of evens: %d,", even_count);
    if (even_count > 0) {
        // 打印偶数的平均值
        printf(" average: %g\n", even_sum / even_count);
    }

    // 打印奇数个数
    printf("Number of odds: %d,", odd_count);
    if (odd_count > 0) {
        // 打印奇数的平均值
        printf(" average: %g\n", odd_sum / odd_count);
    }
    printf("Done\n");

    return 0;
}
