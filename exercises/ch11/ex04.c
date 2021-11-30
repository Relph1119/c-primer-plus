//
// Created by HRF on 2021/11/10.
//
#include <stdio.h>
#include <ctype.h>

#define LEN 80
#define MAX_LEN 10
// 设置停止词
#define STOP '\n'

// 读取n个字符的单词
char *get_n_word(char *str, int n);

int main(void) {
    char input[LEN];
    int n = MAX_LEN - 1;

    printf("Please enter chars:\n");
    while (get_n_word(input, n) != NULL) {
        printf("The word is ");
        puts(input);
        printf("Please enter chars (a newline to quit):\n");
    }
    puts("Done.");

    return 0;
}

char *get_n_word(char *str, int n) {
    int i;
    int ch;

    // 跳过前面所有的空白
    while ((ch = getchar()) != STOP && (isblank(ch) || ispunct(ch)))
        continue;
    if (ch != STOP) {
        str[0] = ch;
    }

    for (i = 1; i < n; i++) {
        // 读取单词
        ch = getchar();
        if (ch != STOP && !(isblank(ch) || ispunct(ch)))
            str[i] = ch;
        else
            break;
    }
    // 设置最后一个元素为空字符
    str[i] = '\0';

    if (ch != STOP) {
        // 丢弃输入行后的其余字符
        while (ch != '\n')
            ch = getchar();
        return str;
    }
    return NULL;
}
