//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // 默认模式是p
    char mode = 'p';
    bool ok = true;
    int ch;

    if (argc == 2) {
        if (argv[1][0] != '-') {
            // 如果第1个命令行参数不是-x型，则提示用户命令行用法
            printf("Usage: %s [-p | -u | -l]\n", argv[0]);
            ok = false;
        } else {
            switch (argv[1][1]) {
                case 'p':
                case 'u':
                case 'l':
                    // 读取模式
                    mode = argv[1][1];
                    break;
                default:
                    printf("%s invalid parameter; ", argv[1]);
                    printf("using default parameter p.\n");
            }
        }
    }

    if (ok) {
        while ((ch = getchar()) != EOF) {
            // 根据不同的模式，执行操作
            switch (mode) {
                case 'p':
                    // 按原样打印
                    putchar(ch);
                    break;
                case 'u':
                    // 把输入全部转换成大写
                    putchar(toupper(ch));
                    break;
                case 'l':
                    // 把输入全部转换成小写
                    putchar(tolower(ch));
                default:;
            }
        }
    }
    return 0;
}
