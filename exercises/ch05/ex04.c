//
// Created by HRF on 2021/11/1.
//
#include <stdio.h>

int main(void) {
    // 2.54厘米每英寸
    const float cm_per_inches = 2.54;
    // 12英寸每英尺
    const int inches_per_feet = 12;

    float height, inches;
    int feet;

    // 提示用户输入身高
    printf("Enter a height in centimeters:");
    scanf("%f", &height);
    while (height > 0) {
        // 计算转换后的英寸
        inches = height / cm_per_inches;
        // 计算英尺
        feet = inches / inches_per_feet;
        // 计算英寸
        inches = inches - feet * inches_per_feet;
        // 打印信息
        printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);

        // 让用户再次输入身高
        printf("Enter a height in centimeters (<=0 to quit):");
        scanf("%f", &height);
    }
    printf("bye\n");

    return 0;
}
