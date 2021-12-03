//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40
#define SIZE 5

// 定义姓名结构
struct names {
    char first[LEN];
    char last[LEN];
};

void show_array(const struct names arr[], int n);

int mycomp(const void *p1, const void *p2);

int main(void) {
    struct names staff[SIZE] = {{"Mack",    "Zackles"},
                                {"Kindra",  "Schlagmeyer"},
                                {"Filmore", "Walletz"},
                                {"Buster",  "Downsize"},
                                {"Stephen", "Prata"}};
    // 打印员工列表
    puts("Staff list:");
    show_array(staff, SIZE);

    // 先按姓排列，如果同姓再按名排序
    qsort(staff, SIZE, sizeof(struct names), mycomp);

    // 显示排序后的列表
    puts("\nSorted list:");
    show_array(staff, SIZE);
    return 0;
}

void show_array(const struct names arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Stuff No %d %s %s\n", i + 1, arr[i].first, arr[i].last);
    }
}

int mycomp(const void *p1, const void *p2) {
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;

    int res;
    // 比较姓
    res = strcmp(ps1->last, ps2->last);
    if (res != 0) {
        return res;
    } else {
        // 如果同姓，则比较名
        return strcmp(ps1->first, ps2->first);
    }
}
