//
// Created by HRF on 2021/10/26.
//
#include <stdio.h>

void br(void);
void ic(void);

int main(void){
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();
    return 0;
}

/**
 * 用户打印"Brazil, Russia"
 */
void br(void){
    printf("Brazil, Russia");
}

/**
 * 用于打印“India, China”
 */
void ic(void){
    printf("India, China");
}
