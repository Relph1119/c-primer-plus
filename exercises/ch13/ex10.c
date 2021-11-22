//
// Created by HRF on 2021/11/15.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LEN 80

char *s_gets(char *st, int n);

int main(void) {

    char file_name[LEN];
    FILE *fp;
    int num;
    int ch;

    printf("Enter a file name:");
    // input exercises/ch13/files/wordy
    s_gets(file_name, LEN);
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Could not open file %s for input\n", file_name);
        exit(EXIT_FAILURE);
    }

    printf("Enter a number to seek file:");
    while (scanf("%d", &num) == 1 && num > 0) {
        printf("After %dth character, file content:\n", num);
        fseek(fp, num - 1, SEEK_SET);
        while (ch != '\n') {
            ch = getc(fp);
            putchar(ch);
        }
        printf("\nEnter next number to seek file (<0 to quit):");
    }

    if (fclose(fp) != 0) {
        printf("Could not close file %s\n", file_name);
    }

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}