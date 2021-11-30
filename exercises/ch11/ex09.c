//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <string.h>

#define LEN 80

char *s_gets(char *st, int n);

// 字符串逆序
void reverse(char str[]);

int main(void) {
    char input[LEN];

    // 提示用户输入字符串
    printf("Please enter a string:\n");
    while (s_gets(input, LEN) && input[0] != '\0') {
        // 将字符串逆序
        reverse(input);
        printf("The revert string: %s\n", input);
        printf("Please enter next string (empty line to quit):\n");
    }
    printf("Done!");
    return 0;
}

void reverse(char str[]) {
    // 得到字符串的长度
    int length = strlen(str);
    int i;
    char temp;
    // 通过for循环，将对应位置的字符交换，达到逆序的目的
    for (i = 0; i < (length / 2); i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
