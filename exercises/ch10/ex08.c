//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

#define ARR_LEN 7
#define TARGET_LEN 3

// 数组拷贝
void copy_arr(int target[], const int source[], int num);

// 显示数组
void display_array(int arr[], int num);

int main(void) {
    int source[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7};
    int target[TARGET_LEN];

    printf("The array of arr is ");
    // 显示数组
    display_array(source, ARR_LEN);
    /*
     * 调用数组拷贝函数，由于是数组元素的地址，
     * 通过+2表示从第3个元素开始，对数组进行拷贝
     * 拷贝长度是3，表示从第3个元素到第5个元素。
     */
    copy_arr(target, source + 2, TARGET_LEN);

    printf("The array of target is ");
    display_array(target, TARGET_LEN);

    return 0;
}

void copy_arr(int target[], const int source[], int num) {
    for (int i = 0; i < num; i++) {
        target[i] = source[i];
    }
}

void display_array(int arr[], int num) {
    printf("[");
    for (int i = 0; i < num; i++) {
        printf("%d", arr[i]);
        if (i != num - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}