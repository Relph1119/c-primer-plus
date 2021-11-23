//
// Created by HRF on 2021/11/23.
//
/* films2.c -- using a linked list of structures */
#include <stdio.h>
#include <stdlib.h>      /* has the malloc prototype      */
#include <string.h>      /* has the strcpy prototype      */

#define TSIZE    45      /* size of array to hold title   */

struct film {
    char title[TSIZE];
    int rating;
    struct film *next;  /* points to next struct in list */
};

char *s_gets(char *st, int n);

void show_reverse(const struct film *p_film);

/*
 * input movie:
 * Spirited Away, 9
 * The Duelists, 8
 * Devil Dog: The Mound of Hound, 1
 */
int main(void) {
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    /* Gather  and store information          */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)       /* first structure       */
            head = current;
        else                    /* subsequent structures */
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    /* Show list of movies                    */
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL) {
        printf("Movie: %s  Rating: %d\n",
               current->title, current->rating);
        current = current->next;
    }

    // 采用递归，逆序显示电影列表
    if (head != NULL) {
        printf("\nHere is the movie list in reverse order:\n");
        show_reverse(head);
    }

    /* Program done, so free allocated memory */
    current = head;
    while (current != NULL) {
        free(current);
        current = current->next;
    }


    return 0;
}

void show_reverse(const struct film *p_film) {
    if (p_film->next != NULL) {
        show_reverse(p_film->next);
    }
    printf("Movie: %s  Rating: %d\n", p_film->title, p_film->rating);
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
