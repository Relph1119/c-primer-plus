//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    float inch = 2.54;
    float height;
    // 提示用户输入身高（单位：英寸）
    printf("Enter the num of height (in):");
    scanf("%f", &height);
    // 计算并打印身高（单位：厘米）
    printf("%.2f(in) height is %.2f(cm).\n", height, height * inch);

    return 0;
}
