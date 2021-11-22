//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>
#include <ctype.h>
int locate(int ch);

int main(void) {
    int ch;

    while((ch = getchar()) != '&') {
        printf("The location of %c in alphabet is %d.\n", ch, locate(ch));
    }

    return 0;
}

int locate(int ch) {
    int index = -1;

    if (isalpha(ch)) {
        index = tolower(ch) - 'a' + 1;
    }
    return index;
}