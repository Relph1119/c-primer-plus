//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>
void ch_line_row(int ch, int c, int r);

int main(void) {
    int ch;
    int col, row;

    printf("Enter a character (& to quit):");
    while ((ch =  getchar()) != '&') {
        if (ch == '\n')
            continue;
        printf("Enter number of rows and columns:");
        if (scanf("%d %d", &row, &col) != 2)
            break;
        ch_line_row(ch, col, row);
        printf("\nEnter next character (& to quit):");
    }

    printf("Bye!");
    return 0;
}

void ch_line_row(int ch, int c, int r){
    int col, row;

    for(row = 0; row < r; row++){
        for(col = 0; col < c; col++)
            putchar(ch);
        putchar('\n');
    }
}