//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

#define SIZE 8

int main(void) {
    // 定义一个包含8个元素的int类型数组
    int arr[SIZE];
    int i;
    int value = 1;

    // 设置数组元素的值
    for (i = 0; i < SIZE; i++) {
        // 根据i，设置为2的i次幂
        arr[i] = value;
        value *= 2;
    }

    i = 0;
    // 使用do while循环显示数组元素的值
    printf("Here are the list values:\n");
    do {
        printf("%d ", arr[i++]);
    } while (i < SIZE);
    printf("\n");

    return 0;
}