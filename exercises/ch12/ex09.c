//
// Created by HRF on 2021/11/14.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define LEN 80

int main(void) {
    int n_word;
    char ** words;
    int i;
    char word_temp[LEN];

    printf("How many words do you wish to enter?");
    scanf("%d", &n_word);

    words = (char **) malloc(n_word * sizeof(char *));
    printf("Enter %d words now:\n", n_word);
    for (i = 0; i < n_word; i++) {
        scanf("%s", word_temp);
        int length = strlen(word_temp);
        words[i] = (char *) malloc((length + 1) * sizeof(char));
        strcpy(words[i], word_temp);
    }

    printf("Here are your words:\n");
    for (i = 0; i < n_word; i++) {
        printf("%s\n", words[i]);
    }

    for (i = 0; i < n_word; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}