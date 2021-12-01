//
// Created by HRF on 2021/11/15.
//
#include <stdio.h>
#include <stdlib.h>

// ex04.exe exercises/ch13/files/eddy exercises/ch13/files/eddy_upper
int main(int argc, char * argv[]) {
    int byte;
    FILE * source;
    int file_index;

    if (argc == 1) {
        // 提示用户命令的用法
        printf("Usage: %s filename[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 循环打印文件内容
    for (file_index = 1; file_index < argc; file_index++) {
        // 检查文件是否能正常打开，并获取文件句柄
        if ((source = fopen(argv[file_index], "r")) == NULL) {
            printf("Could not open file %s for input\n", argv[file_index]);
            continue;
        }
        // 打印文件内容
        printf("%s file content:\n", argv[file_index]);
        while ((byte = getc(source)) != EOF) {
            putchar(byte);
        }
        // 检查文件是否能正常关闭，并关闭文件
        if (fclose(source) != 0) {
            printf("Could not close file %s\n", argv[file_index]);
        }
    }

    return 0;
}
