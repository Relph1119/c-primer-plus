//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
#include <float.h>

int main(void) {
    // 设置double类型的变量
    double ot_d = 1.0 / 3.0;
    // 设置float类型的变量
    float ot_f = 1.0 / 3.0;

    // 按格式打印float类型的值
    printf(" float values: ");
    printf("%.6f %.12f %.16f\n", ot_f, ot_f, ot_f);
    // 按格式打印double类型的值
    printf("double values: ");
    printf("%.6f %.12f %.16f\n", ot_d, ot_d, ot_d);
    // 打印FLT_DIG的值
    printf("FLT_DIG: %d\n", FLT_DIG);
    // 打印DBL_DIG的值
    printf("DBL_DIG: %d\n", DBL_DIG);
    return 0;
}