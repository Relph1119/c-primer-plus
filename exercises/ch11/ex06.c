//
// Created by HRF on 2021/11/11.
//
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LEN 80

bool is_within(const char *str, char c);

char *s_gets(char *st, int n);

int main(void) {
    char input[LEN];
    char ch;
    int found;

    // 提示用户输入字符串
    printf("Please enter a string:\n");
    while (s_gets(input, LEN) && input[0] != '\0') {
        // 提示用户输入指定的字符
        printf("Please enter a character:");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        //调用函数，返回是否在字符串中
        found = is_within(input, ch);
        if (found == 0) {
            printf("Not found %c in \"%s\"\n", ch, input);
        } else {
            printf("%c found in \"%s\"\n", ch, input);
        }
        printf("Please enter next string (empty line to quit):\n");
    }
    printf("Done!");

    return 0;
}

bool is_within(const char *str, char ch) {
    // 使用while循环进行判断，如果不存在就
    while (*str != ch && *str != '\0')
        str++;
    return *str;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
