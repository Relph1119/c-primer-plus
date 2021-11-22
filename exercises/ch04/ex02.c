//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
#include <string.h>
int main(void){
    char name[40];
    printf("Enter your name:");
    scanf("%s", name);
    printf("\"%s\"\n", name);
    printf("\"%*s\"\n", 20, name);
    printf("\"%-*s\"\n", 20, name);
    printf("%*s\n", strlen(name) + 3, name);

    return 0;
}