//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>
int main(void){
    int count, sum;
    int n;

    printf("Enter the upper limit:");
    scanf("%d", &n);

    count = 0;
    sum = 0;
    while(count++ < n)
        sum += count * count;
    printf("sum = %d\n", sum);
    return 0;
}