//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void){


    int limit;
    printf("Enter the number of times you want:");
    scanf("%d", &limit);

    while(limit > 0){
        double sum = 0, den = 1.0;
        for(int i = 0; i <= limit; i++, den++){
            sum += 1.0 / den;
        }
        printf("1.0 + 1.0 / 2.0 + 1.0 / 3.0 + 1.0 / 4.0 +... + 1.0 / %d = %f\n", limit, sum);

        sum = 0, den = 1.0;
        for(int i = 0; i <= limit; i++, den++){
            int sign = 1;
            if(i % 2 != 0){
                sign = -1;
            }
            sum += sign * (1.0 / den);
        }
        printf("1.0 - 1.0 / 2.0 + 1.0 / 3.0 - 1.0 / 4.0 +... + 1.0 / %d = %f\n", limit, sum);

        printf("Enter next number of times (0 or less to quit):");
        scanf("%d", &limit);
    }

    return 0;
}