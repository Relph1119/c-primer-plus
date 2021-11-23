//
// Created by HRF on 2021/10/26.
//
#include <stdio.h>
int main(void){
    int age_years, age_days;
    // 设置年龄
    age_years = 32;
    // 计算天数
    age_days = 365 * age_years;
    // 打印并显示年龄和天数
    printf("The age of %d years is %d days.\n", age_years, age_days);
    return 0;
}
