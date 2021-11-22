//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void){
    char letter = 'F';
    char start;
    char end;

    for (end = letter; end >= 'A'; end--){
        for (start = letter; start >= end; start--)
            printf("%c", start);
        printf("\n");
    }

    return 0;
}
