//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>
#define SIZE 8

int main(void){
    double arr[SIZE];
    double arr_total[SIZE];
    int i;

    printf("Enter %d numbers :", SIZE);
    for(i=0; i < SIZE; i++){
        scanf("%lf", &arr[i]);
    }

    arr_total[0] = arr[0];
    for(i = 1; i< SIZE; i++){
        arr_total[i] = arr_total[i - 1] + arr[i];
    }

    printf("The total array:\n");
    for (i = 0; i < SIZE; i++){
        printf("%g ", arr_total[i]);
    }

    return 0;
}