//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
void print_cube(double x);

int main(void){
    double num;

    printf("Enter a floating-point value:");
    scanf("%lf", &num);
    print_cube(num);

    return 0;
}

void print_cube(double x){
    printf("The cube of %e is %e.\n", x, x * x * x);
}