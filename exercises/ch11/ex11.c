//
// Created by HRF on 2021/11/11.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 81
#define LIM 4

void menu(void);
int get_first(void);
char *s_gets(char *st, int n);
void print_strings(char * str[], int n);
void print_sort_by_ascii(char * str[], int n);
void print_sort_by_length(char * str[], int n);
void print_sort_by_first_word_length(char * str[], int n);
int get_first_word_length(char * str);

int main(void) {
    int choice;
//    char input[LIM][SIZE] = {"O that I was where I would be,",
//                             "The would I be where I am not;",
//                             "But where I am I must be,",
//                             "And where I would be I can not."};
    char input[LIM][SIZE];
    int ct = 0;
    char *ptstr[LIM];

    printf("Input upt to %d lines. To stop, press the Enter key at a line's start.\n", LIM);
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0') {
        ptstr[ct] = input[ct];
        ct++;
    }

    menu();
    while ((choice = get_first()) != 'q') {
        if (choice == '\n')
            continue;

        choice = tolower(choice);

        switch (choice) {
            case 'a':
                print_strings(ptstr, LIM);
                break;
            case 'b':
                print_sort_by_ascii(ptstr, LIM);
                break;
            case 'c':
                print_sort_by_length(ptstr, LIM);
                break;
            case 'd':
                print_sort_by_first_word_length(ptstr, LIM);
                break;
            default:
                printf("Please enter a, b, c, d, or q.\n");
                menu();
                continue;
        }
        menu();
    }

    return 0;
}

void menu(void) {
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the operation of strings :\n");
    printf("a) print string lists         b) print order by ascii\n");
    printf("c) print by string length     d) print by the first word's length\n");
    printf("q) quit\n");
    printf("*****************************************************************\n");
}

void print_strings(char * str[], int n) {
    printf("The input string lists are:\n");
    int i;
    for (i = 0; i < n; i++) {
        puts(str[i]);
    }
    puts("\n");
}

void print_sort_by_ascii(char * str[], int n) {
    printf("The input string lists order by ascii are:\n");
    int top, seek;
    char * temp;
    for(top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (strcmp(str[top], str[seek]) > 0) {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
        }
    }

    for (top = 0; top < n; top++) {
        puts(str[top]);
    }
    puts("\n");
}

void print_sort_by_length(char * str[], int n) {
    printf("The input string lists order by length are:\n");
    int top, seek;
    char * temp;
    for(top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (strlen(str[top]) > strlen(str[seek])) {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
        }
    }

    for (top = 0; top < n; top++) {
        puts(str[top]);
    }
    puts("\n");
}

void print_sort_by_first_word_length(char * str[], int n) {
    printf("The input string lists order by length are:\n");
    int top, seek;
    char * temp;
    for(top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (get_first_word_length(str[top]) > get_first_word_length(str[seek])) {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
        }
    }

    for (top = 0; top < n; top++) {
        puts(str[top]);
    }
    puts("\n");
}

int get_first(void) {
    int ch;

    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

int get_first_word_length(char * str) {
    int ct = 0;
    bool inword = false;

    while (*str) {
        if(isspace(*str) && inword)
            break;
        else {
            ct++;
            inword = true;
        }
        *str++;
    }
    return ct;
}