//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
#include "string.h"
#define SIZE 255

int main(void){
    char sentence[SIZE];
    int i, length;

    printf("Enter a sentence:");
    scanf_s("%s", sentence, 20);

    length = strlen(sentence) - 1;
    for(i = length; i >= 0; i--){
        printf("%c", sentence[i]);
    }

    return 0;
}
