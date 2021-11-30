//
// Created by HRF on 2021/11/10.
//
#include <stdio.h>
#include <string.h>

#define LEN 80

char *my_strchr(char *input, char ch);
char *s_gets(char *st, int n);

int main(void) {
    char input[LEN];
    char *loc;
    char ch;

    // 提示用户输入字符串
    printf("Please enter a string:\n");
    while (s_gets(input, LEN) != NULL && input[0] != '\0') {
        // 提示用户要查找的字符
        printf("Please enter a character you want to find:");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        // 返回找到的位置
        loc = my_strchr(input, ch);
        if (loc) {
            // 打印结果
            printf("the point of %c in \"%s\" is %p.\n", ch, input, loc);
        } else {
            printf("Not found %c in %s.\n", ch, input);
        }
        printf("Please enter next string (empty line to quit):\n");
    }
    printf("Done!");

    return 0;
}

char * my_strchr(char input[], char ch) {
    int i;
    // 得到字符数组长度
    int length = strlen(input);
    for (i = 0; i < length; i++) {
        // 查找首次出现的位置
        if (input[i] == ch) {
            // 返回字符的指针
            return &input[i];
        }
    }
    return NULL;
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