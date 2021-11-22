//
// Created by HRF on 2021/11/1.
//
#include <stdio.h>
int main(void){
    int num;
    printf("Enter a number:");
    scanf("%d", &num);
    int limits = num + 10;
    while(num <= limits){
        printf("%d ", num);
        num++;
    }
    return 0;
}