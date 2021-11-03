//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
void temperatures(double temp);

int main(void){
    double fahrenheit_temp;
    int status;
    printf("Enter a number of fahrenheit temperature:");

    status = scanf_s("%lf", &fahrenheit_temp);
    while (status == 1){
        temperatures(fahrenheit_temp);
        printf("Enter next fahrenheit temperature value (q or non-number to quit):");
        status = scanf_s("%lf", &fahrenheit_temp);
    }
    printf("Done\n");
    return 0;
}

void temperatures(double temp){
    const float celsius_to_kelvin = 273.16;
    const float fahrenheit_to_celsius = 32.0;

    float celsius_temp, kelvin_temp;
    celsius_temp = 5.0 / 9.0 * (temp - fahrenheit_to_celsius);
    kelvin_temp = celsius_temp + celsius_to_kelvin;

    printf("fahrenheit    celsius    kelvin\n");
    printf("%10.2f %10.2f %9.2f\n", temp, celsius_temp, kelvin_temp);
}
