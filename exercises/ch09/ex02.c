//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

void chline(int ch, int i, int j);

int main(void) {
    int ch;
    int i, j;
    // 提示用户输入一个字符
    printf("Enter a character:");
    while ((ch = getchar()) != '\n') {
        // 提示用户输入两个整数
        printf("Enter two integers:");
        if (scanf("%d %d", &i, &j) != 2)
            break;
        // 调用函数，打印j行i列
        chline(ch, i, j);
        while (getchar() != '\n')
            continue;
        printf("Enter another character (a newline to quit):");
    }

    printf("Bye.\n");
    return 0;
}

void chline(int ch, int i, int j) {
    int row, col;

    // 使用两个for循环，打印指定字符
    for (row = 0; row < j; row++) {
        for (col = 0; col < i; col++)
            putchar(ch);
        putchar('\n');
    }
}