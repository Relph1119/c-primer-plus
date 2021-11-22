//
// Created by HRF on 2021/11/16.
//
#include "stdio.h"
#define SLEN 5
struct person_name {
    char first_name[20];
    char mid_name[20];
    char last_name[20];
};

struct person {
    char nino[20];
    struct person_name name;
};
void print_person_info(struct person * p);

int main(void) {
    struct person p[SLEN] = {
            {"302039823", {"Dribble",  "Mill",   "FLossie"}},
            {"302039824", {"John",     "Stuart", "Mill"}},
            {"302039285", {"Allen",    "Aden",   "Henry"}},
            {"302039286", {"Linda",  "Jane",   "Smith"}},
            {"302039287", {"Margaret", "",       "Smith"}}
    };
    for (int i = 0; i < SLEN; i++) {
        print_person_info(&p[i]);
    }
    return 0;
}

void print_person_info(struct person * p) {
    printf("%s, %s", p->name.first_name, p->name.last_name);
    if (p->name.mid_name[0] != '\0') {
        printf( " %c.", p->name.mid_name[0]);
    }
    printf(" -- %s \n", p->nino);
}