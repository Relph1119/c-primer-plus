//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    int age_years;
    double age_seconds;
    // 提示输入年龄
    printf("Enter your age:");
    scanf("%d", &age_years);
    // 计算该年龄对应的秒数
    age_seconds = 3.156e7 * age_years;
    printf("The age of %d years is %e seconds.\n", age_years, age_seconds);
    return 0;
}
