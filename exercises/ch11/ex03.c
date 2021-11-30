//
// Created by HRF on 2021/11/10.
//
#include <stdio.h>
#include <ctype.h>

#define LEN 80
// 设置停止词
#define STOP '\n'

char *get_word(char *str);

int main(void) {
    char input[LEN];

    printf("Please enter chars:\n");
    while (get_word(input) != NULL) {
        printf("The word is ");
        puts(input);
        printf("Please enter chars (a newline to quit):\n");
    }
    puts("Done.");

    return 0;
}

char *get_word(char *str) {
    int ch;

    // 跳过前面所有的空白
    while ((ch = getchar()) != STOP && (isspace(ch) || ispunct(ch)))
        continue;

    // 读取单词
    if (ch != STOP)
        *str++ = (char) ch;

    while ((ch = getchar()) != STOP && !(isspace(ch) || ispunct(ch)))
        *str++ = (char) ch;
    if (ch != STOP) {
        // 丢弃输入行后的其余字符
        while (ch != '\n')
            ch = getchar();
        // 设置最后一个元素为空字符
        *str++ = '\0';
        return str;
    }
    return NULL;
}