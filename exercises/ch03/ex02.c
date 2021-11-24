//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    int ascii;

    // 提示输入一个ASCII码值
    printf("Enter an ASCII code:");
    scanf("%d", &ascii);
    // 打印输入的字符
    printf("%d is the ASCII code for %c.\n", ascii, ascii);
    return 0;
}

