//
// Created by HRF on 2021/11/8.
//
#include "stdio.h"
#define ROWS 3
#define COLS 5

void display_array2d(int arr[][COLS], int rows);
void times_array2d(int arr[][COLS], int rows);

int main(void) {
    int source[ROWS][COLS] = {{1, 2, 3, 4, 5},
                              {2, 3, 4, 5, 6},
                              {3, 4, 5, 6, 7}};
    printf("The array of source is \n");
    display_array2d(source, ROWS);

    times_array2d(source, ROWS);
    printf("After times two, The array of source is \n");
    display_array2d(source, ROWS);

    return 0;
}

void times_array2d(int arr[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < COLS; j++)
            arr[i][j] *= 2;
}

void display_array2d(int arr[][COLS], int rows) {
    printf("[");
    int i, j;
    for (i = 0; i < rows; i++){
        if(i > 0)
            printf(" [");
        else
            printf("[");
        for (j = 0; j < COLS; j++) {
            printf("%d", arr[i][j]);
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
