//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    float pint = 2;
    float cup = 8;
    float oz = 2;
    float tablespoon = 3;

    float num_cup;
    printf("Enter the num of Cup:");
    scanf("%f", &num_cup);
    printf("%g(cup) of pint is %g.\n", num_cup, num_cup / pint);
    printf("%g(cup) of oz is %g.\n", num_cup, num_cup * cup);
    printf("%g(cup) of tablespoon is %g.\n", num_cup, num_cup * cup * oz);
    printf("%g(cup) of teaspoon is %g.\n", num_cup, num_cup * cup * oz * tablespoon);

    return 0;
}
