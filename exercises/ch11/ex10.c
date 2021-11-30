//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <string.h>

#define LEN 80

char *s_gets(char *st, int n);
// 删除空格
void drop_space(char *str);

int main(void) {
    char input[LEN];

    // 提示用户输入字符串
    printf("Please enter a string:\n");
    while (s_gets(input, LEN) && input[0] != '\0') {
        // 删除字符串中的空格
        drop_space(input);
        printf("The result string: %s\n", input);
        printf("Please enter next string (empty line to quit):\n");
    }
    printf("Done!");
    return 0;
}

// 使用指针表示法，操作字符串删除空格
void drop_space(char *str) {
    char *pos;

    while (*str) {
        if (*str == ' ') {
            // 如果遇到空格
            pos = str;
            do {
                // 将后面的字符移动到前面
                *pos = *(pos + 1);
                // 继续循环
                pos++;
            } while (*pos);
        } else {
            // 如果没有遇到空格，继续循环比较
            str++;
        }
    }
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
