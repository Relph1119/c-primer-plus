//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <string.h>

#define LEN 80

char *string_in(const char *str1, const char *str2);

char *s_gets(char *st, int n);

int main(void) {
    char str1[LEN], str2[LEN];
    char *found;

    // 提示用户输入两个字符串
    printf("Please enter string 1:\n");
    while (s_gets(str1, LEN) && str1[0] != '\0') {
        printf("Please enter string 2:\n");
        s_gets(str2, LEN);

        // 调用函数返回第1个字符串开始的地址
        found = string_in(str1, str2);
        if (found) {
            printf("Found %s in %s, the result is %p.\n", str2, str1, found);
        } else {
            printf("Not found %s in %s.\n", str2, str1);
        }
        printf("Please enter next string 1 (empty line to quit):\n");
    }
    printf("Done!");
}

char *string_in(const char *str1, const char *str2) {
    // 得到s2的长度
    int s2_length = strlen(str2);
    // 两个字符串长度的差值
    int diff;
    int no_match = 1;

    diff = strlen(str1) - s2_length + 1;
    if (diff > 0) {
        // 通过将str1逐步加长，并进行比较，返回比较结果
        while ((no_match = strncmp(str1, str2, s2_length)) && diff--) {
            str1++;
        }
    }
    if (no_match)
        return NULL;
    else
        // 返回地址
        return (char *) str1;
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