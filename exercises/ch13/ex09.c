//
// Created by HRF on 2021/11/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 47
#define FILE_NAME "exercises/ch13/files/wordy"

int main(void) {
    FILE *fp;
    char words[MAX];
    int word_count = 0;

    if ((fp = fopen(FILE_NAME, "a+")) == NULL) {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        word_count++;
    rewind(fp);

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%3d: %s\n", ++word_count, words);

    puts("File contents:");
    rewind(fp);           /* go back to beginning of file */
    while (fgets(words, MAX, fp) != NULL)
        fputs(words, stdout);
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }
    puts("Done!");

    return 0;
}
