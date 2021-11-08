//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"

int main(void){
    int n;
    double even_sum = 0;
    int even_count = 0;
    double odd_sum = 0;
    int odd_count = 0;

    while (scanf("%d", &n) == 1 && n != 0){
        if (n % 2 == 0){
            even_sum += n;
            even_count++;
        } else {
            odd_sum += n;
            odd_count++;
        }
    }
    printf("Number of evens: %d,", even_count);
    if (even_count > 0)
        printf(" average: %g\n", even_sum / even_count);

    printf("Number of odds: %d,", odd_count);
    if (odd_count > 0)
        printf(" average: %g\n", odd_sum / odd_count);
    printf("Done\n");

    return 0;
}
