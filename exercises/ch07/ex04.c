//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"

int main(void) {
    int ch;
    int count1 = 0;
    int count2 = 0;

    printf("Enter text to be analyzed (# to terminate):\n");
    while ((ch = getchar()) != '#') {
        if (ch == '!') {
            putchar('!');
            putchar('!');
            count1++;
        } else if (ch == '.') {
            putchar('!');
            count2++;
        } else {
            putchar(ch);
        }
    }

    printf("\n%d replacement(s) of . with !\n", count2);
    printf("%d replacement(s) of ! with !!\n", count1);

    return 0;
}
