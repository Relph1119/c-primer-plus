//
// Created by HRF on 2021/11/23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

#define SLEN 81

char menu(void);

char *s_gets(char *st, int n);
void show_words(const Tree * ptree);
void print_item(Item item);
void find_word(const Tree * ptree);
void process_word(char *word, int n);

int main(void) {
    Tree wordCountTree;
    char choice;
    FILE *fp;
    char file_name[SLEN];
    char word[SLEN];
    Item entry;

    printf("Enter the name of file to be processed:");
    // input exercises/ch17/ex07/wordy
    s_gets(file_name, SLEN);
    if ((fp = fopen(file_name, "r")) == 0) {
        printf("Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&wordCountTree);
    while (fscanf(fp, "%s", word) == 1 && !TreeIsFull(&wordCountTree)) {
        process_word(word, strlen(word));
        strcpy(entry.word, word);
        AddItem(&entry, &wordCountTree);
    }

    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 's':
                show_words(&wordCountTree);
                break;
            case 'f':
                find_word(&wordCountTree);
                break;
            default:
                printf("Error choice!\n");
        }
    }

    if (fclose(fp) == 0) {
        printf("Can't close file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    return 0;
}

void process_word(char *word, int n) {
    int i;
    for (i = 0; i < n; i++) {
        word[i] = tolower(word[i]);
        if (ispunct(word[i])) {
            word[i] = '\0';
            break;
        }
    }
}

void find_word(const Tree * ptree) {
    char word[SLEN];
    Item entry;
    const Item * pi;

    printf("Enter a word to find:");
    s_gets(word, SLEN);
    strcpy(entry.word, word);
    pi = WhereInTree(&entry, ptree);
    if (pi == NULL) {
        printf("%s is not in the list.\n", word);
    } else {
        printf("%s appears %d times.\n", word, pi->count);
    }
}

void show_words(const Tree * ptree) {
    printf("Here is the word list:\n");
    if (TreeIsEmpty(ptree)) {
        printf("No entries!\n");
    } else {
        Traverse(ptree, print_item);
    }
}

void print_item(Item item) {
    printf("%s: %3d\n", item.word, item.count);
}

char menu(void) {
    int ch;

    printf("Enter the letter corresponding to your choice:\n");
    printf("s) show word list      f) find a word\n");
    printf("q) quit\n");

    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n')
            continue;

        ch = tolower(ch);
        if (strchr("sfq", ch) == NULL) {
            printf("Please enter an s, f or q:");
        } else {
            break;
        }
    }

    if (ch == EOF) {
        ch = 'q';
    }

    return (char) ch;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
