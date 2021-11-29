//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    int ch;
    int space_count = 0;
    int newlines_count = 0;
    int other = 0;

    printf("Please input chars (# to exit):\n");
    while ((ch = getchar()) != '#') {
        if (ch == ' ')
            // 统计空格符号的数量
            space_count++;
        else if (ch == '\n')
            // 统计换行符的数量
            newlines_count++;
        else
            // 统计所有其他字符的数量
            other++;
    }

    // 打印统计结果
    printf("spaces: %d, newlines: %d, others: %d", space_count, newlines_count, other);
    return 0;
}