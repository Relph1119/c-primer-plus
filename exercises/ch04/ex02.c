//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[40];
    // 提示用户输入名字
    printf("Enter your name:");
    scanf("%s", name);
    // a. 打印名字，包括双引号
    printf("\"%s\"\n", name);
    // b. 在宽度为20的字段右端打印名字，包括双引号
    printf("\"%*s\"\n", 20, name);
    // c. 在宽度为20的字段左端打印名字，包括双引号
    printf("\"%-*s\"\n", 20, name);
    // d. 在比姓名宽度宽3的字段中打印名字
    printf("%*s\n", strlen(name) + 3, name);

    return 0;
}