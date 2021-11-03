//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"

int main(void){
    int lower, upper, index;
    int square, cube;

    printf("Enter starting integer:");
    scanf_s("%d", &lower);
    printf("Enter ending integer:");
    scanf_s("%d", &upper);

    printf("%5s %10s %15s\n", "num", "square", "cube");
    for (index = lower; index <= upper; index++){
        square = index * index;
        cube = index * square;
        printf("%5d %10d %15d\n", index, square, cube);
    }

    return 0;
}