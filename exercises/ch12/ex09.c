//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 80

int main(void) {
    // 单词个数
    int n_word;
    // 动态数组指针
    char **words;
    int i;
    // 临时char数组
    char word_temp[LEN];

    // 提示用户输入单词个数
    printf("How many words do you wish to enter?");
    scanf("%d", &n_word);

    // 创建动态数组
    words = (char **) malloc(n_word * sizeof(char *));
    // 提示用户输入单词
    printf("Enter %d words now:\n", n_word);
    for (i = 0; i < n_word; i++) {
        scanf("%s", word_temp);
        // 获取单词的长度
        int length = strlen(word_temp);
        // 动态分配每个指针的存储空间
        words[i] = (char *) malloc((length + 1) * sizeof(char));
        // 进行字符串拷贝
        strcpy(words[i], word_temp);
    }

    // 显示数组内容
    printf("\nHere are your words:\n");
    for (i = 0; i < n_word; i++) {
        printf("%s\n", words[i]);
    }

    // 释放动态数组的每个指针的空间
    for (i = 0; i < n_word; i++) {
        free(words[i]);
    }
    // 释放动态数组
    free(words);

    return 0;
}