//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    long upper_count = 0;
    long lower_count = 0;
    long other_count = 0;

    printf("Please enter chars (& to quit):\n");
    // 当输入&字符停止
    while ((ch = getchar()) != '&'){
        if (isupper(ch))
            // 计算大写字母个数
            upper_count++;
        else if (islower(ch))
            // 计算小写字母个数
            lower_count++;
        else
            other_count++;
    }

    // 打印大写字母个数
    printf("\n%ld uppercase characters read\n", upper_count);
    // 打印小写字母个数
    printf("%ld lowercase characters read\n", lower_count);
    // 打印其他字符个数
    printf("%ld other characters read\n", other_count);

    return 0;
}
