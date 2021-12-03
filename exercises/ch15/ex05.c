//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <limits.h>

// 将十进制数转换为二进制字符串
char *itobs(int n, char *ps);
// 循环左移
unsigned int rotate_l(unsigned int n, unsigned int b);

int main(void) {
    // 获得二进制字符数组的长度
    static const int SLEN = CHAR_BIT * sizeof(int) + 1;
    unsigned int value;
    unsigned int rot;
    unsigned int places;
    char bstr1[SLEN];
    char bstr2[SLEN];

    // 提示用户输入一个整数
    printf("Enter an integer (q to quit):");
    while (scanf("%ud", &value)) {
        // 提示用户输入左移的位置
        printf("Enter the number of bits to be rotated:\n");
        if (scanf("%ul", &places) != 1) {
            break;
        }
        // 进行循环左移
        rot = rotate_l(value, places);
        // 将十进制数转换为二进制字符数
        itobs(value, bstr1);
        itobs(rot, bstr2);
        printf("Decimal: %u rotated is %u.\n", value, rot);
        printf("Binary: %s rotated is %s.\n", bstr1, bstr2);
        printf("Enter next integer:");
    }

    return 0;
}

unsigned int rotate_l(unsigned int n, unsigned int b) {
    static const int size = CHAR_BIT * sizeof(int);
    unsigned int overflow;

    // 计算size的余数
    b %= size;
    // 得到左端移出的位
    overflow = n >> (size - b);
    // 进行高阶和低阶的位拼接
    return (n << b) | overflow;
}

char *itobs(int n, char *ps) {
    int i;
    // 获得二进制字符数组的长度
    static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1) {
        // 每次右移一位，并将该值转换为字符串存入数组元素中
        ps[i] = (01 & n) + '0';
    }
    // 字符数组最后一个位置是空字符
    ps[size] = '\0';

    return ps;
}