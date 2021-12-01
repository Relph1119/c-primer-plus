//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
// 显示数组内容
void print_array(int arr[], int n);
// 对数组的数据进行排序
void sort_array(int arr[], int n);

int main(void) {
    int i;
    int arr[SIZE];

    // 生成随机数，并存储到数组中
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10 + 1;
    }
    puts("The array:");
    // 显示原数组
    print_array(arr, SIZE);
    // 对数组降序排列
    sort_array(arr, SIZE);
    puts("\nAfter sort, The array:");
    // 显示降序排列之后的数组
    print_array(arr, SIZE);
    return 0;
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%3d ", arr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }
    if (i % 10 != 0)
        putchar('\n');
}

void sort_array(int arr[], int n) {
    int top, seek, temp;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
            // 当后一个数大于前一个数，进行交换位置，降序排列
            if (arr[seek] > arr[top]) {
                temp = arr[seek];
                arr[seek] = arr[top];
                arr[top] = temp;
            }
}
