//
// Created by HRF on 2021/10/31.
//
#include "stdio.h"
int main(void){
    float download_speed, file_size;

    printf("Enter a number of download speed:");
    scanf("%f", &download_speed);
    printf("Enter a size of file:");
    scanf("%f", &file_size);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", download_speed, file_size);
    printf("downloads in %.2f second.\n", file_size * 8 / download_speed);
    return 0;
}
