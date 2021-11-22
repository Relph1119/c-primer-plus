//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>
unsigned long fibonacci(unsigned n);

int main(void) {
    unsigned n;

    printf("Enter a number:");
    while (scanf("%u", &n) == 1) {
        printf("The Fibonacci(%d) value is %lu.\n", n, fibonacci(n));
        printf("Enter next number (q to quit):");
    }

    return 0;
}

unsigned long fibonacci(unsigned n) {
    int m;
    if (n == 1 || n == 2){
        m = 1;
    } else {
        int prev = 1;
        int prev_prev = 1;
        int sum;
        int i;
        for (i = 3; i < n; i++) {
            sum = prev + prev_prev;
            prev_prev = prev;
            prev = sum;
        }
        m = prev + prev_prev;
    }
    return m;
}
