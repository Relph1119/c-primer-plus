//
// Created by HRF on 2021/11/14.
//
#include <stdio.h>
void critic(int *u);

int main(void) {
    int units;  /* an optional redeclaration */

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");

    return 0;
}

void critic(int *u) {
    /* optional redeclaration omitted */
    printf("No luck, my friend. Try again.\n");
    scanf("%d", u);
}
