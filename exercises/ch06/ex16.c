//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void){
    const double rate_simp = 0.10;
    const double rate_comp = 0.05;
    const double init_amt = 100.0;

    double daphne = init_amt;
    double deidre = init_amt;
    int years = 0;

    while (deidre <= daphne) {
        daphne += rate_simp * init_amt;
        deidre += rate_comp * deidre;
        years++;
    }

    printf("Investment values after %d years:\n", years);
    printf("Daphne: $%.2f\n", daphne);
    printf("Deidre: $%.2f\n", deidre);

    return 0;
}