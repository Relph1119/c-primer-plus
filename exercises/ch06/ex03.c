//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

#define LETTER 'F'

int main(void) {
    char start;
    char end;

    // 由于打印结果是到A为止，可判断下界为字母'A'
    for (end = LETTER; end >= 'A'; end--) {
        // 打印一行，从字母F开始到end变量
        for (start = LETTER; start >= end; start--)
            printf("%c", start);
        // 打印之后换行
        printf("\n");
    }

    return 0;
}
