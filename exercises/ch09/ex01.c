//
// Created by HRF on 2021/11/5.
//
#include "stdio.h"
double min(double x, double y);

int main(void) {
    double x, y;

    printf("Enter two numbers (q to quit):");
    while (scanf("%lf %lf", &x, &y) == 2) {
        printf("The smaller number is %g.\n", min(x, y));
        printf("Next two values (q to quit):");
    }
    printf("Bye!\n");
    return 0;
}

double min(double x, double y) {
    return x < y ? x : y;
}
