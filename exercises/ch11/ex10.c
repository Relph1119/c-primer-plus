//
// Created by HRF on 2021/11/11.
//
#include "stdio.h"
#include "string.h"
#define LEN 80

char *s_gets(char *st, int n);
void drop_space(char * str);

int main(void) {
    char input[LEN];

    printf("Please enter a string:");
    while (s_gets(input, LEN) && input[0] != '\0') {
        drop_space(input);
        printf("The result string: %s\n", input);
        printf("Please enter next string (empty line to quit):");
    }
    printf("Done!\n");
    return 0;
}

void drop_space(char * str) {
    char * pos;

    while(*str) {
        if(*str == ' ') {
            pos = str;
            do {
                *pos = *(pos + 1);
                pos++;
            } while (*pos);
        }else {
            str++;
        }
    }
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
            else
                while (getchar() != '\n')
                    continue;
    }
    return ret_val;
}
