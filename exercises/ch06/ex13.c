//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
#define SIZE 8

int main(void){
    int tow_pows[SIZE];
    int i;
    int value = 1;

    for (i = 0; i < SIZE; i++){
        tow_pows[i] = value;
        value *= 2;
    }

    i = 0;
    do {
        printf("%d ", tow_pows[i]);
        i++;
    } while (i < SIZE);
    printf("\n");

    return 0;
}
