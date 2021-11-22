//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '&'

int main(void) {
    int ch;
    long n_chars = 0L;
    int n_words = 0;
    bool in_word = true;

    while ((ch = getchar()) != STOP) {
        if (isalpha(ch))
            n_chars++;

        if (!isspace(ch) && !in_word) {
            in_word = true;
            n_words++;
        }
        if (isspace(ch) && in_word)
            in_word = false;
    }

    printf("The average number of letters in a word are %.2f", (double) n_chars / n_words);

    return 0;
}
