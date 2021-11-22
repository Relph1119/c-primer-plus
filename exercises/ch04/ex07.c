//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
#include <float.h>
int main(void){
    double ot_d = 1.0 / 3.0;
    float ot_f = 1.0 / 3.0;

    printf( " float values:");
    printf("%.6f %.12f %.16f\n", ot_f, ot_f, ot_f);
    printf( "double values:");
    printf("%.6f %.12f %.16f\n", ot_d, ot_d, ot_d);
    printf("FLT_DIG: %d\n", FLT_DIG);
    printf("DBL_DIG: %d\n", DBL_DIG);
    return 0;
}