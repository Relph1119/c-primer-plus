/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* 局部函数原型 */
static void CopyToNode(Item item, Node *pnode);

/* 接口函数 */

// 把链表设置为空
void InitializeList(List *plist) {
    plist->head = NULL;
    // 对尾指针设置为空
    plist->end = NULL;
}

// 如果链表为空，返回true
bool ListIsEmpty(const List *plist) {
    if (plist->head == NULL)
        return true;
    else
        return false;
}

// 如果链表已满，返回true
bool ListIsFull(const List *plist) {
    Node *pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

// 返回节点的数量
unsigned int ListItemCount(const List *plist) {
    unsigned int count = 0;
    Node *pnode = plist->head;

    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

// 创建存储项的节点，并将其添加至由plist指向的链表末尾（较慢的实现）
bool AddItem(Item item, List *plist) {
    Node *pnew;
    Node *scan = plist->head;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) {
        // 空链表，设置头指针和尾指针都为pnew
        plist->head = pnew;
        plist->end = pnew;
    } else {
        // 把pnew添加到链表的末尾，并设置尾指针
        plist->end->next = pnew;
        plist->end = pnew;
    }

    return true;
}

// 访问每个节点并执行pfun指向的函数
void Traverse(const List *plist, void (*pfun)(Item item)) {
    Node *pnode = plist->head;

    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

// 释放由malloc()分配的内存，设置链表指针为NULL
void EmptyTheList(List *plist) {
    Node *psave;

    while (plist->head != NULL) {
        psave = plist->head->next; /* save address of next node */
        free(plist->head);           /* free current node         */
        plist->head = psave;         /* advance to next node      */
    }
}

// 把一个项拷贝到节点中
static void CopyToNode(Item item, Node *pnode) {
    pnode->item = item;  /* structure copy */
}
