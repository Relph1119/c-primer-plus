//
// Created by HRF on 2021/11/22.
//
#include "stdio.h"

struct font_style {
    unsigned int id: 8;
    unsigned int size: 7;
    unsigned int align: 2;
    unsigned int bold: 1;
    unsigned int italic: 1;
    unsigned int underline: 1;
};

const char align[][8] = {"left", "center", "right"};
const char on_off[][4] = {"off", "on"};
void menu(struct font_style font_mode);
void change_font(struct font_style *font);
void change_size(struct font_style *font);
void change_alignment(struct font_style *font);
void change_others(char ch, struct font_style *font);

int main(void) {
    char choice;
    struct font_style font = {1, 12, 0, 0, 0, 0};

    menu(font);
    scanf("%c", &choice);
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

void change_font(struct font_style *font) {
    unsigned int n;
    printf("Enter font id (0-255):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    font->id = n;
}

void change_size(struct font_style *font) {
    unsigned int n;
    printf("Enter font size (0-127):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    font->size = n;
}

void change_alignment(struct font_style *font) {
    char ch;
    printf("Select alignment:\n");
    printf("1)left   c)center   r)right\n");
    scanf("%c", &ch);
    while (getchar() != '\n')
        continue;
    switch (ch) {
        case 'l':
            font->align = 0;
            break;
        case 'c':
            font->align = 1;
            break;
        case 'r':
            font->align = 2;
            break;
        default:
            printf("Not valid alignment.\n");
    }
}

void change_others(char ch, struct font_style *font) {
    if (ch == 'b') {
        font->bold = !font->bold;
    }
    if (ch == 'i') {
        font->italic = !font->italic;
    }
    if (ch == 'u') {
        font->underline = !font->underline;
    }
}

void menu(struct font_style font_mode) {
    printf("%4s %4s %9s %3s %3s %3s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4d%5d%7s%8s%4s%4s\n", font_mode.id, font_mode.size, align[font_mode.align], on_off[font_mode.bold],
           on_off[font_mode.italic], on_off[font_mode.underline]);
    printf("f)change font    s)change size    a)change alignment\n");
    printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
}