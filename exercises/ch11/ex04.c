//
// Created by HRF on 2021/11/10.
//
#include <stdio.h>
#include <ctype.h>
#define LEN 80
#define MAX_LEN 10
char * get_n_word(char * str, int n);

int main(void) {
    char input[LEN];

    while (get_n_word(input, MAX_LEN - 1) != NULL)
        puts(input);
    puts("Done.\n");

    return 0;
}

char * get_n_word(char * str, int n) {
    int i;
    int ch;
    char * orig = str;

    while ((ch = getchar()) != EOF && isblank(ch))
        continue;
    if (ch == EOF)
        return NULL;
    else
        str[0] = ch;

    for (i = 1; i < n; i++) {
        ch = getchar();
        if (ch != EOF && !isblank(ch))
            str[i] = ch;
        else
            break;
    }
    str[i] = '\0';

    if (ch == EOF)
        return NULL;
    else {
        while (ch != '\n')
            ch = getchar();
        return orig;
    }
}
