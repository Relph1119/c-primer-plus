//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void print_array(int arr[], int n);
void sort_array(int arr[], int n);

int main(void) {
    int i;
    int arr[SIZE];

    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10 + 1;
    }
    puts("The array is");
    print_array(arr, SIZE);
    sort_array(arr, SIZE);
    puts("After sort, The array is");
    print_array(arr, SIZE);
    return 0;
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%2d ", arr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }
    if (i % 10 != 0)
        putchar('\n');
}

void sort_array(int arr[], int n) {
    int top, seek, temp;

    for (top = 0; top < n - 1; top++)
        for (seek = top + 1; seek < n; seek++)
            if (arr[seek] > arr[top]) {
                temp = arr[seek];
                arr[seek] = arr[top];
                arr[top] = temp;
            }
}
