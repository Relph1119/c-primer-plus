//
// Created by HRF on 2021/11/8.
//
#include "stdio.h"
#define ROWS 3
#define COLS 5
void display_array2d(double arr[][COLS], int rows);
void copy_arr(double target[][COLS], const double source[][COLS], int rows);

int main(void) {
    double source[ROWS][COLS] = {{1.1, 2.2, 3.3, 4.4, 5.5},
                                 {3.3, 4.4, 4.4, 5.5, 6.6},
                                 {5.5, 6.6, 7.7, 8.8, 9.9}};
    double target[ROWS][COLS];
    printf("The array of source is \n");
    display_array2d(source, ROWS);

    copy_arr(target, source, ROWS);
    printf("The array of target is \n");
    display_array2d(target, ROWS);

    return 0;
}

void copy_arr(double target[][COLS], const double source[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for(j = 0; j < COLS; j++) {
            target[i][j] = source[i][j];
        }
    }
}

void display_array2d(double arr[][COLS], int rows) {
    printf("[");
    int i, j;
    for (i = 0; i < rows; i++){
        if(i > 0)
            printf(" [");
        else
            printf("[");
        for (j = 0; j < COLS; j++) {
            printf("%g", arr[i][j]);
            if(j != COLS - 1) {
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