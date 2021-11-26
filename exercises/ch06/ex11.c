//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

#define SIZE 8

int main(void) {
    // 定义整数数组
    int input[SIZE];
    int i;

    // 提示用户输入8个整数
    printf("Please enter %d integers.\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &input[i]);
    }

    // 逆序打印8个整数
    printf("Here are the values in reverse order you entered:\n");
    for (i = SIZE - 1; i >= 0; i--) {
        printf("%d ", input[i]);
    }
    printf("\n");

    return 0;
}