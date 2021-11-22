//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <limits.h>
char *itobs(int n, char *ps);
unsigned int rotate(unsigned  int n, unsigned  int b);

int main(void) {
    static const int SLEN = CHAR_BIT * sizeof(int) + 1;
    unsigned int value;
    unsigned int rot;
    unsigned int places;
    char bstr1[SLEN];
    char bstr2[SLEN];

    printf("Enter an integer (q to quit):");
    while (scanf("%ud", &value)) {
        printf("Enter the number of bits to be rotated:\n");
        if (scanf("%ul", &places) != 1) {
            break;
        }
        rot = rotate(value, places);
        itobs(value, bstr1);
        itobs(rot, bstr2);
        printf("Decimal: %u rotated is %u.\n", value, rot);
        printf("Binary: %s rotated is %s.\n", bstr1, bstr2);
        printf("Enter next integer:");
    }

    return 0;
}

unsigned int rotate(unsigned  int n, unsigned  int b) {
    static const int size = CHAR_BIT * sizeof (int);
    unsigned int overflow;

    b %= size;

    overflow = n >> (size - b);
    return (n << b) | overflow;
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