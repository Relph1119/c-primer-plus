//
// Created by HRF on 2021/11/8.
//
#include "stdio.h"
#define LEN 4
void display_array(int arr[], int num);
void add_arr(const int arr1[], const int arr2[], int result[], int n);

int main(void) {
    int arr1[LEN] = {2, 4, 5, 8};
    int arr2[LEN] = {1, 0, 4, 6};
    int result[LEN];

    printf("The array of arr1 is ");
    display_array(arr1, LEN);
    printf("The array of arr2 is ");
    display_array(arr2, LEN);

    add_arr(arr1, arr2, result, LEN);

    printf("The array of result is ");
    display_array(result, LEN);

    return 0;
}

void add_arr(const int arr1[], const int arr2[], int result[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        result[i] = arr1[i] + arr2[i];
    }
}

void display_array(int arr[], int num) {
    printf("[");
    for (int i = 0; i < num; i++){
        printf("%d", arr[i]);
        if(i != num - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}
