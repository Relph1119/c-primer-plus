//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#define HMEAN(X, Y) (1 / ((1 / (X) + 1 / (Y)) / 2))


int main(void) {
    double f1, f2, ans;
    printf("Enter a pair of numbers (q to quit):");
    while (scanf("%lf %lf", &f1, &f2) == 2) {
        ans = HMEAN(f1, f2);
        printf("The harmonic mean of %g %g is %g\n", f1, f2, ans);
        printf("Enter next pair of numbers (q to quit):");
    }

    printf("Bye.\n");
    return 0;
}