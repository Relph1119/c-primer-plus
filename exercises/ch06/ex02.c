//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>
#define SIZE 5

int main(void){
    for(int i = 0; i < SIZE; i++){
        for (int j = 0; j <= i; j++)
            printf("$");
        printf("\n");
    }

    return 0;
}