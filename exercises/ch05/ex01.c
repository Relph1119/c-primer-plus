//
// Created by HRF on 2021/11/1.
//
#include <stdio.h>
#define MIN_PER_HOUR 60
int main(void){
    int minutes, hours, mins;

    printf("Enter the number of minutes to convert:");
    scanf("%d", &minutes);
    while (minutes > 0){
        hours = minutes / MIN_PER_HOUR;
        mins = minutes % MIN_PER_HOUR;
        printf("%d minutes = %d hours, %d minutes\n", minutes, hours, mins);
        printf("Enter next minutes value(0 to quit):");
        scanf("%d", &minutes);
    }
    printf("Bye!\n");

    return 0;
}