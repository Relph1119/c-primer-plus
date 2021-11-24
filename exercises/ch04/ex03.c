//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
int main(void){
    float val;
    // 读取一个浮点数
    printf("Enter a floating-point value:");
    scanf("%f", &val);
    // 以小数点记数法打印
    printf("The input is %.1f or %.1e.\n", val, val);
    // 以指数记数法打印
    printf("The input is %+.3f or %.3E.\n", val, val);
    return 0;
}
