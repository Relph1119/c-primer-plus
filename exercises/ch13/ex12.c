//
// Created by HRF on 2021/11/15.
//
#include <string.h>
#include <stdlib.h>
#include "stdio.h"

#define ROWS 20
#define COLS 30
#define LEVELS 10
#define LEN 81
const char trans[LEVELS + 1] = " .':~*=&%#";

void init_pic(char pic[][COLS], char ch);
char *s_gets(char *st, int n);
void trans_pic(int data[][COLS], char pic[][COLS], int rows);
void save_pic(char save_file_name[], char pic[][COLS]);

int main(void) {

    int row, col;
    int arr[ROWS][COLS];
    char pic[ROWS][COLS];
    char data_file_name[LEN];
    char save_file_name[LEN];
    FILE *data_pf;

    init_pic(pic, '$');

    printf("Enter the name of data file:");
    // input exercises/ch13/files/data_file
    s_gets(data_file_name, LEN);
    if ((data_pf = fopen(data_file_name, "r")) == NULL) {
        fprintf(stderr, "Could not open data file %s.\n", data_file_name);
        exit(EXIT_FAILURE);
    }

    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            fscanf(data_pf, "%d", &arr[row][col]);

    if (ferror(data_pf)) {
        fprintf(stderr, "Error getting data from file %s.\n", data_file_name);
        exit(EXIT_FAILURE);
    }

    trans_pic(arr, pic, ROWS);

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++)
            putchar(pic[row][col]);
        putchar('\n');
    }

    save_pic(save_file_name, pic);

    return 0;
}

void save_pic(char save_file_name[], char pic[][COLS]) {
    int row, col;
    FILE *save_pf;

    printf("Enter the file name to save:");
    // input exercises/ch13/files/pic_file
    s_gets(save_file_name, LEN);
    if ((save_pf = fopen(save_file_name, "w")) == NULL) {
        fprintf(stderr, "Could not open data file %s.\n", save_file_name);
        exit(EXIT_FAILURE);
    }

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            fprintf(save_pf, "%c", pic[row][col]);
        }
        putc('\n', save_pf);
    }
    if (fclose(save_pf) != 0) {
        fprintf(stderr, "Can't close file %s\n", save_file_name);
    }
}

void trans_pic(int data[][COLS], char pic[][COLS], int rows) {
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            pic[r][c] = trans[data[r][c]];
}

void init_pic(char pic[][COLS], char ch) {
    int r, c;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            pic[r][c] = ch;
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