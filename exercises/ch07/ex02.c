//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"
#define SIZE 8

int main(void){
    int ch;
    int count = 1;

    while ((ch = getchar()) != '#'){
        printf("%c-%d", ch, ch);
        if (count % SIZE == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
        count++;
    }

    return 0;
}
