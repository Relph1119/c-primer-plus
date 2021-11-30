//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

// 求数组中的最大值
int max_arr(const int arr[], int n);
// 打印数组
void display_arr(const int arr[], int n);

int main(void) {
    int arr[] = {1, 2, 3, 4, 12, 6, 7, 8, 9, 10};
    // 计算数组长度
    int length = sizeof(arr) / sizeof arr[0];
    int max;

    printf("The array is ");
    display_arr(arr, length);
    // 调用函数求数组的最大值
    max = max_arr(arr, length);
    printf("The largest value is %d\n", max);

    return 0;
}

int max_arr(const int arr[], int n) {
    int i;
    int max = arr[0];
    for (i = 0; i < n; i++) {
        // 比较并记录最大值
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void display_arr(const int arr[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}