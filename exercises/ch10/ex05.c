//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>
double diff_arr(const double arr[], int n);
void display_arr(const double arr[], int n);

int main(void) {
    double arr[] = {1.1, 2, 3, 4, 12, 61.3, 7, 8, 9, 10};
    int length = sizeof (arr) / sizeof arr[0];

    double diff_value;
    printf("The array is ");
    display_arr(arr, length);
    diff_value = diff_arr(arr, length);
    printf("the maximum difference is %g\n", diff_value);

    return 0;
}

double diff_arr(const double arr[], int n) {
    int i;
    double max = arr[0];
    double min = arr[0];

    for (i = 0; i < n; i++) {
        if(max < arr[i])
            max = arr[i];
        else if (min > arr[i])
            min = arr[i];
    }
    return max - min;
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