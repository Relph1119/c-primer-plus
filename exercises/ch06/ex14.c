//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

#define SIZE 8

int main(void) {
    double arr1[SIZE], arr2[SIZE];
    int i;

    // 提示用户输入8个double类型的数，并赋值给第一个数组
    printf("Enter %d numbers to the FIRST array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%lf", &arr1[i]);
    }

    // 使用一个循环
    arr2[0] = arr1[0];
    for (i = 1; i < SIZE; i++) {
        arr2[i] = arr2[i - 1] + arr1[i];
    }

    // 显示两个数组的内容
    printf("All the data of  two array:\n");
    printf("First  Array: ");
    for (int i = 0; i < 8; i++) {
        printf("%10lf. ", arr1[i]);
    }
    printf("\nSecond Array: ");
    for (int i = 0; i < 8; i++) {
        printf("%10lf. ", arr2[i]);
    }

    return 0;
}