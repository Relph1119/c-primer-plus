//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
void critic(int *u);

int main(void) {
    int units;

    // 提示用户输入磅数
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        // 判断用户输入的值
        critic(&units);
    printf("You must have looked it up!\n");

    return 0;
}

void critic(int *u) {
    printf("No luck, my friend. Try again.\n");
    // 继续猜测磅数
    scanf("%d", u);
}
