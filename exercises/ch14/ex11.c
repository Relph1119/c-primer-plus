//
// Created by HRF on 2021/11/18.
//
#include <stdio.h>
#include <math.h>
#define LEN 100
void transform(double source[], double target[], int n, double (*func) (double));
double twice(double x);
double half(double x);
void show_data(double arr[], int n, int span);
int main(void) {
    double source[LEN], target[LEN];

    for (int i = 0; i < LEN; i++) {
        source[i] = i;
    }
    printf("The source data is:\n");
    show_data(source, LEN, 3);
    printf("\n");

    transform(source, target, LEN, sin);
    printf("The target sin data is:\n");
    show_data(target, LEN, 10);
    printf("\n");

    transform(source, target, LEN, cos);
    printf("The target cos data is:\n");
    show_data(target, LEN, 10);
    printf("\n");

    transform(source, target, LEN, twice);
    printf("The target twice data is:\n");
    show_data(target, LEN, 3);
    printf("\n");

    transform(source, target, LEN, half);
    printf("The target half data is:\n");
    show_data(target, LEN, 4);
    printf("\n");
    return 0;
}

void show_data(double arr[], int n, int span) {
    for (int i = 0; i < n; i++) {
        if (i % 10 != 9) {
            printf("%*g ", span, arr[i]);
        } else {
            printf("%*g ", span, arr[i]);
            printf("\n");
        }
    }
    printf("\n");
}

void transform(double source[], double target[], int n, double (*func) (double)) {
    for (int i = 0; i < n; ++i) {
        target[i] = func(source[i]);
    }
}

double twice(double x) {
    return 2.0 * x;
}

double half(double x) {
    return x / 2.0;
}