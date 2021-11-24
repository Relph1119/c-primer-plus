//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    float num;
    // 输入一个浮点数
    printf("Enter a floating-point value:");
    scanf("%f", &num);
    // 打印小数点形式
    printf("fixed-point notation: %f\n", num);
    // 打印指数形式
    printf("exponential notation:%e\n", num);
    // 打印p记数法形式
    printf("p notation:%a\n", num);
    return 0;
}

