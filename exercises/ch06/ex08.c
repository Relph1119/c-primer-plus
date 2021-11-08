//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"

int main(void){
    double n, m;
    double res;

    printf("Enter a pair of numbers:");

    while (scanf("%lf %lf", &n, &m) == 2) {
        res = (n - m) / (n * m);
        printf("(%.3g - %.3g) / (%.3g * %.3g) = %.5g\n", n, m, n, m, res);
        printf("Enter next pair (non-numeric to quit):");
    }

    return 0;
}