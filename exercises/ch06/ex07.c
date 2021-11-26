//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>
#include <string.h>

#define LEN 40

int main(void) {
    char word[LEN];
    int i, length;

    // 提示用户输入一个单词
    printf("Enter a word:");
    scanf("%s", word);

    // 得到单词的长度
    length = strlen(word) - 1;
    printf("The reverse of %s is ", word);
    // 逆序打印这个单词
    for (i = length; i >= 0; i--) {
        printf("%c", word[i]);
    }

    return 0;
}