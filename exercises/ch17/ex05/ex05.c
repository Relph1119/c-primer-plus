//
// Created by HRF on 2021/11/23.
//
#include <stdio.h>
#include "stack.h"
#include <string.h>
#define SLEN 81

char *s_gets(char *st, int n);

int main(void) {
    Stack stack;
    char temp[SLEN];
    int i;
    char ch;

    InitializeStack(&stack);
    printf("Enter a line:\n");
    while (s_gets(temp, SLEN) && temp[0] != '\0') {
        i = 0;
        while (temp[i] != '\0' && !StackIsFull(&stack)) {
            Push(temp[i], &stack);
            i++;
        }

        while (!StackIsEmpty(&stack)) {
            Pop(&ch, &stack);
            putchar(ch);
        }
        putchar('\n');
        printf("Enter next line (empty line to quit):\n");
    }
    printf("Bye.\n");

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
