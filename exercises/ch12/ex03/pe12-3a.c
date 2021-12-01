//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include "pe12-3a.h"

void set_mode(int *mode) {
    // 如果不是美制或公制，则使用美制
    if (*mode != METRIC && *mode != US) {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        *mode = US;
    }
}

void get_info(int mode, double *pd, double *pf) {
    // 根据不同的模式，显示不同的提示
    if (mode == METRIC)
        printf("Enter distance traveled in kilometers:");
    else
        printf("Enter distance traveled in miles:");
    scanf("%lf", pd);

    if (mode == METRIC)
        printf("Enter fuel consumed in liters:");
    else
        printf("Enter fuel consumed in gallons:");
    scanf("%lf", pf);
}

void show_info(int mode, double pd, double pf) {
    // 根据不同的模式，显示并计算油耗
    printf("Fuel consumption is ");
    if (mode == METRIC)
        printf("%.2f liters per 100 km.\n", 100 * pf / pd);
    else
        printf("%.1f miles per gallon.\n", pd / pf);
}