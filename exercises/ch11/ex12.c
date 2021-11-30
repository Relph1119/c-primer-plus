//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
// 使用&作为停止符
#define STOP '&'

int main(void) {
    int ch;
    // 小写字母数
    int lower_ct = 0;
    // 大写字母数
    int upper_ct = 0;
    // 数字字符数
    int dig_ct = 0;
    // 单词数
    int n_words = 0;
    // 标点符号数
    int punc_ct = 0;
    bool inword = false;

    // 提示用户输入
    printf("Please enter text to be analyzed (& to quit):\n");

    while ((ch = getchar()) != STOP) {

        if (islower(ch))
            // 当遇到小写字母，记录小写字母数
            lower_ct++;
        else if (isupper(ch))
            // 当遇到大写字母，记录大写字母数
            upper_ct++;
        else if (isdigit(ch))
            // 当遇到数字字符，记录数字字符数
            dig_ct++;
        else if (ispunct(ch))
            // 当遇到标点符号，记录标点符号数
            punc_ct++;
        if (!isspace(ch) && !inword) {
            // 当没有遇到空格，且不是单词时，记录单词数，并修改单词标识为true
            inword = true;
            n_words++;
        }
        // 当遇到空格，表示单词已经结束，修改单词标识为false
        if (isspace(ch) && inword)
            inword = false;
    }
    // 打印结果
    printf("nwords = %d, lowercase = %d, uppercase = %d, "
           "digits = %d, punctuation = %d\n",
           n_words, lower_ct, upper_ct, dig_ct, punc_ct);

    return 0;
}