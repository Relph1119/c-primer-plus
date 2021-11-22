//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void){
    int friends = 5;
    int weeks = 1;

    printf("The number of Dr Rabnud's friends:\n");
    printf("%5s %10s\n", "Week", "Friends");

    while (friends <= 150) {
        friends = (friends - 1) * 2;
        printf("%5d %10d\n", weeks, friends);
        weeks++;
    }

    return 0;
}