//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void) {
    int limit;
    // 提示用户输入次数
    printf("Enter the number of times you want:");

    while (scanf("%d", &limit) == 1 && limit > 0) {
        // 初始化求和变量
        double sum = 0, den = 1.0;
        // 计算第一个无限序列总和
        for (int i = 0; i <= limit; i++) {
            sum += 1.0 / den++;
        }
        // 打印第一个无限序列总和的结果
        printf("1.0 + 1.0 / 2.0 + 1.0 / 3.0 + 1.0 / 4.0 +... + 1.0 / %d = %f\n", limit, sum);

        sum = 0, den = 1.0;
        // 计算第二个无限序列总和
        for (int i = 0; i <= limit; i++) {
            // 对符号进行设置
            int sign = 1;
            if (i % 2 != 0) {
                sign = -1;
            }
            sum += sign * (1.0 / den++);
        }
        // 打印第二个无限序列总和的结果
        printf("1.0 - 1.0 / 2.0 + 1.0 / 3.0 - 1.0 / 4.0 +... + 1.0 / %d = %f\n", limit, sum);

        // 提示用户再次输入次数
        printf("Enter next number of times (0 or less to quit):");
    }

    return 0;
}