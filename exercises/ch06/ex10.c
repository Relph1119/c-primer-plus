//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"

int main(void){
    int lower, upper, index;
    int sum;

    printf("Enter lower and upper integer limits:");
    scanf_s("%d %d", &lower, &upper);


    do{
        sum = 0;
        for(index = lower; index <= upper; index++){
            sum += index * index;
        }
        printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        printf("Enter next set of limits:");
        scanf_s("%d %d", &lower, &upper);
    } while(lower != upper);

    printf("Done");
    return 0;
}