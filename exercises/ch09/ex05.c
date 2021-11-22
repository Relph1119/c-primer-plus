//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>
void larger_of(double *p1, double *p2);

int main(void) {
    double x, y;

    printf("Enter tow number (q to quit):");
    while (scanf("%lf %lf", &x, &y) == 2) {
        larger_of(&x, &y);
        printf("The modified values are %g and %g.\n", x, y);
        printf("Next two value (q to quit):");
    }

    printf("Bye!");
    return 0;
}

void larger_of(double *p1, double *p2) {
    *p1 = *p2 = *p1 > *p2? *p1 : *p2;
}
