//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    float mass_mol = 3.0e-23;
    float mass_qt = 950;
    float quarts, molecules;

    // 提示用户输入水的夸脱数
    printf("Enter the number of quarts of water:");
    scanf("%f", &quarts);
    // 计算水分子的数量
    molecules = quarts * mass_qt / mass_mol;
    printf("%g quarts of water contain %e molecules.\n", quarts, molecules);
    return 0;
}