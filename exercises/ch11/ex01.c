//
// Created by HRF on 2021/11/10.
//
#include <stdio.h>
#define LEN 10
char * get_n_char(char * str, int n);

int main(void) {
    char input[LEN];
    char *ret_val;

    ret_val = get_n_char(input, LEN - 1);
    if (ret_val == NULL) {
        puts("Input failed.");
    } else {
        puts(input);
    }
    puts("Done.\n");

    return 0;
}

char * get_n_char(char * str, int n) {
    int i;
    char ch;

    for (i = 0; i < n; i++) {
        ch = getchar();
        if (ch != EOF)
            str[i] = ch;
        else
            break;
    }

    if (ch == EOF)
        return NULL;
    else {
        str[i] = '\0';
        return str;
    }
}