//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    char mode = 'p';
    bool ok = true;
    int ch;

    if (argc == 2) {
        if (argv[1][0] != '-') {
            printf("Usage: %s [-p | -u | -l]\n", argv[0]);
            ok = false;
        } else {
            switch (argv[1][1]) {
                case 'p':
                case 'u':
                case 'l':
                    mode = argv[1][1];
                    break;
                default:
                    printf("%s invalid parameter; ", argv[1]);
                    printf("using default parameter p.\n");
            }
        }
    }

    if (ok) {
        while ((ch = getchar()) != EOF) {
            switch (mode) {
                case 'p':
                    putchar(ch);
                    break;
                case 'u':
                    putchar(toupper(ch));
                    break;
                case 'l':
                    putchar(tolower(ch));
                default:;
            }
        }
    }
    return 0;
}
