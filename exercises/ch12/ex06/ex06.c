//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <rand.h>
#define SIZE 1000
void print_count(const int arr[]);
void init_array(int * arr);

int main(void) {
    int i, n, seed;
    int arr[11];

    printf("USE ANSI C rand function and srand function.");
    seed = 0;
    while(seed < 10) {
        srand(seed);
        init_array(arr);
        for (i = 0; i < SIZE; i++) {
            n = rand() % 10 + 1;
            arr[n]++;
        }
        putchar('\n');
        printf("Seed %d, the Number Counts:\n", seed);
        print_count(arr);
        seed++;
    }

    printf("\n\nUSE Self-Defining rand1 function and srand1 function.");
    seed = 0;
    while(seed < 10) {
        srand1(seed);
        init_array(arr);
        for (i = 0; i < SIZE; i++) {
            n = rand1() % 10 + 1;
            arr[n]++;
        }
        putchar('\n');
        printf("Seed %d, the Number Counts:\n", seed);
        print_count(arr);
        seed++;
    }
//
//    init_array(arr);
//    for (i = 0; i < SIZE; i++) {
//        n = rand1() % 10 + 1;
//        arr[n]++;
//    }
//    printf("\nUSE rand1, the Number Counts:\n");
//    print_count(arr);

    return 0;
}

void print_count(const int arr[]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%5d ", i + 1);
    }
    putchar('\n');
    for (i = 1; i <= 10; i++) {
        printf("%5d ", arr[i]);
    }
}

void init_array(int * arr) {
    int i;
    for (i = 0; i <= 10; i++) {
        arr[i] = 0;
    }
}