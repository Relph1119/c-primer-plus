//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>
#include <string.h>

#define LEN 80

char *s_gets(char *st, int n);

char *mystrncpy(char *str1, const char *str2, int num);

int main(void) {
    char target[LEN] = "";
    char source[LEN];
    int num;

    // 提示用户输入字符串
    printf("Please enter string:\n");
    while (s_gets(source, LEN) && source[0] != '\0') {
        int length = strlen(source);
        // 输入要拷贝的字符数
        printf("Please enter a number to copy characters (1 to %d):", length);
        scanf("%d", &num);
        while (getchar() != '\n')
            continue;

        mystrncpy(target, source, num);
        // 打印拷贝结果
        printf("source string: %s\n", source);
        printf("target string: %s\n", target);

        printf("Please enter next string (empty line to quit):\n");
    }
    printf("Done!");

    return 0;
}

char *mystrncpy(char *str1, const char *str2, int n) {
    int i;

    // 进行n次for循环的拷贝
    for (i = 0; i < n; i++) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    // 添加空字符
    *str1 = '\0';
    return str1;
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