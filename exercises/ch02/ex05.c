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
    ic();
    br();
    printf("\n");
    return 0;
}

void br(void){
    printf("Brazil, Russia");
}

void ic(void){
    printf("India, China\n");
}
