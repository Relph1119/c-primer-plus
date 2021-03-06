//
// Created by HRF on 2021/11/18.
//
#include <stdio.h>
#include <math.h>

#define FUN_NUM 4
// 显示菜单
void menu(void);
// 4个函数
double twice(double x);
double half(double x);
double thrice(double x);
double square_root(double x);

int main(void) {
    // 定义函数指针
    double (* pf[FUN_NUM])(double);
    pf[0] = twice;
    pf[1] = half;
    pf[2] = thrice;
    pf[3] = square_root;
    double val;
    char ch;
    double ans;

    // 显示菜单选择
    printf("Enter a number (negative to quit):");
    while (scanf("%lf", &val) == 1 && val >= 0) {
        while (getchar() != '\n')
            continue;
        menu();
        while ((ch = getchar()) != 'q') {
            // 调用不同的函数
            switch (ch) {
                case 'a':
                    ans = pf[0](val);
                    break;
                case 'b':
                    ans = pf[1](val);
                    break;
                case 'c':
                    ans = pf[2](val);
                    break;
                case 'd':
                    ans = pf[3](val);
                    break;
                default:
                    break;
            }
            while (getchar() != '\n')
                continue;
            printf("answer = %f\n", ans);
            menu();
        }
        while (getchar() != '\n')
            continue;

        putchar('\n');
        printf("Enter next number (negative to quit): ");
    }
    printf("Bye.\n");
    return 0;
}

void menu(void) {
    puts("Enter one of the following choices:");
    puts("a) double the value     b) halve the value");
    puts("c) triple the value     d) squareroot the value");
    puts("q) quit");
}

double twice(double x) {
    return 2.0 * x;
}

double half(double x) {
    return x / 2.0;
}

double thrice(double x) {
    return 3.0 * x;
}

double square_root(double x) {
    return sqrt(x);
}