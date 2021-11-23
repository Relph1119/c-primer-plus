//
// Created by HRF on 2021/11/23.
//

#include "stack.h"

void InitializeStack(Stack *ps) {
    ps->top = 0;
}

bool StackIsFull(const Stack *ps) {
    if (ps->top == MAXSTACK) {
        return true;
    } else {
        return false;
    }
}

bool StackIsEmpty(const Stack *ps) {
    if (ps->top == 0) {
        return true;
    } else {
        return false;
    }
}

int StackItemCount(const Stack *ps) {
    return ps->top;
}

bool Push(Item item, Stack *ps) {
    if (ps->top == MAXSTACK) {
        return false;
    } else {
        ps->items[ps->top++] = item;
        return true;
    }
}

bool Pop(Item *pitem, Stack *ps) {
    if (ps->top == 0) {
        return false;
    } else {
        ps->top--;
        *pitem = ps->items[ps->top];
        return true;
    }
}

void EmptyTheStack(Stack *ps) {
    ps->top = 0;
}