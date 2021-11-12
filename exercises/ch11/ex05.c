//
// Created by HRF on 2021/11/10.
//
#include "stdio.h"
#include "string.h"

#define LEN 80

char *my_strchr(char *input, char ch);
char *s_gets(char *st, int n);

int main(void) {
    char input[LEN];
    char *loc;
    char ch;

    printf("Please enter a string:");
    while (s_gets(input, LEN) != NULL && input[0] != '\0') {
        printf("Please enter a character you want to find:");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        loc = my_strchr(input, ch);
        if (loc) {
            printf("the point of %c in %s is %p.\n", ch, input, loc);
        } else {
            printf("Not found %c in %s.\n", ch, input);
        }
        printf("Please enter next string (empty line to quit): ");
    }
    printf("Done!\n");

    return 0;
}

char * my_strchr(char input[], char ch) {
    int i;
    int length = strlen(input);
    for (i = 0; i < length; i++) {
        if (input[i] == ch) {
            return &input[i];
        }
    }
    return NULL;
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