//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void) {
    int count, sum;
    int n;

    // 提示用户输入一个求和上限值
    printf("Enter the upper limit:");
    scanf("%d", &n);

    count = 0;
    sum = 0;
    // 进行迭代求和
    while (count++ < n)
        sum += count;
    // 打印求和结果
    printf("sum = %d\n", sum);
    return 0;
}