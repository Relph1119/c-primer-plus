//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>

int main(int argc, char **argv) {
    int i;

    // 打印命令行参数
    printf("The argument values:\n");
    for(i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    printf("\nThe reserve arguments values:\n");
    // 根据输入的参数个数，反向打印每个命令行参数
    for (i = argc - 1; i > 0; i--) {
        if (i == 0) {
            printf("\n");
        } else {
            printf("%s ", argv[i]);
        }

    }
    return 0;
}