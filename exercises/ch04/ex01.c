//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
int main(void){
    char first_name[40];
    char last_name[40];

    // 提示用户输入名
    printf("Enter your first name:");
    scanf("%s", first_name);
    // 提示用户输入姓
    printf("Enter your last name:");
    scanf("%s", last_name);
    // 打印“名，姓”
    printf("%s, %s\n", first_name, last_name);
    return 0;
}

