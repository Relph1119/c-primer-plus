//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <limits.h>

int get_bit(int n, int pos);

char *itobs(int n, char *ps);

int main(void) {
    int value;
    int pos;
    static int SLEN = CHAR_BIT * sizeof(int) + 1;
    char bstr[SLEN];

    printf("Enter a integer number:");
    while (scanf("%d", &value)) {
        printf("Enter a position:");
        scanf("%d", &pos);
        switch (pos) {
            case 1:
                printf("The %dst position of %d (%s) is %d\n", pos, value, itobs(value, bstr), get_bit(value, pos));
                break;
            case 2:
                printf("The %dnd position of %d (%s) is %d\n", pos, value, itobs(value, bstr), get_bit(value, pos));
                break;
            case 3:
                printf("The %drd position of %d (%s) is %d\n", pos, value, itobs(value, bstr), get_bit(value, pos));
                break;
            default:
                printf("The %dth position of %d (%s) is %d\n", pos, value, itobs(value, bstr), get_bit(value, pos));
        }

        printf("Enter next integer number (q to quit):");
    }

    return 0;
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

int get_bit(int n, int pos) {
    static const int size = CHAR_BIT * sizeof(int) + 1;
    if (pos > size || pos < 0) {
        printf("Error position.\n");
        return -1;
    }
    if (1 & (n >> pos)) {
        return 1;
    } else {
        return 0;
    }
}