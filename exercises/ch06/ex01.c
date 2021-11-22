//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>
#define SIZE 26

int main(void){
    char letters[SIZE];
    int i;

    for (i = 0; i < SIZE; i++)
        letters[i] = 'a' + i;

    for (i = 0; i < SIZE; i++)
        printf("%c", letters[i]);

    printf("\n");
    return 0;
}
