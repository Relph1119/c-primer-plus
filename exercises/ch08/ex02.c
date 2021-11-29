//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>

int main(void) {
    int ch;
    // 字符数
    int count = 0;

    while ((ch = getchar()) != '&') {
        // 当满10个，则打印换行符
        if (count++ == 10) {
            printf("\n");
            count = 1;
        }
        // 大于空格字符显示字符和相应的ASCII码
        if (ch >= '\040') {
            printf("%2c-%3d ", ch, ch);
        } else if (ch == '\t') {
            // 处理制表符
            printf("\\t-%3d", ch);
            printf(" ");
        } else if (ch == '\n') {
            // 处理换行符
            printf("\\n-%3d\n", ch);
            count = 0;
        } else {
            // 处理其他的非打印字符
            printf("^%c-%3d", ch, (ch + 64));
        }
    }

    return 0;
}