//
// Created by HRF on 2021/10/31.
//
#include "stdio.h"
#include "string.h"
int main(void){
    char first_name[40];
    char last_name[40];

    printf("Enter your first name:");
    scanf_s("%s", first_name, 40);
    printf("Enter your last name:");
    scanf_s("%s", last_name, 40);
    printf("%s %s\n", first_name, last_name);
    printf("%*i %*i\n", strlen(first_name), strlen(first_name), strlen(last_name), strlen(last_name));
    printf("%s %s\n", first_name, last_name);
    printf("%-*i %-*i\n", strlen(first_name), strlen(first_name), strlen(last_name), strlen(last_name));
    return 0;
}