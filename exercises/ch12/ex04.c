//
// Created by HRF on 2021/11/14.
//
#include "stdio.h"
#define MAX_COUNT 10
void foo(void);
static int count = 0;

int main(void) {

    int i;
    for (i = 0; i < MAX_COUNT; i++) {
        foo();
        printf("The foo function is called %d times.\n", count);
    }

    return 0;
}

void foo(void) {
    extern int count;

    printf("The function called.\n");
    count++;
}