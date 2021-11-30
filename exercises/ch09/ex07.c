//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>
#include <ctype.h>

int locate(int ch);

int main(void) {
    int ch;

    // 提示用户输入一个字符
    printf("Enter a character:");
    while ((ch = getchar()) != '\n') {
        // 如果是字母，打印字母在字母表中的位置
        if (isalpha(ch)) {
            printf("The location of %c in alphabet is %d.\n", ch, locate(ch));
        }
        while (getchar() != '\n')
            continue;
        printf("Enter next character (a newline to quit):");
    }

    printf("Bye");
    return 0;
}

int locate(int ch) {
    // 如果不是字母，返回-1
    int index = -1;

    // 如果是字母
    if (isalpha(ch)) {
        // 将字符转成小写字母，然后减去第一个字母并加上1
        index = tolower(ch) - 'a' + 1;
    }
    return index;
}