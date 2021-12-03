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
extern void find_word(const Tree * pt);
void process_word(char *word, int n);

int main(void) {
    Tree word_tree;
    char choice;
    FILE *fp;
    char file_name[SLEN];
    Item temp;

    printf("Enter the name of file to be processed:");
    // input exercises/ch17/ex07/wordy
    s_gets(file_name, SLEN);
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    // 初始化二叉查找树
    InitializeTree(&word_tree);
    while (fscanf(fp, "%s", temp.word) == 1 && !TreeIsFull(&word_tree)) {
        process_word(temp.word, strlen(temp.word));
        temp.count = 1;
        AddItem(&temp, &word_tree);
    }

    // 关闭文件
    if (fclose(fp) != 0){
        printf("Can't close file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    // 提示用户选择一个选项
    printf("file is opened,what do you want to do:\n");
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 's':
                // 列出所有单词及其出现的次数
                show_words(&word_tree);
                break;
            case 'f':
                // 查找单词，并报告该单词在文件中出现的次数
                find_word(&word_tree);
                break;
            default:
                printf("Error choice!\n");
        }
    }

    puts("Bye!");
    DeleteAll(&word_tree);

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

void show_words(const Tree * ptree) {
    printf("Here is the word list:\n");
    if (TreeIsEmpty(ptree)) {
        printf("No entries!\n");
    } else {
        Traverse(ptree, print_item);
    }
}

void print_item(Item item) {
    // 打印单词及其出现的次数
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
