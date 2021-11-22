//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
int main(void){
    float num;
    printf("Enter a num:");
    scanf("%f", &num);
    printf("The input is %.1f or %.1e.\n", num, num);
    printf("The input is %+.3f or %.3E.\n", num, num);
    return 0;
}
