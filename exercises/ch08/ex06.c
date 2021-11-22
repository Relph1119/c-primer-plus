//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>
#include <ctype.h>
int get_first(void);

int main(void) {
    int ch;

    printf("Please enter a word:");
    ch = get_first();
    printf("The first character is %c", ch);

    return 0;
}

int get_first(void) {
    int ch;

    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}