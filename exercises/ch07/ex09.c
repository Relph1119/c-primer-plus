//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"
#include "stdbool.h"

int main(void) {
    int limit;
    int num;
    int div;
    bool num_is_prime;

    printf("Enter a positive integer:");
    while (scanf("%d", &limit) == 1 && limit > 0) {
        if (limit > 1)
            printf("Here are the prime numbers up through %d\n", limit);
        else
            printf("No primes.\n");

        for (num = 2; num <= limit; num++) {
            for (div = 2, num_is_prime = true; (div * div) <= num; div++) {
                if (num % div == 0)
                    num_is_prime = false;
            }
            if (num_is_prime)
                printf("%d is prime.\n", num);
        }
        printf("Enter next positive integer (q to quit):");
    }
    printf("Done!\n");

    return 0;
}

