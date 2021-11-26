//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    // 单利息
    const double RATE_SIMP = 0.10;
    // 复合利息
    const double RATE_COMP = 0.05;
    const double init_amt = 100.0;

    // 两个人都投资了100美元
    double daphne = init_amt;
    double deirdre = init_amt;

    int years = 0;

    // 判断Deirdre的投资额是否超过了Daphne
    while (deirdre <= daphne) {
        // 计算单利息方案的投资
        daphne += RATE_SIMP * init_amt;
        // 计算复合利息的投资
        deirdre += RATE_COMP * deirdre;
        years++;
    }

    // 显示两人的投资额
    printf("Investment values after %d years:\n", years);
    printf("Daphne: $%.2f\n", daphne);
    printf("Deirdre: $%.2f\n", deirdre);

    return 0;
}