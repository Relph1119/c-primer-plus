//
// Created by HRF on 2021/11/15.
//
#include <stdio.h>
#include <stdlib.h> // exit() prototype
#include <string.h>

#define LEN 81

char *s_gets(char *st, int n);

// ex08.exe a exercises/ch13/files/eddy
int main(int argc, char *argv[]) {
    char find_ch;
    char ch;
    FILE *fp;
    unsigned long count = 0;
    char input[LEN];


    if (argc < 2) {
        printf("Usage: %s <character> [file_name1 ....]", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) == 1) {
        find_ch = argv[1][0];
    } else {
        printf("Usage: %s <character> [file_name1 ....]", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2) {
        printf("Enter the string you wanted to analysize: ");
        s_gets(input, LEN);
        int input_length = strlen(input);
        for (int i = 0; i < input_length; i++) {
            if (find_ch == input[i]) {
                count++;
            }
        }
        printf("In string \"%s\", %c have appeared %d times\n", input, find_ch, count);
    } else {
        for (int i = 2; i < argc; i++) {
            count = 0;
            if ((fp = fopen(argv[i], "r")) == NULL) {
                printf("Could not open file %s for input\n", argv[i]);
                continue;
            }
            while ((ch = fgetc(fp)) != EOF) {
                if (find_ch == ch)
                    count++;
            }
            if (fclose(fp) != 0) {
                printf("Could not close file %s\n", argv[i]);
            }
            printf("In file %s, %c have appeared %lu times\n", argv[i], find_ch, count);
        }
    }

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
