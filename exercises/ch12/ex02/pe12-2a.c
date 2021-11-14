//
// Created by HRF on 2021/11/14.
//
#include "stdio.h"
#include "pe12-2a.h"

static int mode;
static double pd;
static double pf;

void set_mode(int pm) {
    extern int mode;

    if (pm != METRIC && pm != US) {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        mode = US;
    }
}

void get_info(void) {
    if (mode == METRIC)
        printf("Enter distance traveled in kilometers:");
    else
        printf("Enter distance traveled in miles:");
    scanf("%lf",&pd);

    if (mode == METRIC)
        printf("Enter fuel consumed in liters:");
    else
        printf("Enter fuel consumed in gallons:");
    scanf("%lf", &pf);
}

void show_info(void) {
    printf("Fuel consumption is ");
    if (mode == METRIC)
        printf("%.2f liters per 100 km.\n", 100 * pf / pd);
    else
        printf("%.1f miles per gallon.\n", pd / pf);
}