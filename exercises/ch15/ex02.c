//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 将二进制字符串转换为十进制数
int bstr_to_dec(const char *str);
// 校验二进制字符串
bool check_value(const char *str);
// 将十进制数转换为二进制字符串
char *itobs(int n, char *ps);

char *s_gets(char *st, int n);

int main(void) {
    const static size_t SLEN = 8 * sizeof(int) + 1;
    char value1[SLEN];
    char value2[SLEN];
    int v1;
    int v2;
    char bstr[SLEN];

    // 提示用户输入第1个数
    printf("Enter first binary number with up to %zu digits:", SLEN - 1);
    while (s_gets(value1, SLEN) && value1[0] != '\0') {
        // 提示用户输入第2个数
        printf("Enter second binary number with up to %zu digits:", SLEN - 1);
        s_gets(value2, SLEN);

        // 检查二进制字符串
        if (!check_value(value1) && !check_value(value2)) {
            printf("A binary number contains just 0s and 1s.\n");
        } else {
            // 将二进制字符串转换为十进制数
            v1 = bstr_to_dec(value1);
            v2 = bstr_to_dec(value2);

            // 使用~运算符、&运算符、|运算符和^运算符
            printf("~%s = %s\n", value1, itobs(~v1, bstr));
            printf("~%s = %s\n", value2, itobs(~v2, bstr));
            printf("%s & %s = %s\n", value1, value2, itobs(v1 & v2, bstr));
            printf("%s | %s = %s\n", value1, value2, itobs(v1 | v2, bstr));
            printf("%s ^ %s = %s\n", value1, value2, itobs(v1 ^ v2, bstr));
        }
        printf("Enter next binary number (empty line to quit):");
    }
    puts("Done!");
    return 0;
}

char *itobs(int n, char *ps) {
    int i;
    // 得到二进制字符数组的长度
    static int size = 8 * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1) {
        // 每次右移一位，并将该值转换为字符串存入数组元素中
        ps[i] = (01 & n) + '0';
    }
    // 字符数组最后一个位置是空字符
    ps[size] = '\0';

    return ps;
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