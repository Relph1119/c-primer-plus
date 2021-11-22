//
// Created by HRF on 2021/11/11.
//
#include <stdio.h>

int main(int argc, char **argv) {
    int i;
    for (i = argc - 1; i > 0; i--) {
        if (i == 0) {
            printf("\n");
        } else {
            printf("%s ", argv[i]);
        }

    }
    return 0;
}