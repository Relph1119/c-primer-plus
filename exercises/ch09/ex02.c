//
// Created by HRF on 2021/11/5.
//
#include "stdio.h"
void chline(int ch, int i, int j);

int main(void) {
    int ch;
    int j, i;
    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n') {
        if (scanf("%d %d", &i, &j) != 2)
            break;
        chline(ch, i, j);
        while (getchar() != '\n')
            continue;
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }

    printf("Bye.\n");
    return 0;
}

void chline(int ch, int i, int j) {
    int row, col;

    for (row = 1; row <= i; row++) {
        for (col = 1; col <= j; col++)
            putchar(ch);
        putchar('\n');
    }
}