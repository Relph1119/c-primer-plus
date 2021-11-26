//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

#define SIZE 6

int main(void) {

    int count;
    // 打印的字母初始化为A
    char letter = 'A';
    for (count = 0; count < SIZE; count++) {
        // 每行需要打印的第一个字母
        letter += count;
        // 用于字母自增打印
        char temp = letter;
        for (int j = 0; j <= count; temp++, j++) {
            printf("%c", temp);
        }
        printf("\n");
    }

    return 0;
}