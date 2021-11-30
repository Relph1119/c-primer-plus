//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>
#define LEN 10
// 倒序排列数组
void reverse(double arr[], int n);
// 显示数组
void display_arr(const double arr[], int n);

int main(void) {
    double arr[] = {1.1, 2, 3, 4, 5.5, 6, 7, 8 ,9 ,10.1};
    printf("The array is ");
    display_arr(arr, LEN);

    // 对arr进行倒序排列
    reverse(arr, LEN);
    printf("The reverse array is ");
    display_arr(arr, LEN);

    return 0;
}

void reverse(double arr[], int n) {
    double temp;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            // 进行比较并交换位置
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void display_arr(const double arr[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%g", arr[i]);
        if (i != n - 1){
            printf(" ");
        }
    }
    printf("]\n");
}


