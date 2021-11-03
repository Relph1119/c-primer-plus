//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"

int main(void){
    char ch;
    int space_count = 0;
    int newlines_count = 0;
    int other = 0;

    while ((ch = getchar()) != '#'){
        if (ch == ' ')
            space_count++;
        else if (ch == '\n')
            newlines_count++;
        else
            other++;
    }
    printf("spaces: %d, newlines: %d, others: %d", space_count, newlines_count, other);

    return 0;
}