//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

char *s_gets(char *st, int n);
// 校验二进制字符串
bool check_value(const char *str);
// 将二进制字符串转换为十进制数
int bstr_to_dec(const char *str);

int main(void) {
    // 二进制字符串的长度
    const static size_t SLEN = CHAR_BIT * sizeof(int) + 1;
    char value[SLEN];

    // 提示用户输入一个二进制字符串
    printf("Enter a binary number with up to %zu digits:", SLEN - 1);
    while (s_gets(value, SLEN) && value[0] != '\0') {
        // 检查二进制字符串
        if (!check_value(value)) {
            printf("A binary number contains just 0s and 1s.\n");
        } else {
            printf("%s is %d\n", value, bstr_to_dec(value));
        }
        printf("Enter next binary number (empty line to quit):");
    }

    puts("Bye.");
    return 0;
}

int bstr_to_dec(const char *str) {
    int value = 0;

    while (*str != '\0') {
        // 将二进制转换成十进制，每个位乘以2
        value = 2 * value + (*str - '0');
        str++;
    }

    return value;
}

bool check_value(const char *str) {
    bool valid = true;
    while (valid && *str != '\0') {
        // 检查字符串的字符是0或1
        if (*str != '0' && *str != '1') {
            valid = false;
        }
        ++str;
    }
    return valid;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}