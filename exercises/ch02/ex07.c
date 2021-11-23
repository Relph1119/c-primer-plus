//
// Created by HRF on 2021/10/26.
//
#include <stdio.h>

void smile(void);

int main(void){
    // 打印三次Smile!
    smile();
    smile();
    smile();
    printf("\n");
    // 打印两次Smile!
    smile();
    smile();
    printf("\n");
    // 打印一次Smile!
    smile();
    printf("\n");
    return 0;
}

/**
 * 用于打印Smile!
 */
void smile(void){
    printf("Smile!");
}
