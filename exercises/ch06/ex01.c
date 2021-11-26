//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

// 定义元素个数
#define SIZE 26

int main(void) {
    // 创建一个包含26个元素的数组
    int letters[SIZE];
    int i;

    // 使用for循环存储26个小写字母
    for (i = 0; i < SIZE; i++)
        letters[i] = 'a' + i;

    // 使用for循环打印数组的所有内容
    for (i = 0; i < SIZE; i++)
        printf("%c", letters[i]);

    printf("\n");
    return 0;
}
