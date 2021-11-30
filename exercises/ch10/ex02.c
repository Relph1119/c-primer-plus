//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

// 带数组表示法的函数
void copy_arr(double target[], const double source[], int num);
// 带指针表示法和指针递归的函数
void copy_ptr(double *target, double *source, int num);
// 带源数组名和指向源数组最后一个元素后面的元素指针的函数
void copy_ptrs(double *target, double *start, const double *end);
// 显示数组
void display_array(double arr[], int num);

int main(void) {
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    printf("The array of source is ");
    display_array(source, 5);

    copy_arr(target1, source, 5);
    printf("The array of target1 is ");
    display_array(target1, 5);

    copy_ptr(target2, source, 5);
    printf("The array of target2 is ");
    display_array(target2, 5);

    copy_ptrs(target3, source, source + 5);
    printf("The array of target3 is ");
    display_array(target3, 5);

    return 0;
}

void copy_arr(double target[], const double source[], int num) {
    for (int i = 0; i < num; i++) {
        target[i] = source[i];
    }
}

void copy_ptr(double *target, double *source, int num) {
    int i = 0;
    // 进行指针递增
    while (i < num) {
        *target = *source;
        target++;
        source++;
        i++;
    }
}

void copy_ptrs(double *target, double *start, const double *end) {
    // 循环判断头指针和尾指针
    while (start < end) {
        *target = *start;
        start++;
        target++;
    }
}

void display_array(double arr[], int num) {
    printf("[");
    for (int i = 0; i < num; i++) {
        printf("%g", arr[i]);
        if (i != num - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}