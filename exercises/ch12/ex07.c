//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>              /* for library srand() */
#include <time.h>                /* for time()          */

int rollem(int sides);

int main(void) {
    int dice, roll, count;
    int sides;
    int set, sets;

    srand((unsigned int) time(0)); /* randomize seed      */
    printf("Enter the number of sets; enter q to stop:");
    while (scanf("%d", &sets) == 1) {
        printf("How many sides and how many dice?");
        while (scanf("%d %d", &sides, &dice) != 2) {
            puts("not integers -- terminating input loop.");
            break;
        }
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (set = 0; set < sets; set++) {
            for (roll = 0, count = 0; count < dice; count++){
                roll += rollem(sides);
            }
            printf("%4d ", roll);
            if (set % 15 == 14)
                putchar('\n');
        }
        if (set % 15 != 0)
            putchar('\n');

        printf("How many sides? Enter q to stop:");
    }

    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}

int rollem(int sides) {
    return rand() % sides + 1;
}