//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>

int main(void) {
    int ch;
    int count = 0;

    while ((ch = getchar()) != '&')
        count++;
    printf("%d characters read.\n", count);
    return 0;
}