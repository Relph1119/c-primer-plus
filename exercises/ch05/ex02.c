//
// Created by HRF on 2021/11/1.
//
#include <stdio.h>

int main(void) {
    int num;

    // 提示用户输入一个整数
    printf("Enter a number:");
    scanf("%d", &num);
    // 得到上限值
    int limits = num + 10;
    // 使用while循环，打印范围内的所有整数
    printf("The number from %d to %d:\n", num, limits);
    while (num <= limits) {
        printf("%d ", num);
        num++;
    }
    return 0;
}