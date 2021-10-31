//
// Created by HRF on 2021/10/31.
//
#include "stdio.h"
#define LITER_PER_GALLONS 3.785
#define KILOMETERS_PER_MILE 1.609

int main(void){
    float mileage, gas;

    printf("Enter a mileage:");
    scanf_s("%f", &mileage);
    printf("Enter an amount of gasoline:");
    scanf_s("%f", &gas);
    printf("Miles per gallon(US): %.1f\n",  mileage / gas);
    printf("Miles per gallon(EUR): %.1f\n", (gas * LITER_PER_GALLONS) / (mileage * KILOMETERS_PER_MILE / 100));

    return 0;
}