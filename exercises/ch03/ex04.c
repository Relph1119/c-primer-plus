//
// Created by HRF on 2021/10/27.
//
#include "stdio.h"
int main(void){
    float num;
    printf("Enter a floating-point value:");
    scanf_s("%f", &num);
    printf("fixed-point notation: %f\n", num);
    printf("exponential notation:%e\n", num);
    printf("p notation:%a\n", num);
    return 0;
}

