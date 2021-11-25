//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

void Temperatures(double fahrenheit);

int main(void) {
    double input;

    // 提示用户输入一个华氏温度
    printf("Enter a number of fahrenheit temperature:");
    // 判断用户输入的数字是否为q或非数字
    while (scanf("%lf", &input) == 1) {
        // 打印温度转换结果
        Temperatures(input);
        // 提示用户再次输入
        printf("Enter next fahrenheit temperature value (q or non-numeric to quit):");
    }
    printf("Done\n");
    return 0;
}

void Temperatures(double fahrenheit) {
    // 摄氏温度转换开氏温度的变量
    const double celsius_to_kelvin = 273.16;
    // 华氏温度转换摄氏温度的变量
    const double fahrenheit_to_celsius = 32.0;

    double celsius, kelvin;
    // 计算华氏温度转换成摄氏温度
    celsius = 5.0 / 9.0 * (fahrenheit - fahrenheit_to_celsius);
    // 计算开氏温度转换成摄氏温度
    kelvin = celsius + celsius_to_kelvin;

    // 打印3个温度值
    printf("%.2f. fahrenheit = %.2f celsius, and %.2f kelvin\n", fahrenheit, celsius, kelvin);
}
