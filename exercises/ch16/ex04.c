//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <time.h>

void delay(double second);

int main(void) {
    double sec;

    printf("Enter a second to delay:");
    while (scanf("%lf", &sec) == 1) {
        delay(sec);
        printf("Enter next second to delay (q to quit):");
    }

    return 0;
}

void delay(double second) {
    clock_t start = clock();
    printf("Test %lf second delay\n", second);
    clock_t now = clock();

    while (((double) (now - start)) / CLOCKS_PER_SEC < second) {
        now = clock();
        printf("The delay time is %lf second.\n", ((double) (now - start)) / CLOCKS_PER_SEC);
    }
}