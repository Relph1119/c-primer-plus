//
// Created by HRF on 2021/11/4.
//
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int high = 100;
    int low = 1;
    int guess = (high + low) / 2;
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y') {
        if (response == '\n')
            continue;
        if (response != 'h' && response != 'l') {
            printf("I don't understand that response. Please enter h for\n");
            printf("high, l for low, or y for correct.\n");
            continue;
        }

        if (response == 'h')
            high = guess - 1;
        else if (response == 'l')
            low = guess + 1;
        guess = (high + low) / 2;

        printf("Well, then, is it %d? [low:%d, high:%d]\n", guess, low, high);
        if (high <= low)
            break;
    }

    printf("The number is %d. I knew I could do it!\n", guess);
    return 0;
}
