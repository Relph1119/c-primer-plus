/* list.c -- functions supporting list operations */
#include "list.h"

/* 局部函数原型 */
static void CopyToNode(Item item, Node *pnode);

/* 接口函数 */

// 把链表设置为空
void InitializeList(List *plist) {
    // 初始化项数为0
    plist->items = 0;
}

// 如果链表为空，返回true
bool ListIsEmpty(const List *plist) {
    // 如果项数为0，返回true，否则返回false
    if (plist->items == 0)
        return true;
    else
        return false;
}

// 如果链表已满，返回true
bool ListIsFull(const List *plist) {
    bool full;
    // 如果项数等于MAXSIZE，返回true，否则返回false
    if (plist->items == MAXSIZE)
        full = true;
    else
        full = false;

    return full;
}

// 返回节点的数量
unsigned int ListItemCount(const List *plist) {
    // 返回项数
    return plist->items;
}

// 创建存储项的节点，并将其添加至由plist指向的链表末尾（较慢的实现）
bool AddItem(Item item, List *plist) {
    if (plist->items == MAXSIZE) {
        // 如果已满，返回false
        return false;
    } else {
        // 添加新项，项数加1，返回true
        plist->entries[plist->items] = item;
        plist->items++;
        return true;
    }
}

// 访问每个节点并执行pfun指向的函数
void Traverse(const List *plist, void (*pfun)(Item item)) {
    for (int i = 0; i < plist->items; i++) {
        (*pfun)(plist->entries[i]);
    }
}

// 释放由malloc()分配的内存，设置链表指针为NULL
void EmptyTheList(List *plist) {
    // 清空列表的项数
    plist->items = 0;
}
