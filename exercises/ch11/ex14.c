//
// Created by HRF on 2021/11/11.
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(int argc, char *argv[]) {
    double num, exp;

    if (argc != 3) {
        printf("Usage: %s number exponent\n", argv[0]);
    } else {
        num = atof(argv[1]);
        exp = atof(argv[2]);
        printf("%g to the %g power = %g\n", num, exp, pow(num, exp));
    }

    return 0;
}
