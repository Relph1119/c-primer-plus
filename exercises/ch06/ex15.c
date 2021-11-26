//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>
#include <string.h>

#define SIZE 255

int main(void) {
    char data[SIZE];
    int i = 0, length;

    // 提示用户输入一行字符
    printf("Enter the char in a line:\n");
    do {
        // 循环读取用户输入的字符，保存到字符数组中，直到输入换行符
        scanf("%c", &data[i]);
    } while (data[i++] != '\n');

    // 打印倒序的内容
    printf("The reverse char of the data:\n");
    // 删除数组中的最后一个字符（即换行符）
    length = strlen(data) - 2;
    for (i = length; i >= 0; i--) {
        printf("%c", data[i]);
    }

    return 0;
}
