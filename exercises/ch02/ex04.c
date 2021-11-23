//
// Created by HRF on 2021/10/26.
//
#include <stdio.h>

void jolly(void);
void deny(void);

int main(void){
    jolly();
    jolly();
    jolly();
    deny();
    return 0;
}

/**
 * 用于打印前3条信息
 */
void jolly(void){
    printf("For he's a jolly good fellow!\n");
}

/**
 * 用于打印最后一条信息
 */
void deny(void){
    printf("Which nobody can deny!");
}