//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    // 当前字符
    int ch;
    // 前一个字符
    int prev = ' ';
    // ei出现的次数
    int count = 0;

    printf("Please input chars (# to quit):\n");
    while ((ch = getchar()) != '#') {
        // 判断是否为ei
        if (prev == 'e' && ch == 'i') {
            count++;
        } else {
            // 记录前一个字符
            prev = ch;
        }
    }
    // 报告ei出现的次数
    printf("Total ei appear %d times in all chars.\n", count);
    printf("Done\n");

    return 0;
}