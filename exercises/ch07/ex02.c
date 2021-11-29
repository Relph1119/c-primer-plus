//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

#define SIZE 8

int main(void) {
    int ch;
    int count = 0;

    printf("Please input chars (# to quit):\n");
    // 判断读到#字符停止
    while ((ch = getchar()) != '#') {
        if (count++ % SIZE == 0) {
            printf("\n");
        }
        // 打印字符-ASCII码
        if (ch == '\n') {
            printf("\\n-%3d ", ch);
        } else if (ch == '\t') {
            printf("\\t-%3d ", ch);
        } else {
            printf("%c-%3d ", ch, ch);
        }
    }

    return 0;
}
