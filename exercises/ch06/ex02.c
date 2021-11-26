//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>
// 设置需要打印的数量
#define SIZE 5

int main(void) {
    // 循环打印每一行
    for (int i = 0; i < SIZE; i++) {
        // 循环打印该行的字符
        for (int j = 0; j <= i; j++)
            printf("$");
        printf("\n");
    }

    return 0;
}