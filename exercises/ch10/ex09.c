//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

#define ROWS 3
#define COLS 5
// 显示二维数组内容
void display_array2d(int n, int m, const double arr[n][m]);
// 拷贝二维数组
void copy_arr(int n, int m, double target[n][m], const double source[n][m]);

int main(void) {
    double source[ROWS][COLS] = {{1.1, 2.2, 3.3, 4.4, 5.5},
                                 {3.3, 4.4, 4.4, 5.5, 6.6},
                                 {5.5, 6.6, 7.7, 8.8, 9.9}};
    double target[ROWS][COLS];
    printf("The array of source is \n");
    // 显示二维数组source的内容
    display_array2d(ROWS, COLS, source);

    // 拷贝二维数组
    copy_arr(ROWS, COLS, target, source);
    printf("The array of target is \n");
    // 显示二维数组target的内容
    display_array2d(ROWS, COLS, target);

    return 0;
}

void copy_arr(int n, int m, double target[n][m], const double source[n][m]) {
    int i, j;
    // 使用二层for循环拷贝二维数组
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            target[i][j] = source[i][j];
        }
    }
}

void display_array2d(int n, int m, const double arr[n][m]) {
    printf("[");
    int i, j;
    for (i = 0; i < n; i++) {
        if (i > 0)
            printf(" [");
        else
            printf("[");
        for (j = 0; j < m; j++) {
            printf("%g", arr[i][j]);
            if (j != COLS - 1) {
                printf(" ");
            }
        }
        if (i != n - 1)
            printf("],\n");
        else
            printf("]");
    }
    printf("]\n");
}