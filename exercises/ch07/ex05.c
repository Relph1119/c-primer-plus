//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    int ch;
    int count1 = 0;
    int count2 = 0;

    printf("Enter text to be analyzed (# to terminate):\n");
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case '.':
                putchar('!');
                count1++;
                break;
            case '!':
                putchar('!');
                putchar('!');
                count2++;
                break;
            default:
                putchar(ch);
        }
    }

    printf("\n%d replacement(s) of . with !\n", count1);
    printf("%d replacement(s) of ! with !!\n", count2);

    return 0;
}