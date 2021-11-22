//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define SIZE 5

typedef struct names names;
struct names {
    char first[LEN];
    char last[LEN];
};

void show_array(const struct names arr[], int n);

int mycomp(const void *p1, const void *p2);

int main(void) {
    struct names inputs[SIZE] = {{"Mack",    "Zackles"},
                                 {"Kindra",  "Schlagmeyer"},
                                 {"Filmore", "Walletz"},
                                 {"Buster",  "Downsize"},
                                 {"Stephen", "Prata"}};
    puts("Input list:");
    show_array(inputs, SIZE);
    qsort(inputs, SIZE, sizeof(names), mycomp);
    puts("\nSorted list:");
    show_array(inputs, SIZE);
    return 0;
}

void show_array(const struct names arr[], int n) {
    for (int i = 0; i < n; i++){
        printf("Stuff No %d %s %s\n", i+1, arr[i].first, arr[i].last);
    }
}

int mycomp(const void *p1, const void *p2) {
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;

    int res;
    res = strcmp(ps1->last, ps2->last);
    if (res != 0) {
        return res;
    } else {
        return strcmp(ps1->first, ps2->first);
    }
}
