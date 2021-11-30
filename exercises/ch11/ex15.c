//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 80

char *s_gets(char *st, int n);

int my_atoi(char *str);

int main(void) {
    char input[LEN];

    // 提示用户输入一个整数字符串
    printf("Please enter a number:");
    while (s_gets(input, LEN) && input[0] != '\0') {
        // 打印字符串转整数
        printf("string %s to integer %d\n", input, my_atoi(input));
        printf("Please enter next number (empty line to quit):");
    }
    printf("Done!\n");

    return 0;
}

int my_atoi(char *str) {
    // 获取整数字符串的长度
    int length = strlen(str);
    int i;
    int value = 0;
    // 循环读取字符串
    for (i = 0; i < length; i++) {
        // 判断字符是否为数字
        if (!isdigit(str[i]))
            return 0;
        // 得到一个十进制整数
        value = value * 10 + (str[i] - '0');
    }
    return value;
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
