//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>
#include <ctype.h>

void print_menu(void);
int get_first(void);
double get_number(void);
void calc(int response);

int main(void) {
    int response;

    // 打印菜单
    print_menu();
    // 读取用户选择，使用get_first()函数，获取第一个字母
    while ((response = get_first()) != 'q') {
        if (response == '\n')
            continue;
        // 将用户输入替换成小写字母
        response = tolower(response);

        // 进行选择判断
        switch (response) {
            case 'a':
            case 's':
            case 'm':
            case 'd':
                calc(response);
                break;
            default:
                printf("Please enter a, s, m, d, or q.\n");
                print_menu();
                continue;
        }
        print_menu();
    }

    printf("Bye.");
    return 0;
}

void print_menu(void) {
    printf("*****************************************************************\n");
    printf("Enter the operation of your choice:\n");
    printf("a. add                            s. subtract\n");
    printf("m. multiply                       d. divide\n");
    printf("q) quit\n");
    printf("*****************************************************************\n");
}

// 得到第一个字母
int get_first(void) {
    int ch;

    ch = getchar();
    while (isspace(ch) || ispunct(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

// 得到数字
double get_number(void) {
    double input;
    char ch;

    while (scanf("%lf", &input) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input
        printf(" is not an number.\n");
        printf("Please enter an number, such as 2.5, -1.78E8, or 3:");
    }

    return input;
}

void calc(int response) {
    double first_number, second_number;

    // 提示用户输入double类型的数字，并进行检查
    printf("Enter first number:");
    first_number = get_number();
    printf("Enter second number:");
    second_number = get_number();

    switch (response) {
        case 'a':
            printf("%g + %g = %g\n", first_number, second_number, first_number + second_number);
            break;
        case 's':
            printf("%g - %g = %g\n", first_number, second_number, first_number - second_number);
            break;
        case 'm':
            printf("%g * %g = %g\n", first_number, second_number, first_number * second_number);
            break;
        case 'd':
            // 当输入0作为第2个数（除数）
            if (second_number == 0) {
                // 提示用户重新输入一个新值
                printf("Enter a number other than 0:");
                second_number = get_number();
            }
            printf("%g / %g = %g\n", first_number, second_number, first_number / second_number);
            break;
        default:;
    }
}