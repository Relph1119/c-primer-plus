//
// Created by HRF on 2021/11/1.
//
#include <stdio.h>
// 每小时60分钟
#define MIN_PER_HOUR 60
int main(void){
    int minutes, hours, mins;

    // 提示用户输入分钟数
    printf("Enter the number of minutes to convert:");
    scanf("%d", &minutes);
    while (minutes > 0){
        // 计算转换后的小时数
        hours = minutes / MIN_PER_HOUR;
        // 计算转换后的分钟数
        mins = minutes % MIN_PER_HOUR;
        // 打印转换后的用小时和分钟表示的时间
        printf("%d minutes = %d hours, %d minutes\n", minutes, hours, mins);
        // 提示用户再次输入
        printf("Enter next minutes value(0 to quit):");
        scanf("%d", &minutes);
    }
    printf("Bye!\n");

    return 0;
}