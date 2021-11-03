//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
#define SIZE 6

int main(void){

    int count;
    char letter = 'A';
    for(count = 0; count < SIZE; count++){
        letter += count;
        char temp = letter;
        for(int j = 0; j <= count; temp++, j++){
            printf("%c", temp);
        }
        printf("\n");
    }

    return 0;
}