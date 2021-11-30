//
// Created by HRF on 2021/11/8.
//
#include <stdio.h>

#define MONTHS 12    // number of months in a year
#define YEARS   5    // number of years of data
// 计算全年总降雨量
float calc_total(const float arr[][MONTHS], int years);
// 计算月平均值
void calc_monthly_average(const float arr[][MONTHS], int years);

int main(void) {
    // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
            {
                    {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
                    {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
                    {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
                    {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
                    {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
            };
    float total;
    total = calc_total(rain, YEARS);
    printf("\nThe yearly average is %.1f inches.\n\n",
           total / YEARS);

    calc_monthly_average(rain, YEARS);
    return 0;
}

void calc_monthly_average(const float arr[][MONTHS], int years) {
    int y, m;
    float subtot;

    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");
    for (m = 0; m < MONTHS; m++) {             // for each month, sum rainfall over years
        for (y = 0, subtot = 0; y < years; y++)
            subtot += arr[y][m];
        printf("%4.1f ", subtot / years);
    }
    printf("\n");
}

float calc_total(const float arr[][MONTHS], int years) {
    int y, m;
    float subtot, total;

    printf(" YEAR    RAINFALL  (inches)\n");
    for (y = 0, total = 0; y < years; y++) {             // for each year, sum rainfall for each month
        for (m = 0, subtot = 0; m < MONTHS; m++)
            subtot += arr[y][m];
        printf("%5d %15.1f\n", 2010 + y, subtot);
        total += subtot; // total for all years
    }
    return total;
}