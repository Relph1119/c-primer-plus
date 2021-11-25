//
// Created by HRF on 2021/11/1.
//
#include <stdio.h>

int main(void) {
    // 每周7天
    const int days_per_week = 7;
    int days, weeks, day_rem;

    // 提示用户输入天数
    printf("Enter the number of days:");
    scanf("%d", &days);
    while (days > 0) {
        // 计算周数
        weeks = days / days_per_week;
        // 计算转换后的天数
        day_rem = days % days_per_week;
        // 打印转换后的周数和天数
        printf("%d days are %d weeks, %d days.\n", days, weeks, day_rem);

        // 提示用户再次输入天数
        printf("Enter the number of days (0 or less to quit):");
        scanf("%d", &days);
    }
    printf("Bye!\n");

    return 0;
}