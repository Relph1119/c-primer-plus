//
// Created by HRF on 2021/11/15.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ROWS 20
#define COLS 30
#define LEVELS 10
#define LEN 81
const char trans[LEVELS + 1] = " .':~*=&%#";

void init_pic(int rows, int cols, char pic[rows][cols], char ch);

char *s_gets(char *st, int n);

int clean_distortion(int rows, int cols, int data[rows][cols], int row, int col);

void trans_pic(int rows, int cols, int data[rows][cols], char pic[rows][cols]);

void save_pic(int rows, int cols, char save_file_name[], char pic[rows][cols]);

int main(void) {

    int row, col;
    int arr[ROWS][COLS];
    char pic[ROWS][COLS];
    char data_file_name[LEN];
    char save_file_name[LEN];
    FILE *data_pf;

    init_pic(ROWS, COLS, pic, '$');

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
    // clean distortion
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            arr[row][col] = clean_distortion(ROWS, COLS, arr, row, col);
        }
    }
    // transform picture
    trans_pic(ROWS, COLS, arr, pic);

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++)
            putchar(pic[row][col]);
        putchar('\n');
    }

    save_pic(ROWS, COLS, save_file_name, pic);

    return 0;
}

void save_pic(int rows, int cols, char save_file_name[], char pic[rows][cols]) {
    int row, col;
    FILE *save_pf;

    printf("Enter the file name to save:");
    // input exercises/ch13/files/pic_clean_distortion_file
    s_gets(save_file_name, LEN);
    if ((save_pf = fopen(save_file_name, "w")) == NULL) {
        fprintf(stderr, "Could not open data file %s.\n", save_file_name);
        exit(EXIT_FAILURE);
    }

    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            fprintf(save_pf, "%c", pic[row][col]);
        }
        putc('\n', save_pf);
    }
    if (fclose(save_pf) != 0) {
        fprintf(stderr, "Can't close file %s\n", save_file_name);
    }
}

void trans_pic(int rows, int cols, int data[rows][cols], char pic[rows][cols]) {
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            pic[r][c] = trans[data[r][c]];
}

int clean_distortion(int rows, int cols, int data[rows][cols], int row, int col) {
    int avg;

    if (row == 0) {
        // 矩形上边
        if (col == 0) {
            // 左上角
            if ((data[row][col] - data[row][col + 1]) > 1 && (data[row][col] - data[row + 1][cols]) > 1) {
                avg = (int) ((data[row][col + 1] + data[row + 1][cols]) / 2.0 + 0.5);
                return avg;
            }
        } else if (col == cols - 1) {
            // 右上角
            if ((data[row][col] - data[row][col - 1]) > 1 && (data[row][col] - data[row + 1][cols]) > 1) {
                avg = (int) ((data[row][col - 1] + data[row + 1][cols]) / 2.0 + 0.5);
                return avg;
            }
        } else {
            // 上边
            if ((data[row][col] - data[row][col - 1]) > 1 &&
                (data[row][col] - data[row][col + 1]) > 1 &&
                (data[row][col] - data[row + 1][col]) > 1) {
                avg = (int) ((data[row][col - 1] + data[row][col + 1] + data[row + 1][col]) / 3.0 + 0.5);
                return avg;
            }
        }
    } else if (row == rows - 1) {
        // 矩形下边
        if (col == 0) {
            // 左下角
            if ((data[row][col] - data[row - 1][col]) > 1 && (data[row][col] - data[row][cols + 1]) > 1) {
                avg = (int) ((data[row - 1][col] + data[row][cols + 1]) / 2.0 + 0.5);
                return avg;
            }
        } else if (col == cols - 1) {
            // 右下角
            if ((data[row][col] - data[row][col - 1]) > 1 && (data[row][col] - data[row - 1][cols]) > 1) {
                avg = (int) ((data[row][col - 1] + data[row - 1][cols]) / 2.0 + 0.5);
                return avg;
            }
        } else {
            // 下边
            if ((data[row][col] - data[row][col - 1]) > 1 &&
                (data[row][col] - data[row][col + 1]) > 1 &&
                (data[row][col] - data[row - 1][col]) > 1) {
                avg = (int) ((data[row][col - 1] + data[row][col + 1] + data[row - 1][col]) / 3.0 + 0.5);
                return avg;
            }
        }
    }

    if (col == 0) {
        // 左边
        if ((data[row][col] - data[row - 1][col]) > 1 &&
            (data[row][col] - data[row + 1][col]) > 1 &&
            (data[row][col] - data[row][col + 1]) > 1) {
            avg = (int) ((data[row - 1][col] + data[row + 1][col] + data[row][col + 1]) / 3.0 + 0.5);
            return avg;
        }
    } else if (col == cols - 1) {
        // 右边
        if ((data[row][col] - data[row - 1][col]) > 1 &&
            (data[row][col] - data[row + 1][col]) > 1 &&
            (data[row][col] - data[row][col - 1]) > 1) {
            avg = (int) ((data[row - 1][col] + data[row + 1][col] + data[row][col - 1]) / 3.0 + 0.5);
            return avg;
        }
    }
    // 剩余;
    if ((data[row][col] - data[row - 1][col]) > 1 &&
        (data[row][col] - data[row + 1][col]) > 1 &&
        (data[row][col] - data[row][col - 1]) > 1 &&
        (data[row][col] - data[row][col + 1]) > 1) {
        avg = (int) ((data[row - 1][col] + data[row + 1][col] + data[row][col - 1] + data[row][col + 1]) / 4.0 + 0.5);
        return avg;
    }
    return data[row][col];
}

void init_pic(int rows, int cols, char pic[rows][cols], char ch) {
    int r, c;
    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
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