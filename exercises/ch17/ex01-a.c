//
// Created by HRF on 2021/11/23.
//
/* films2.c -- using a linked list of structures */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct film {
    // 电影名称
    char title[TSIZE];
    // 评分
    int rating;
    // 指向链表中的下一个结构
    struct film *next;
    // 指向链表中的前一个结构
    struct film *prev;
};

char *s_gets(char *st, int n);

/*
 * input movie:
 * Spirited Away, 9
 * The Duelists, 8
 * Devil Dog: The Mound of Hound, 1
 */
int main(void) {
    struct film *head = NULL;
    // 创建前序结构指针和当前结构指针
    struct film *prev, *current;
    char input[TSIZE];

    // 收集并存储信息
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL) {
            head = current;
            head->prev = NULL;
        } else {
            // 前一个节点的next指针，指向当前节点
            prev->next = current;
            // 当前指针的prev指针，指向前一个节点
            current->prev = prev;
        }

        current->next = NULL;
        // 给电影名称赋值
        strcpy(current->title, input);
        // 提示用户输入评分
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        // 将指针移动到下一个
        prev = current;
    }

    // 正序显示电影信息
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

    // 采用双向链表，逆序显示电影列表
    if (head != NULL) {
        printf("\nHere is the movie list in reverse order:\n");
        current = prev;
        while (current != NULL) {
            printf("Movie: %s  Rating: %d\n",
                   current->title, current->rating);
            // 向前序节点移动
            current = current->prev;
        }
    }

    current = head;
    while (current != NULL) {
        head = current->next;
        free(current);
        current = head;
    }

    printf("Bye!\n");

    return 0;
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

