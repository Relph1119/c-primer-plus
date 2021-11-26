//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void) {
    int lower, upper, index;
    int sum;

    // 提示用户输入一个上限整数和一个下限整数
    printf("Enter lower and upper integer limits:");
    while (scanf("%d %d", &lower, &upper) == 2 && lower < upper) {
        sum = 0;
        // 求范围内所有整数的平方和
        for (index = lower; index <= upper; index++) {
            sum += index * index;
        }
        // 打印结果
        printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        // 提示用户再次输入
        printf("Enter next set of limits:");
    }

    printf("Done");
    return 0;
}