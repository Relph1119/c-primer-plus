//
// Created by HRF on 2021/11/15.
//
#include "stdio.h"
#include "stdlib.h"

// ex04.exe exercises/ch13/files/eddy exercises/ch13/files/eddy.copy
int main(int argc, char * argv[]) {
    int byte;
    FILE * source;
    int file_index;

    if (argc == 1) {
        printf("Usage: %s filename[s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (file_index = 1; file_index < argc; file_index++) {
        if ((source = fopen(argv[file_index], "r")) == NULL) {
            printf("Could not open file %s for input\n", argv[file_index]);
            continue;
        }
        printf("%s file content:\n", argv[file_index]);
        while ((byte = getc(source)) != EOF) {
            putchar(byte);
        }
        if (fclose(source) != 0) {
            printf("Could not close file %s\n", argv[file_index]);
        }
    }

    return 0;
}
