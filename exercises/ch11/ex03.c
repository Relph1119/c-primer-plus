//
// Created by HRF on 2021/11/10.
//
#include <stdio.h>
#include <ctype.h>
#define LEN 80
char * get_word(char * str);

int main(void) {
    char input[LEN];

    while (get_word(input) != NULL)
        puts(input);
    puts("Done.\n");

    return 0;
}

char * get_word(char * str) {
    int ch;
    char * orig = str;

    while ((ch = getchar()) != EOF && isspace(ch))
        continue;
    if (ch == EOF)
        return NULL;
    else
        *str++ = ch;

    while ((ch = getchar()) != EOF && !isspace(ch))
        *str++ = ch;
    if (ch == EOF)
        return NULL;
    else {
        while (ch != '\n')
            ch = getchar();
        return orig;
    }
}