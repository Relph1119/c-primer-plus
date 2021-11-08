//
// Created by HRF on 2021/11/8.
//
#include "stdio.h"
#define ROWS 3
#define COLS 5
void input_array_numbers(double arr[], int nums);
void display_array2d(const double arr[][COLS], int rows);
double calc_average_array1d(const double arr[], int nums);
double calc_average_all(const double arr[][COLS], int rows);
double max_all(const double arr[][COLS], int rows);

int main(void) {
    double arr[ROWS][COLS];

    int row;
    for (row = 0; row < ROWS; row++) {
        printf("Enter %d numbers for %d:\n", COLS, row + 1);
        input_array_numbers(arr[row], COLS);
    }
    printf("\nThe array is\n");
    display_array2d(arr, ROWS);

    printf("\nGroup    AVERAGE\n");
    for (row = 0; row < ROWS; row++) {
        printf("%3d %10.1f\n", row+1, calc_average_array1d(arr[row], COLS));
    }

    double avg_all = calc_average_all(arr, ROWS);
    printf("\nThe average of numbers is %.2f.\n", avg_all);

    double max = max_all(arr, ROWS);
    printf("The largest value is %g.\n", max);

    printf("Bye!\n");
    return 0;
}

double max_all(const double arr[][COLS], int rows) {
    int i, j;
    double max = arr[0][0];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}

double calc_average_all(const double arr[][COLS], int rows) {
    int i, j;
    double total;
    for (i = 0, total = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            total += arr[i][j];
        }
    }
    if (rows * COLS > 0)
        return total / (rows * COLS);
    else
        return 0.0;
}

double calc_average_array1d(const double arr[], int nums) {
    int i;
    double total;
    for (i = 0, total = 0; i < nums; i++) {
        total += arr[i];
    }
    return total / nums;
}

void display_array2d(const double arr[][COLS], int rows) {
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

void input_array_numbers(double arr[], int nums) {
    int i;
    for (i = 0; i < nums; i++) {
        scanf("%lf", &arr[i]);
    }
}