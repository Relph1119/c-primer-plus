//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
int main(void){
    char first_name[40];
    char last_name[40];

    printf("Enter your first name:");
    scanf("%s", first_name);
    printf("Enter your last name:");
    scanf("%s", last_name);
    printf("%s, %s\n", last_name, first_name);
    return 0;
}

