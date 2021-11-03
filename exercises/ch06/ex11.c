//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
#define SIZE 8

int main(void){
    int vals[SIZE];
    int i;

    printf("Please enter %d integers.\n", SIZE);
    for (i=0; i < SIZE; i++){
        scanf_s("%d", &vals[i]);
    }

    printf("Here, in reverse order, are the values you entered:\n");
    for (i = SIZE - 1; i >= 0; i--){
        printf("%d ", vals[i]);
    }
    printf("\n");

    return 0;
}