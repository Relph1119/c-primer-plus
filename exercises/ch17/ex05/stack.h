//
// Created by HRF on 2021/11/23.
//

#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

typedef char Item;

#define MAXSTACK 100

typedef struct stack {
    Item items[MAXSTACK];
    int top;
} Stack;

void InitializeStack(Stack * ps);

bool StackIsFull(const Stack * ps);

bool StackIsEmpty(const Stack *ps);

int StackItemCount(const Stack * ps);

bool Push(Item item, Stack * ps);

bool Pop(Item * pitem, Stack * ps);

void EmptyTheStack(Stack * ps);

#endif
