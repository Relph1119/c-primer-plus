//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

void print_cube(double x);

int main(void) {
    double num;

    // 提示用户输入一个double类型的数
    printf("Enter a double value:");
    scanf("%lf", &num);
    // 调用函数，打印该数的立方值
    print_cube(num);

    return 0;
}

void print_cube(double x) {
    // 计算并打印x的立方值
    printf("The cube of %g is %g.\n", x, x * x * x);
}