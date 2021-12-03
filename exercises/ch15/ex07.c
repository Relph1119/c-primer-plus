//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <ctype.h>

// 字体ID掩码
#define ID_MASK 0xFF
// 字体大小掩码
#define SIZE_MASK 0x7F00
// 字体左对齐掩码
#define ALIGN_LEFT 0x00000
// 字体居中掩码
#define ALIGN_CENTER 0x08000
// 字体右对齐掩码
#define ALIGN_RIGHT 0x10000
// 字体对齐掩码
#define ALIGN_MASK 0x18000
// 字体加粗掩码
#define BOLD_MASK 0x20000
// 字体斜体掩码
#define ITALIC_MASK 0x40000
// 字体下划线掩码
#define UNDER_MASK 0x80000
// 字体大小的位数
#define SIZE_SHIFT 8

typedef unsigned long font_style;

void menu(font_style font_mode);
void change_font(font_style *font);
void change_size(font_style *font);
void change_alignment(font_style *font);
void change_others(char ch, font_style *font);

int main(void) {
    // 设置初始值
    font_style font = 1 | (12 << SIZE_SHIFT) | ALIGN_LEFT;

    char choice;
    // 显示菜单
    menu(font);
    while ( scanf("%c", &choice) == 1 && choice != 'q') {
        while (getchar() != '\n')
            continue;
        switch (choice) {
            case 'f':
                // 改变字体ID
                change_font(&font);
                break;
            case 's':
                // 改变字体大小
                change_size(&font);
                break;
            case 'a':
                // 改变对齐方式
                change_alignment(&font);
                break;
            default:
                // 改变其他（加粗、斜体、下划线）
                change_others(choice, &font);
        }
        putchar('\n');
        menu(font);
    }
    printf("Bye!");
    return 0;
}

void change_font(font_style *font) {
    unsigned int n;
    // 提示用户输入字体ID
    printf("Enter font id (0-255):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    // 先清空位，再设置字体ID
    *font &= ~ID_MASK;
    *font |= n;
}

void change_size(font_style *font) {
    unsigned int n;
    // 提示用户输入字体大小
    printf("Enter font size (0-127):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    // 先清空位，再设置字体大小，并左移位置
    *font &= ~SIZE_MASK;
    *font |= n << SIZE_SHIFT;;
}

void change_alignment(font_style *font) {
    char ch;
    // 提示用户输入字体对齐方式
    printf("Select alignment:\n");
    printf("1)left   c)center   r)right\n");
    scanf("%c", &ch);
    while (getchar() != '\n')
        continue;
    switch (ch) {
        case 'l':
            // 先清空位，再设置字体左对齐
            *font &= ~ALIGN_MASK;
            *font |= ALIGN_LEFT;
            break;
        case 'c':
            // 先清空位，再设置字体居中
            *font &= ~ALIGN_MASK;
            *font |= ALIGN_CENTER;
            break;
        case 'r':
            // 先清空位，再设置字体右对齐
            *font &= ~ALIGN_MASK;
            *font |= ALIGN_RIGHT;
            break;
        default:
            printf("Not valid alignment.\n");
    }
}

void change_others(char ch, font_style *font) {
    if (ch == 'b') {
        // 加粗切换位
        *font ^= BOLD_MASK;
    }
    if (ch == 'i') {
        // 斜体切换位
        *font ^= ITALIC_MASK;
    }
    if (ch == 'u') {
        // 下划线切换位
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