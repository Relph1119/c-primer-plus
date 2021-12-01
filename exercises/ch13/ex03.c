//
// Created by HRF on 2021/11/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN 81

char *s_gets(char *st, int n);

int main(void) {
    int ch;
    FILE *source_file;
    FILE *target_file;
    char source_file_name[LEN];
    char target_file_name[LEN];

    // 提示用户输入文本文件名
    printf("Enter a source file name:\n");
    s_gets(source_file_name, LEN);
    // input exercises/ch13/files/eddy
    // 检查文件是否能正常打开，并获取文件句柄
    if ((source_file = fopen(source_file_name, "r")) == NULL) {
        printf("Could not open file %s for input\n", source_file_name);
        exit(EXIT_FAILURE);
    }

    printf("Enter a target file name:\n");
    s_gets(target_file_name, LEN);
    // input exercises/ch13/files/eddy_upper
    if ((target_file = fopen(target_file_name, "w")) == NULL) {
        printf("Could not open file %s for output\n", target_file_name);
        exit(EXIT_FAILURE);
    }

    printf("Transform the file......\n");
    while ((ch = getc(source_file)) != EOF) {
        // 对字符进行大写转换
        putc(toupper(ch), target_file);
    }
    printf("Complete the file transform from file %s to file %s\n", source_file_name, target_file_name);

    // 检查文件是否能正常关闭，并关闭文件
    if (fclose(source_file) != 0)
        printf("Could not close file %s\n", source_file_name);
    if (fclose(target_file) != 0)
        printf("Could not close file %s\n", target_file_name);

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