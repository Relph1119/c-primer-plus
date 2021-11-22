//
// Created by HRF on 2021/11/22.
//
#include "stdio.h"
#include "ctype.h"

#define ID_MASK 0xFF
#define SIZE_MASK 0x7F00
#define ALIGN_LEFT 0x00000
#define ALIGN_CENTER 0x08000
#define ALIGN_RIGHT 0x10000
#define ALIGN_MASK 0x18000
#define BOLD_MASK 0x20000
#define ITALIC_MASK 0x40000
#define UNDER_MASK 0x80000
#define SIZE_SHIFT 8

typedef unsigned long font_style;

void menu(font_style font_mode);
void change_font(font_style *font);
void change_size(font_style *font);
void change_alignment(font_style *font);
void change_others(char ch, font_style *font);

int main(void) {
    font_style font = 1 | (12 << SIZE_SHIFT) | ALIGN_LEFT;

    char choice;
    menu(font);
    scanf("%c", &choice);
    choice = tolower(choice);
    while (choice != 'q') {
        while (getchar() != '\n')
            continue;
        switch (choice) {
            case 'f':
                change_font(&font);
                break;
            case 's':
                change_size(&font);
                break;
            case 'a':
                change_alignment(&font);
                break;
            default:
                change_others(choice, &font);
        }
        menu(font);
        scanf("%c", &choice);
    }
    printf("Bye!");
    return 0;
}

void change_font(font_style *font) {
    unsigned int n;
    printf("Enter font id (0-255):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    *font &= ~ID_MASK;
    *font |= n;
}

void change_size(font_style *font) {
    unsigned int n;
    printf("Enter font size (0-127):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    *font &= ~SIZE_MASK;
    *font |= n << SIZE_SHIFT;;
}

void change_alignment(font_style *font) {
    char ch;
    printf("Select alignment:\n");
    printf("1)left   c)center   r)right\n");
    scanf("%c", &ch);
    while (getchar() != '\n')
        continue;
    switch (ch) {
        case 'l':
            *font &= ~ALIGN_MASK;
            *font |= ALIGN_LEFT;
            break;
        case 'c':
            *font &= ~ALIGN_MASK;
            *font |= ALIGN_CENTER;
            break;
        case 'r':
            *font &= ~ALIGN_MASK;
            *font |= ALIGN_RIGHT;
            break;
        default:
            printf("Not valid alignment.\n");
    }
}

void change_others(char ch, font_style *font) {
    if (ch == 'b') {
        *font ^= BOLD_MASK;
    }
    if (ch == 'i') {
        *font ^= ITALIC_MASK;
    }
    if (ch == 'u') {
        *font ^= UNDER_MASK;
    }
}

void menu(font_style f) {
    printf("%4s %4s %9s %3s %3s %3s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4lu%5lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
    switch (f & ALIGN_MASK) {
        case ALIGN_LEFT:
            printf("%7s", "left");
            break;
        case ALIGN_CENTER:
            printf("%7s", "center");
            break;
        case ALIGN_RIGHT:
            printf("%7s", "right");
        default:
            printf("%7s", "unknown");
    }
    printf("%8s", (f & BOLD_MASK) == BOLD_MASK ? "on" : "off");
    printf("%4s", (f & ITALIC_MASK) == ITALIC_MASK ? "on" : "off");
    printf("%4s\n", (f & UNDER_MASK) == UNDER_MASK ? "on" : "off");
    printf("f)change font    s)change size    a)change alignment\n");
    printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
}


