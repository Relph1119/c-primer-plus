//
// Created by HRF on 2021/11/10.
//
#include <stdio.h>

#define LEN 10
// 获取n个字符
char *get_n_char(char *str, int n);

int main(void) {
    char input[LEN];
    char *ret_val;
    int n = LEN - 1;

    printf("Please enter chars:\n");
    ret_val = get_n_char(input, n);
    if (ret_val == NULL) {
        puts("Input failed.");
    } else {
        printf("%d chars: ", n);
        puts(input);
    }
    puts("Done.");

    return 0;
}

char *get_n_char(char *str, int n) {
    int i;
    char ch;
    // for循环n次，取出n个字符，存储到str数组中
    for (i = 0; i < n; i++) {
        ch = getchar();
        if (ch != EOF)
            str[i] = ch;
        else
            break;
    }

    if (ch == EOF)
        return NULL;
    else {
        // 赋给str数组的最后一个元素为空字符
        str[i] = '\0';
        return str;
    }
}