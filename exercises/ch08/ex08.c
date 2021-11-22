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

    print_menu();
    while ((response = get_first()) != 'q') {
        if (response == '\n')
            continue;

        response = tolower(response);

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

int get_first(void) {
    int ch;

    ch = getchar();
    while (isspace(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

double get_number(void) {
    double input;
    char ch;

    while (scanf("%lf", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input
            printf(" is not an number.\nPlease enter an ");
            printf("number, such as 2.5, -1.78E8, or 3: ");
    }

    return input;
}

void calc(int response){
    double first_number, second_number;

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
            if (second_number == 0) {
                printf("Enter a number other than 0:");
                second_number = get_number();
            }
            printf("%g / %g = %g\n", first_number, second_number, first_number / second_number);
            break;
        default:
            ;
    }
}