//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>

int main(void) {
    // 初始朋友数量
    int friends = 5;
    // 第1周
    int weeks = 1;

    printf("The number of Dr Rabnud's friends:\n");
    printf("%5s %10s\n", "Week", "Friends");

    while (friends <= 150) {
        // 第n周少了n个朋友，剩下的朋友数量翻倍
        friends = (friends - weeks) * 2;
        // 打印每周的朋友数量
        printf("%5d %7d\n", weeks, friends);
        weeks++;
    }

    return 0;
}