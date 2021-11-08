//
// Created by HRF on 2021/11/1.
//
#include "stdio.h"
int main(void){
    const int days_per_week = 7;
    int days, weeks, day_rem;

    printf("Enter the number of days:");
    scanf("%d", &days);
    while(days > 0){
        weeks = days / days_per_week;
        day_rem = days % days_per_week;
        printf("%d days are %d weeks, %d days.\n", days, weeks, day_rem);

        printf("Enter the number of days (0 or less to quit):");
        scanf("%d", &days);
    }
    printf("Bye!\n");

    return 0;
}