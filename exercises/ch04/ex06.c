//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    char first_name[40];
    char last_name[40];

    // 提示用户输入名
    printf("Enter your first name:");
    scanf("%s", first_name);
    // 提示用户输入姓
    printf("Enter your last name:");
    scanf("%s", last_name);
    // 打印用户输入的名和姓
    printf("%s %s\n", first_name, last_name);
    // 打印名和姓的字母数，并与相应的名和姓的结尾对齐
    printf("%*i %*i\n", strlen(first_name), strlen(first_name), strlen(last_name), strlen(last_name));
    // 打印用户输入的名和姓
    printf("%s %s\n", first_name, last_name);
    // 打印名和姓的字母数，并与相应的名和姓的开头对齐
    printf("%-*i %-*i\n", strlen(first_name), strlen(first_name), strlen(last_name), strlen(last_name));
    return 0;
}