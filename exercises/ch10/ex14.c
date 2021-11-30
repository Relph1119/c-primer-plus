//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

#define ROWS 3
#define COLS 5
// 任务a：把用户输入的数据存储到数组中
void input_array_numbers(double arr[], int nums);
// 任务e：显示数组内容
void display_array2d(int rows, int cols, double arr[rows][cols]);
// 任务b：计算一维数组的平均值
double calc_average_array1d(const double arr[], int nums);
// 任务c：计算所有数据的平均值
double calc_average_all(int rows, int cols, double arr[rows][cols]);
// 任务d：找出数组中的最大值
double max_all(int rows, int cols, double arr[rows][cols]);

int main(void) {
    double arr[ROWS][COLS];

    int row;
    // 提示用户输入数据
    for (row = 0; row < ROWS; row++) {
        printf("Enter %d numbers for %d:\n", COLS, row + 1);
        input_array_numbers(arr[row], COLS);
    }
    printf("\nThe array is\n");
    // 显示数组内容
    display_array2d(ROWS, COLS, arr);

    // 计算每组的平均值
    printf("\nGroup    AVERAGE\n");
    for (row = 0; row < ROWS; row++) {
        printf("%3d %10.1f\n", row + 1, calc_average_array1d(arr[row], COLS));
    }

    // 计算所有数据的平均值
    double avg_all = calc_average_all(ROWS, COLS, arr);
    printf("\nThe average of numbers is %.2f.\n", avg_all);

    // 找出数组中的最大值
    double max = max_all(ROWS, COLS, arr);
    printf("The largest value is %g.\n", max);

    printf("Bye!\n");
    return 0;
}

double max_all(int rows, int cols, double arr[rows][cols]) {
    int i, j;
    double max = arr[0][0];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            // 比较并把较大值赋给max
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}

double calc_average_all(int rows, int cols, double arr[rows][cols]) {
    int i, j;
    double total;
    for (i = 0, total = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            total += arr[i][j];
        }
    }
    if (rows * cols > 0)
        // 计算平均值
        return total / (rows * cols);
    else
        return 0.0;
}

double calc_average_array1d(const double arr[], int nums) {
    int i;
    double total;
    for (i = 0, total = 0; i < nums; i++) {
        total += arr[i];
    }
    // 计算一维数组的平均值
    return total / nums;
}

void display_array2d(int rows, int cols, double arr[rows][cols]) {
    printf("[");
    int i, j;
    for (i = 0; i < rows; i++) {
        if (i > 0)
            printf(" [");
        else
            printf("[");
        for (j = 0; j < cols; j++) {
            printf("%g", arr[i][j]);
            if (j != cols - 1) {
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
    // 给一维数组赋值
    for (i = 0; i < nums; i++) {
        scanf("%lf", &arr[i]);
    }
}
