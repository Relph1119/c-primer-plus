//
// Created by HRF on 2021/11/15.
//
#include "stdio.h"
#include "stdlib.h"

// ex02.exe exercises/ch13/files/eddy exercises/ch13/files/eddy.copy
int main(int argc, char *argv[]) {
    int byte;
    FILE * source_file;
    FILE * target_file;

    if (argc != 3) {
        printf("Usage: %s source_file target_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((source_file = fopen(argv[1], "rb")) == NULL) {
        printf("Could not open file %s for input\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((target_file = fopen(argv[2], "wb")) == NULL) {
        printf("Could not open file %s for output\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((byte = getc(source_file)) != EOF) {
        putc(byte, target_file);
    }

    if (fclose(source_file) != 0)
        printf("Could not close file %s\n", argv[1]);
    if (fclose(target_file) != 0)
        printf("Could not close file %s\n", argv[2]);

    return 0;
}
