//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    long upper_count = 0;
    long lower_count = 0;
    long other_count = 0;

    while ((ch = getchar()) != '&'){
        if (isupper(ch))
            upper_count++;
        else if (islower(ch))
            lower_count++;
        else
            other_count++;
    }

    printf("%ld uppercase characters read\n", upper_count);
    printf("%ld lowercase characters read\n", lower_count);
    printf("%ld other characters read\n", other_count);

    return 0;
}
