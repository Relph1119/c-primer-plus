//
// Created by HRF on 2021/11/5.
//
#include <stdio.h>

unsigned long fibonacci(unsigned n);

int main(void) {
    unsigned n;

    // 提示用户输入一个值
    printf("Enter a number:");
    while (scanf("%u", &n) == 1) {
        // 返回该值的斐波那契数
        printf("The Fibonacci(%d) value is %lu.\n", n, fibonacci(n));
        printf("Enter next number (q to quit):");
    }

    return 0;
}

unsigned long fibonacci(unsigned n) {
    int m;
    // 当n为1或2时，返回1
    if (n == 1 || n == 2) {
        m = 1;
    } else {
        // 记录前面第一个值
        int prev = 1;
        // 前面第二个值
        int prev_prev = 1;
        int sum;
        int i;
        // 对当前值进行循环求前面第一个值和前面第二个值
        for (i = 3; i < n; i++) {
            // 计算前面第一个值
            sum = prev + prev_prev;
            // 计算前面第二个值
            prev_prev = prev;
            prev = sum;
        }
        // 计算最终结果
        m = prev + prev_prev;
    }
    return m;
}
