//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"

int main(void){
    const double rate_year = 0.8;

    int years = 0;
    double chuckie = 100;

    while (chuckie > 0) {
        chuckie *= rate_year;
        chuckie -= 10;
        years++;
    }
    printf("Investment values after %d years are empty.\n", years);
}