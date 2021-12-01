//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
#include <stdlib.h>              /* for library srand() */
#include <time.h>                /* for time()          */

// 生成每个骰子的点数
int rollem(int sides);

int main(void) {
    int dice, roll, count;
    int sides;
    int set, sets;

    // 设置种子
    srand((unsigned int) time(0)); /* randomize seed      */
    // 提示用户输入掷骰子的次数
    printf("Enter the number of sets; enter q to stop:");
    while (scanf("%d", &sets) == 1) {
        // 提示用户输入骰子的面数和骰子的个数
        printf("How many sides and how many dice?");
        while (scanf("%d %d", &sides, &dice) != 2) {
            puts("not integers -- terminating input loop.");
            break;
        }
        // 打印掷骰子的结果
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (set = 0; set < sets; set++) {
            // 计算本次所有骰子的点数总和
            for (roll = 0, count = 0; count < dice; count++) {
                // 每个骰子的点数累加
                roll += rollem(sides);
            }
            printf("%3d ", roll);
            if (set % 15 == 14)
                putchar('\n');
        }
        if (set % 15 != 0)
            putchar('\n');

        printf("How many sides? Enter q to stop:");
    }

    return 0;
}

int rollem(int sides) {
    return rand() % sides + 1;
}