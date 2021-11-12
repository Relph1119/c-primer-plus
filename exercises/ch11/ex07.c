//
// Created by HRF on 2021/11/11.
//
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define LEN 80
char *s_gets(char *st, int n);
char *mystrncpy(char *str1, const char *str2, int num);

int main(void) {
    char input1[LEN] = "";
    char input2[LEN];
    char * ret_val;
    int num;

    printf("Please enter string:");
    while (s_gets(input2, LEN) && input2[0] != '\0') {
        printf("Please enter a number (1 to %d):", LEN);
        scanf("%d", &num);
        while (getchar() != '\n')
            continue;

        mystrncpy(input1, input2, num);
        printf("input2: %s\n", input2);
        printf("input1: %s\n", input1);

        printf("Please enter next string (empty line to quit):");
    }
    printf("Done!\n");

    return 0;
}

char *mystrncpy(char *str1, const char *str2, int n) {
    int i;

    for (i = 0; i < n; i++) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return str1;
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