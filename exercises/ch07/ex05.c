//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    int ch;
    int count1 = 0;
    int count2 = 0;

    // 提示用户录入信息
    printf("Enter text to be analyzed (# to terminate):\n");
    // 读到#停止
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case '.':
                // 用感叹号替换句号
                putchar('!');
                count1++;
                break;
            case '!':
                // 用两个感叹号替换原来的感叹号
                putchar('!');
                putchar('!');
                count2++;
                break;
            default:
                putchar(ch);
        }
    }

    // 报告替换次数
    printf("\n%d replacement(s) of . with !\n", count1);
    printf("%d replacement(s) of ! with !!\n", count2);
    printf("Total replace %d times\n", count1 + count2);
    printf("Done\n");

    return 0;
}