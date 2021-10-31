//
// Created by HRF on 2021/10/31.
//
#include "stdio.h"
int main(void){
    float height;
    char name[40];
    printf("Enter your height in inches:");
    scanf_s("%f", &height);
    printf("Enter your name:");
    scanf_s("%s", name, 40);
    printf("%s, you are %.3f feet tall.\n", name, height/12.0);

    return 0;
}