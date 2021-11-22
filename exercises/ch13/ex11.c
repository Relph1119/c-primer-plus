//
// Created by HRF on 2021/11/15.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SLEN 256

// ex11.exe The exercises/ch13/files/wordy
int main(int argc, char *argv[]) {
    FILE * fp;
    char line_content[SLEN];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Can not open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line_content, SLEN, fp) != NULL) {
        if (strstr(line_content, argv[1]) != NULL)
            fputs(line_content, stdout);
    }

    if (fclose(fp) != 0) {
        fprintf(stderr, "Could not close file %s\n", argv[1]);
    }

    return 0;
}