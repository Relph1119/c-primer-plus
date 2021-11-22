//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    float mass_mol = 3.0e-23;
    float mass_qt = 950;
    float quarts, molecules;

    printf("Enter the number of quarts of water:");
    scanf("%f", &quarts);
    molecules = quarts * mass_qt / mass_mol;
    printf("%g quarts of water contain %e molecules.\n", quarts, molecules);
    return 0;
}