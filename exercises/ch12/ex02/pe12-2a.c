//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include "pe12-2a.h"

// 模式，文件作用域，内部链接
static int mode;
// 距离，文件作用域，内部链接
static double pd;
// 消耗的燃料，文件作用域，内部链接
static double pf;

void set_mode(int pm) {
    // 根据输入的模式，设置mode
    mode = pm;
    // 如果不是美制或公制，则使用美制
    if (pm != METRIC && pm != US) {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        mode = US;
    }
}

void get_info(void) {
    // 根据不同的模式，显示不同的提示
    if (mode == METRIC)
        printf("Enter distance traveled in kilometers:");
    else
        printf("Enter distance traveled in miles:");
    scanf("%lf", &pd);

    if (mode == METRIC)
        printf("Enter fuel consumed in liters:");
    else
        printf("Enter fuel consumed in gallons:");
    scanf("%lf", &pf);
}

void show_info(void) {
    // 根据不同的模式，显示并计算油耗
    printf("Fuel consumption is ");
    if (mode == METRIC)
        printf("%.2f liters per 100 km.\n", 100 * pf / pd);
    else
        printf("%.1f miles per gallon.\n", pd / pf);
}