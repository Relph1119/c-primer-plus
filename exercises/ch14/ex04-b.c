//
// Created by HRF on 2021/11/16.
//
#include <stdio.h>
#define SLEN 5

struct person_name {
    // 名
    char first_name[20];
    // 中间名
    char mid_name[20];
    // 姓
    char last_name[20];
};

struct person {
    // 社会保险号
    char nino[20];
    struct person_name name;
};

void print_person_info(struct person p);

int main(void) {
    // 初始化person结构数组
    struct person p[SLEN] = {
            {"302039823", {"Dribble",  "Mill",   "FLossie"}},
            {"302039824", {"John",     "Stuart", "Mill"}},
            {"302039285", {"Allen",    "Aden",   "Henry"}},
            {"302039286", {"Linda",    "Jane",   "Smith"}},
            {"302039287", {"Margaret", "",       "Smith"}}
    };
    // 打印数组内容
    for (int i = 0; i < SLEN; i++) {
        // 传递结构的值
        print_person_info(p[i]);
    }

    return 0;
}

void print_person_info(struct person p) {
    // 按照指定格式打印person内容
    printf("%s, %s", p.name.first_name, p.name.last_name);
    // 如果有中间名，则打印
    if (p.name.mid_name[0] != '\0') {
        printf(" %c.", p.name.mid_name[0]);
    }
    printf(" -- %s \n", p.nino);
}
