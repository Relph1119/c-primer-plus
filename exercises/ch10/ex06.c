//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>
#define LEN 10
void reverse(double target[], const double arr[], int n);
void display_arr(const double arr[], int n);

int main(void) {
    double arr[] = {1.1, 2, 3, 4, 5.5, 6, 7, 8 ,9 ,10.1};
    double target[LEN];
    printf("The array is ");
    display_arr(arr, LEN);

    reverse(target, arr, LEN);
    printf("The reverse array is ");
    display_arr(target, LEN);

    return 0;
}

void reverse(double target[], const double arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        target[i] = arr[n - 1 - i];
    }
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


