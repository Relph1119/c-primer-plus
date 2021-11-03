//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"

int main(void) {
    char ch;
    char prev = ' ';
    int count = 0;

    while ((ch = getchar()) != '#') {
        if (prev == 'e' && ch == 'i')
            count++;
        else
            prev = ch;
    }
    printf("Number of ei: %d\n", count);

    return 0;
}