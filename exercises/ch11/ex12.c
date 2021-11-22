//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int ch;
    int lower_ct = 0;
    int upper_ct = 0;
    int dig_ct = 0;
    int n_words = 0;
    int punc_ct = 0;
    bool inword = false;

    printf("Please enter text to be analyzed (& to quit):\n");
    while ((ch = getchar()) != '&') {
        if (islower(ch))
            lower_ct++;
        else if (isupper(ch))
            upper_ct++;
        else if (isdigit(ch))
            dig_ct++;
        else if (ispunct(ch))
            punc_ct++;
        if (!isspace(ch) && !inword) {
            inword = true;
            n_words++;
        }
        if (isspace(ch) && inword)
            inword = false;
    }
    printf("nwords = %d, lowercase = %d, uppercase = %d, "
           "digits = %d, punctuation = %d\n",
           n_words, lower_ct, upper_ct, dig_ct, punc_ct);

    return 0;
}