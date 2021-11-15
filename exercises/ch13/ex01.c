//
// Created by HRF on 2021/11/15.
//
#include <stdio.h>
#include <stdlib.h> // exit() prototype

#define LEN 81
char *s_gets(char *st, int n);


int main(void) {
    int ch;         // place to store each character as read
    FILE *fp;       // "file pointer"
    unsigned long count = 0;
    char file_name[LEN];

    printf("Enter a file name you want:\n");
    // input exercises/ch13/files/eddy
    s_gets(file_name, LEN);

    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);  // same as putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", file_name, count);

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
