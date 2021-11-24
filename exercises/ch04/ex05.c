//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>

int main(void) {
    float download_speed, file_size;
    //输入下载速度
    printf("Enter a number of download speed(Mb/s):");
    scanf("%f", &download_speed);
    // 输入文件大小
    printf("Enter a size of file(MB):");
    scanf("%f", &file_size);
    // 打印信息
    printf("\nAt %.2f megabits per second, a file of %.2f megabytes\n", download_speed, file_size);
    // 计算并打印下载时间
    printf("downloads in %.2f second.\n", file_size * 8 / download_speed);

    return 0;
}
