//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

#define ROWS 4
#define COLS 2
// 显示二维数组
void display_array2d(double arr[][COLS], int rows);
// 拷贝数组
void copy_arr(double target[], const double source[], int num);

int main(void) {
    // 初始化源二维数组
    double source[ROWS][COLS] = {{1.1, 2.2},
                                 {3.3, 4.4},
                                 {5.5, 6.6},
                                 {7.7, 8.8}};
    double target[ROWS][COLS];
    printf("The array of source is \n");
    display_array2d(source, ROWS);

    // 对子数组使用for循环进行拷贝
    int i;
    for (i = 0; i < ROWS; i++) {
        copy_arr(target[i], source[i], COLS);
    }

    printf("The array of target is \n");
    display_array2d(target, ROWS);

    return 0;
}

void copy_arr(double target[], const double source[], int num) {
    for (int i = 0; i < num; i++) {
        target[i] = source[i];
    }
}

void display_array2d(double arr[][COLS], int rows) {
    printf("[");
    int i, j;
    for (i = 0; i < rows; i++) {
        if (i > 0)
            printf(" [");
        else
            printf("[");
        for (j = 0; j < COLS; j++) {
            printf("%g", arr[i][j]);
            if (j != COLS - 1) {
                printf(" ");
            }
        }
        if (i != rows - 1)
            printf("],\n");
        else
            printf("]");
    }
    printf("]\n");
}