//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <limits.h>
#include <string.h>

// 获得指定位置的位
int get_bit(int n, int pos);
// 将十进制数转换为二进制字符串
char *itobs(int n, char *ps);

int main(void) {
    int value;
    int pos;
    // 获得二进制字符数组的长度，最后一位为空字符
    static int SLEN = CHAR_BIT * sizeof(int) + 1;
    char bstr[SLEN];
    char indexs[3];

    // 提示用户输入一个整数
    printf("Enter a integer number:");
    while (scanf("%d", &value)) {
        // 提示用户输入一个位置
        printf("Enter a position:");
        scanf("%d", &pos);
        switch (pos) {
            case 1:
                strncpy(indexs, "st", 2);
                break;
            case 2:
                strncpy(indexs, "nd", 2);
                break;
            case 3:
                strncpy(indexs, "rd", 2);
                break;
            default:;
        }
        // 打印该位置的位
        printf("The %d%s position of %d (%s) is %d\n", pos, indexs, value, itobs(value, bstr), get_bit(value, pos));
        printf("Enter next integer number (q to quit):");
    }
    printf("Bye.");

    return 0;
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

int get_bit(int n, int pos) {
    // 获得二进制字符数组的长度
    static const int size = CHAR_BIT * sizeof(int) + 1;
    pos -= 1;
    // 对指定位置进行检查
    if (pos > size || pos < 0) {
        printf("Error position.\n");
        return -1;
    }
    // 将数右移指定位置，和1做&
    if (1 & (n >> pos)) {
        return 1;
    } else {
        return 0;
    }
}