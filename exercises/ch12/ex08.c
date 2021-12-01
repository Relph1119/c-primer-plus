//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>

// 创建数组
int *make_array(int elem, int val);

// 显示数组内容
void show_array(const int ar[], int n);

int main(void) {
    // 数组指针
    int *pa;
    int size;
    int value;

    // 提示用户输入数组长度
    printf("Enter the number of elements:");
    while (scanf("%d", &size) == 1 && size > 0) {
        // 提示用户输入要初始化数组的指定的值
        printf("Enter the initialization value:");
        scanf("%d", &value);
        // 创建数组
        pa = make_array(size, value);
        if (pa) {
            // 显示数组内容
            show_array(pa, size);
            // 释放指针
            free(pa);
        }
        printf("Enter the number of elementes (<1 to quit):");
    }
    printf("Done.\n");
    return 0;
}

int *make_array(int elem, int val) {
    int *ar;
    int i;
    ar = (int *) malloc(elem * sizeof(int));
    for (i = 0; i < elem; i++) {
        // 使用数组形式进行赋值初始化
        ar[i] = val;
    }
    return ar;
}

void show_array(const int ar[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        // 每行打印8个数据，最后输入换行符
        printf("%d%s", ar[i], (i + 1) % 8 == 0 ? "\n" : " ");
    }
    putchar('\n');
}
