//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void) {
    int lower, upper, index;
    int square, cube;

    // 输入下限
    printf("Enter starting integer:");
    scanf("%d", &lower);
    // 输入上限
    printf("Enter ending integer:");
    scanf("%d", &upper);

    printf("%5s %10s %15s\n", "num", "square", "cube");
    // 使用for循环打印整数、该数的平方、该数的立方
    for (index = lower; index <= upper; index++) {
        // 计算该数的平方
        square = index * index;
        // 计算该数的立方
        cube = index * square;
        printf("%5d %10d %15d\n", index, square, cube);
    }

    return 0;
}