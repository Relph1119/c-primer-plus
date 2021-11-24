//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>

int main(void) {
    float height;
    char name[40];
    // 提示用户输入身高
    printf("Enter your height(in):");
    scanf("%f", &height);
    // 提示用户输入姓名
    printf("Enter your name:");
    scanf("%s", name);
    // 显示用户输入的信息
    printf("%s, you are %.3f feet tall.\n", name, height / 12.0);

    return 0;
}