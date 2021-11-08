//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
#include "string.h"

int main(void){
    char word[20];
    int i, length;

    printf("Enter a word:");
    scanf("%s", word, 20);

    length = strlen(word) - 1;
    for(i = length; i >= 0; i--){
        printf("%c", word[i]);
    }

    return 0;
}