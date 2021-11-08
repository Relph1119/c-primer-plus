//
// Created by HRF on 2021/11/8.
//
#include "stdio.h"
int max_index_arr(const double arr[], int n);
void display_arr(const double arr[], int n);

int main(void) {
    double arr[] = {1.1, 2.2, 3.3, 4.4, 12.12, 6.6, 7.7, 8.8, 9.9, 10.1};
    int length = sizeof(arr) / sizeof arr[0];
    int max_index;

    printf("The array is ");
    display_arr(arr, length);
    max_index = max_index_arr(arr, length);
    printf("The index of the largest value is %d\n", max_index);

    return 0;
}

int max_index_arr(const double arr[], int n) {
    int i;
    double max = arr[0];
    int index;
    for(i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void display_arr(const double arr[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%g", arr[i]);
        if (i != n - 1){
            printf(" ");
        }
    }
    printf("]\n");
}