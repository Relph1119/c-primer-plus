//
// Created by HRF on 2021/11/5.
//
#include "stdio.h"
double harmean(double x, double y);

int main(void) {
    double x, y;

    printf("Enter two double-type number (q to quit):");
    while(scanf_s("%lf %lf", &x, &y) == 2) {
        if (x == 0 || y == 0) {
            printf("Enter two double-type number (other than 0):");
            continue;
        }
        printf("The harmean of (%g, %g) is %g\n", x, y, harmean(x, y));
        printf("Enter next double-type number (q to quit):");
    }

    return 0;
}

double harmean(double x, double y) {
    return 1 / ((1.0 / 2.0) * (1 / x + 1 / y));
}
