//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include "pe12-3a.h"

int main(void) {
    int mode;
    double distance, fuel;

    // 提示用户输入模式
    printf("Enter 0 for metric mode, 1 for US mode:");
    scanf("%d", &mode);

    while (mode >= 0) {
        // 设置模式
        set_mode(&mode);
        // 根据用户输入的模式提示用户输入相应数据
        get_info(mode, &distance, &fuel);
        // 根据设置的模式计算并显示油耗
        show_info(mode, distance, fuel);
        // 再次提示用户输入模式
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit):");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}
