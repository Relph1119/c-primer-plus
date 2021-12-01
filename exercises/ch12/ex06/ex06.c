//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "rand.h"
// 随机数个数
#define SIZE 1000
// 打印结果
void print_count(const int arr[]);
// 初始化数组
void init_array(int *arr);

int main(void) {
    int i, n, seed;
    // 使用数组记录每个数的出现次数
    int arr[11];

    // 使用ANSI C的rand()和srand()函数
    printf("Use ANSI C rand function and srand function.");
    seed = 0;
    while (seed < 10) {
        // 设置种子
        srand(seed);
        // 初始化数组，每个数的出现次数都初始化为0
        init_array(arr);
        for (i = 0; i < SIZE; i++) {
            // 生成随机数
            n = rand() % 10 + 1;
            // 记录次数
            arr[n]++;
        }
        putchar('\n');
        // 打印每个数的出现次数
        printf("Seed %d, the number counts:\n", seed);
        print_count(arr);
        seed++;
    }

    // 使用本章自定义的rand()和srand()函数
    printf("\n\nUse Self-Defining rand1 function and srand1 function.");
    seed = 0;
    while (seed < 10) {
        srand1(seed);
        init_array(arr);
        for (i = 0; i < SIZE; i++) {
            n = rand1() % 10 + 1;
            arr[n]++;
        }
        putchar('\n');
        printf("Seed %d, the number counts:\n", seed);
        print_count(arr);
        seed++;
    }

    return 0;
}

void print_count(const int arr[]) {
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%5d ", i);
    }
    putchar('\n');
    for (i = 1; i <= 10; i++) {
        printf("%5d ", arr[i]);
    }
}

void init_array(int *arr) {
    int i;
    for (i = 0; i <= 10; i++) {
        arr[i] = 0;
    }
}