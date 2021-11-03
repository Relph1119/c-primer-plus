//
// Created by HRF on 2021/11/2.
//
#include "stdio.h"
void print_blank(int num);
void print_letter_asc(int num);
void print_letter_desc(int num);

int main(void){
    char letter;

    printf("Enter a letter:");
    scanf_s("%c", &letter);
    int count = letter - 'A' + 1;
    for(int i = 0; i < count; i++){
        print_blank(count - i + 1);
        print_letter_asc(i);
        print_letter_desc(i);
        print_blank(count - i + 1);
        printf("\n");
    }

    return 0;
}

void print_blank(int num){
    for(int i = 0; i <= num; i++){
        printf(" ");
    }
}

void print_letter_asc(int num){
    char c = 'A';
    for(int i = 0; i <= num; i++, c++){
        printf("%c", c);
    }
}

void print_letter_desc(int num){
    char c = 'A' + num - 1;
    for(int i = 0; i < num; i++, c--){
        printf("%c", c);
    }
}