//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);

double *new_d_array(int n, ...);

int main() {
    double *p1;
    double *p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}

void show_array(const double ar[], int n) {
    // 显示数组内容
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", ar[i]);
    }
    putchar('\n');
}

double *new_d_array(int n, ...) {
    // 声明一个存储参数的对象
    va_list ap;
    // 把ap初始化为参数列表
    va_start(ap, n);
    // 动态创建存储空间
    double *ar = (double *) malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        // 访问参数列表的内容
        ar[i] = va_arg(ap, double);
    }
    // 完成清理工作
    va_end(ap);
    return ar;
}