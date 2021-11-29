//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>

int main(void) {
    int ch;
    // 字符数
    int count = 0;

    // 读取文件输入流，配置Redirect input from：exercises\ch08\files\file
    while ((ch = getchar()) != '&') {
        count++;
    }
    // 打印字符总数
    printf("%d characters read.\n", count);
    return 0;
}