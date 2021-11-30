//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

#define ROWS 3
#define COLS 5

// 显示二维数组内容
void display_array2d(int arr[][COLS], int rows);
// 将二维数组元素的值翻倍
void times_array2d(int arr[][COLS], int rows);

int main(void) {
    int source[ROWS][COLS] = {{1, 2, 3, 4, 5},
                              {2, 3, 4, 5, 6},
                              {3, 4, 5, 6, 7}};
    printf("The array of source is \n");
    // 显示数组内容
    display_array2d(source, ROWS);

    // 将source数组中的元素值翻倍
    times_array2d(source, ROWS);
    printf("After times two, The array of source is \n");
    display_array2d(source, ROWS);

    return 0;
}

void times_array2d(int arr[][COLS], int rows) {
    int i, j;
    // 用二层for循环，将元素值翻倍
    for (i = 0; i < rows; i++)
        for (j = 0; j < COLS; j++)
            arr[i][j] *= 2;
}

void display_array2d(int arr[][COLS], int rows) {
    printf("[");
    int i, j;
    for (i = 0; i < rows; i++) {
        if (i > 0)
            printf(" [");
        else
            printf("[");
        for (j = 0; j < COLS; j++) {
            printf("%d", arr[i][j]);
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
