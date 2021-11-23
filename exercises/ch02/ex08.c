//
// Created by HRF on 2021/10/26.
//
#include <stdio.h>

void one_three(void);
void two(void);

int main(void){
    printf("starting now;\n");
    one_three();
    printf("done!\n");
    return 0;
}

void one_three(void){
    // 打印one
    printf("one\n");
    // 调用函数tow()
    two();
    // 打印three
    printf("three\n");
}

void two(void){
    // 打印tow
    printf("two\n");
}
