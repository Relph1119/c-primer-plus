//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>
#include <ctype.h>

int get_first(void);

int main(void) {
    int ch;

    // 提示用户输入一个单词
    printf("Please enter a word:");
    ch = get_first();
    printf("The first character is %c", ch);

    return 0;
}

int get_first(void) {
    int ch;

    // 获取第一个字符
    ch = getchar();
    // 如果是空白或标点字符，就取下一个字符
    while (isspace(ch) || ispunct(ch))
        ch = getchar();

    // 将所有的输入流都清空
    while (getchar() != '\n')
        continue;

    // 返回不是空白或标点的字符，即已取到的字符
    return ch;
}