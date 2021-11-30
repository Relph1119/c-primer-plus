//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

void to_base_n(int n, int base);

int main(void) {
    int number;
    int b;
    int status;

    // 提示用户输入一个整数
    printf("Enter an integer (q to quit):");
    while (scanf("%d", &number) == 1) {
        printf("Enter number base (2-10):");
        // 检查第2个参数是否在2~10范围内
        while ((status = scanf("%d", &b)) == 1 && (b < 2 || b > 10)) {
            printf("base should be in the range 2-10:");
        }
        if (status != 1)
            break;
        // 打印转换的进制数
        printf("%d Base %d equivalent: ", number, b);
        to_base_n(number, b);
        putchar('\n');
        printf("Enter an integer (q to quit):");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(int n, int base) {
    int r;

    // 计算余数
    r = n % base;
    if (n >= base)
        // 进行递归调用
        to_base_n(n / base, base);
    // 打印转换后的进制数
    putchar('0' + r);
}

