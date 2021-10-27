//
// Created by HRF on 2021/10/27.
//
#include "stdio.h"
int main(void){
    float inch = 2.54;
    float height;
    printf("Enter the num of height:");
    scanf_s("%f", &height);
    printf("%f(in) height is %f(cm).\n", height, height * inch);

    return 0;
}
