//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#define MAX_COUNT 10
void foo(void);
// 使用文件作用域，内部链接
static int count = 0;

int main(void) {
    int i;
    // 循环调用foo函数
    for (i = 0; i < MAX_COUNT; i++) {
        foo();
        // 打印函数调用信息
        printf("The foo function is called %d times.\n", count);
    }

    return 0;
}

void foo(void) {
    printf("The function called.\n");
    // 计算函数被调用次数
    count++;
}