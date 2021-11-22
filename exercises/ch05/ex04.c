//
// Created by HRF on 2021/11/1.
//
#include <stdio.h>
int main(void){
    const float cm_per_inches = 2.54;
    const int inches_per_feet = 12;

    float height, inches;
    int feet;

    printf("Enter a height in centimeters:");
    scanf("%f", &height);
    while (height > 0) {
        inches = height / cm_per_inches;
        feet = inches / inches_per_feet;
        inches = inches - feet * inches_per_feet;
        printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);

        printf("Enter a height in centimeters (<=0 to quit):");
        scanf("%f", &height);
    }
    printf("bye\n");

    return 0;
}
