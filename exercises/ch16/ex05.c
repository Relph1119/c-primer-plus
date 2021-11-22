//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LEN 40
void random_pick(int arr[], int n, int pick_times);

int main(void) {
    int input[LEN];
    int i;
    char ch;
    int pick_times;

    for (i = 0; i < LEN; i++) {
        input[i] = i + 1;
    }

    printf("Enter a number of pick times:");
    while (scanf("%d", &pick_times) == 1) {
        printf("Pick? <y/n>:");
        while (getchar() != '\n')
            continue;
        while ((ch = getchar()) != '\0' && (ch == 'y' || ch == 'Y')) {
            while (getchar() != '\n')
                continue;
            random_pick(input, LEN, pick_times);
            printf("Pick Again? <y/n>:");
        }

        printf("Enter next number of pick times (q to quit):");
    }

    return 0;
}

void random_pick(int arr[], int n, int picks) {
    int i, index, temp;

    srand((unsigned int) time(0));
    if (picks > n) {
        fprintf(stderr, "Number of picks > array size\n");
        fprintf(stderr, "It will set picks = array size\n");
        picks = n;
    }

    printf("The number of picks:\n");
    for (i = 0; i < picks; i++) {
        index = rand() % (n - 1);
        temp = arr[index];
        printf("%d ", temp);
        if (i % 20 == 19) {
            putchar('\n');
        }
        arr[index] = arr[n - 1];
        arr[n - 1] = temp;
        n--;
    }
    if (i % 20 != 0) {
        putchar('\n');
    }
}