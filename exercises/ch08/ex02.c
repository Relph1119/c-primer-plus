//
// Created by HRF on 2021/11/4.
//
#include "stdio.h"

int main(void) {
    int ch;
    int count = 1;

    while ((ch = getchar()) != '&') {
        if (ch == '\t') {
            printf("\\t-%d", ch);
            printf(" ");
        } else if(ch == '\n') {
            printf("\\n-%d", ch);
            printf("\n");
        } else if(count % 10 == 0){
            printf("%c-%d", ch, ch);
            printf("\n");
        } else {
            printf("%c-%d", ch, ch);
            printf(" ");
        }
        count++;
    }

    return 0;
}