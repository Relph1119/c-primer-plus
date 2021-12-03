//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <time.h>

void delay(double second);

int main(void) {
    double sec;

    // 提示用户输入延迟的时间（单位秒）
    printf("Enter some seconds to delay:");
    while (scanf("%lf", &sec) == 1 && sec != 0) {
        // 执行延迟程序
        delay(sec);
        printf("Enter some seconds to delay (q to quit):");
    }

    printf("Bye.");
    return 0;
}

void delay(double second) {
    // 获取系统开始时间
    clock_t start = clock();
    printf("Test %lf second delay\n", second);
    // 获取系统当前时间，用于计算时间差
    clock_t now = clock();

    while (((double) (now - start)) / CLOCKS_PER_SEC < second) {
        // 当每过1秒时，打印一次信息
        if ((now - start) % CLOCKS_PER_SEC == 0) {
            printf("The delay time is %lf second.\n", ((double) (now - start)) / CLOCKS_PER_SEC);
        }
        // 重新获取系统当前时间
        now = clock();
    }
}