//
// Created by HRF on 2021/11/23.
//
#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

typedef char Item;
// 定义栈的上限
#define MAXSTACK 100

typedef struct stack {
    // 使用字符数组
    Item items[MAXSTACK];
    // 栈顶的位置
    int top;
} Stack;

// 初始化栈
void InitializeStack(Stack * ps);

// 确定栈是否已满
bool StackIsFull(const Stack * ps);

// 确定栈是否为空
bool StackIsEmpty(const Stack *ps);

// 确定栈的长度
int StackItemCount(const Stack * ps);

// 把项压入栈
bool Push(Item item, Stack * ps);

// 把项弹出栈
bool Pop(Item * pitem, Stack * ps);

// 清空栈
void EmptyTheStack(Stack * ps);

#endif
