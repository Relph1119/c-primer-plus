//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

void ch_line_row(int ch, int cols, int rows);

int main(void) {
    int ch;
    int cols, rows;

    // 提示用户输入一个字符
    printf("Enter a character:");
    while ((ch = getchar()) != '\n') {
        printf("Enter two integers:");
        if (scanf("%d %d", &cols, &rows) != 2)
            break;
        // 调用函数打印
        ch_line_row(ch, cols, rows);
        while (getchar() != '\n')
            continue;
        printf("\nEnter next character (a newline to  to quit):");
    }

    printf("Bye!");
    return 0;
}

void ch_line_row(int ch, int cols, int rows) {
    int i, j;

    // 使用两个for循环，打印指定字符
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            putchar(ch);
        putchar('\n');
    }
}