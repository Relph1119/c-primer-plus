//
// Created by HRF on 2021/11/15.
//
#include <stdio.h>
#include <stdlib.h>    // for exit()
#include <string.h>    // for strcpy(), strcat()

#define LEN 40
char *s_gets(char *st, int n);

int main(void) {
    FILE *in, *out;   // declare two FILE pointers
    int ch;
    char input_file_name[LEN];
    char output_file_name[LEN];    // storage for output filename
    int count = 0;

    printf("Enter a source file name:\n");
    // input exercises/ch13/files/eddy
    s_gets(input_file_name, LEN);
    // set up input
    if ((in = fopen(input_file_name, "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                input_file_name);
        exit(EXIT_FAILURE);
    }
    // set up output
    strncpy(output_file_name, input_file_name, LEN - 5); // copy filename
    output_file_name[LEN - 5] = '\0';
    strcat(output_file_name, ".red");            // append .red
    if ((out = fopen(output_file_name, "w")) == NULL) {                       // open file for writing
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else // must have words[i] == '\0'
        while (getchar() != '\n')
            continue;
    }
    return ret_val;
}