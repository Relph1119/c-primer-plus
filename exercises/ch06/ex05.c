//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

void print_blank(int num);
void print_letter_asc(int num);
void print_letter_desc(int num);

int main(void) {
    char letter;

    printf("Enter a letter(A...Z):");
    scanf("%c", &letter);
    // 计算要打印的行数
    int count = letter - 'A' + 1;
    for (int i = 0; i < count; i++) {
        // 打印空格
        print_blank(count - i - 1);
        // 正序打印字符，从1开始
        print_letter_asc(i + 1);
        // 逆序打印字符，从0开始
        print_letter_desc(i);
        printf("\n");
    }

    return 0;
}

void print_blank(int num) {
    for (int i = 0; i < num; i++) {
        printf(" ");
    }
}

void print_letter_asc(int num) {
    char c = 'A';
    // 递增打印
    for (int i = 0; i < num; i++, c++) {
        printf("%c", c);
    }
}

void print_letter_desc(int num) {
    // 逆序打印的第一个字母
    int c = 'A' + num - 1;
    // 递减打印
    for (int i = 0; i < num; i++, c--) {
        printf("%c", c);
    }
}