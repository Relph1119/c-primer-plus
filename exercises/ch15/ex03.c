//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <limits.h>

// 将十进制数转换为二进制字符串
char *itobs(int n, char *ps);
//
int onbits(int n);

int main(void) {
    int value;
    // 获得二进制字符数组的长度，最后一位为空字符
    static int SLEN = CHAR_BIT * sizeof(int) + 1;

    char bstr[SLEN];

    // 提示用户输入一个整数
    printf("Enter an integer:");
    while (scanf("%d", &value)) {
        // 打印打开位的数量
        printf("%d (%s) has %d bit(s) on.\n", value, itobs(value, bstr), onbits(value));
        printf("Enter next integer (q to quit):");
    }

    printf("Done.\n");
    return 0;
}

int onbits(int n) {
    // 获得二进制字符数组的长度
    static const int size = CHAR_BIT * sizeof(int);
    int count = 0;
    int i;

    for (i = 0; i < size; i++, n >>= 1) {
        // 使用&符号判断打开位
        if ((1 & n) == 1) {
            // 统计打开位的个数
            count++;
        }
    }
    return count;
}

char *itobs(int n, char *ps) {
    int i;
    // 得到二进制字符数组的长度
    static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1) {
        // 每次右移一位，并将该值转换为字符串存入数组元素中
        ps[i] = (01 & n) + '0';
    }
    // 字符数组最后一个位置是空字符
    ps[size] = '\0';

    return ps;
}