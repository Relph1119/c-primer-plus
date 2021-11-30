//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

void handle(double *p1, double *p2, double *p3);
void swap(double *x, double *y);

int main(void) {
    double x, y, z;

    // 提示用户输入3个double类型的数
    printf("Enter three numbers:");
    while (scanf("%lf %lf %lf", &x, &y, &z) == 3) {
        // 进行比较交换
        handle(&x, &y, &z);
        // 打印结果
        printf("The values are %g, %g and %g.\n", x, y, z);
        printf("Next three values (q to quit):");
    }

    printf("Bye\n");
    return 0;
}

// 处理三个变量的函数
void handle(double *p1, double *p2, double *p3) {
    if (*p1 > *p2) {
        swap(p1, p2);
    }
    if (*p1 > *p3) {
        swap(p1, p3);
    }
    if (*p2 > *p3) {
        swap(p2, p3);
    }
}

// 交换位置的函数
void swap(double *x, double *y) {
    double t;

    t = *x;
    *x = *y;
    *y = t;
}