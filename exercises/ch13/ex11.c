//
// Created by HRF on 2021/11/15.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SLEN 256

// ex11.exe The exercises/ch13/files/wordy
int main(int argc, char *argv[]) {
    FILE *fp;
    char line_content[SLEN];

    if (argc != 3) {
        // 检查命令行参数，显示命令用法
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 检查是否能正常打开文件，获取文件句柄
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Can not open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("The line contain \"%s\" in file %s:\n", argv[1], argv[2]);
    while (fgets(line_content, SLEN, fp) != NULL) {
        // 判断该行是否包含字符串
        if (strstr(line_content, argv[1]) != NULL)
            fputs(line_content, stdout);
    }

    // 检查文件是否正常关闭，并关闭该文件
    if (fclose(fp) != 0) {
        fprintf(stderr, "Could not close file %s\n", argv[1]);
    }

    return 0;
}