//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <limits.h>
char *itobs(int n, char *ps);
int onbits(int n);

int main(void) {
    int value;
    static int SLEN = CHAR_BIT * sizeof(int) + 1;

    char bstr[SLEN];

    printf("Enter an integer (q to quit):");
    while (scanf("%d", &value)) {
        printf("%d (%s) has %d bit(s) on.\n", value, itobs(value, bstr), onbits(value));
        printf("Enter next integer:");
    }

    printf("Done.\n");
    return 0;
}

int onbits(int n) {
    static const int size = CHAR_BIT * sizeof(int);
    int count = 0;
    int i;

    for (i = 0; i < size; i++, n >>= 1) {
        if ((1 & n) == 1) {
            count++;
        }
    }
    return count;
}

char *itobs(int n, char *ps) {
    int i;
    static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1) {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';

    return ps;
}