//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>

struct font_style {
    // 字体ID
    unsigned int id: 8;
    // 字体大小
    unsigned int size: 7;
    // 对齐方式
    unsigned int align: 2;
    // 加粗
    unsigned int bold: 1;
    // 斜体
    unsigned int italic: 1;
    // 下划线
    unsigned int underline: 1;
};

// 对齐的打印信息
const char align[][8] = {"left", "center", "right"};
// 开关的打印信息
const char on_off[][4] = {"off", "on"};
// 菜单
void menu(struct font_style font_mode);
// 改变字体ID
void change_font(struct font_style *font);
// 改变字体大小
void change_size(struct font_style *font);
// 改变对齐方式
void change_alignment(struct font_style *font);
// 改变其他（加粗、斜体、下划线）
void change_others(char ch, struct font_style *font);

int main(void) {
    char choice;
    // 设置初始值，0表示关闭
    struct font_style font = {1, 12, 0, 0, 0, 0};
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

void change_font(struct font_style *font) {
    unsigned int n;
    // 提示用户输入字体ID
    printf("Enter font id (0-255):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    font->id = n;
}

void change_size(struct font_style *font) {
    unsigned int n;
    // 提示用户输入字体大小
    printf("Enter font size (0-127):");
    scanf("%u", &n);
    while (getchar() != '\n')
        continue;
    font->size = n;
}

void change_alignment(struct font_style *font) {
    char ch;
    // 提示用户输入字体对齐方式
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
        // 加粗切换开关
        font->bold = !font->bold;
    }
    if (ch == 'i') {
        // 斜体切换开关
        font->italic = !font->italic;
    }
    if (ch == 'u') {
        // 下划线切换开关
        font->underline = !font->underline;
    }
}

void menu(struct font_style font_mode) {
    printf("%4s %4s %9s %3s %3s %3s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4d %4d %6s %7s %3s %3s\n", font_mode.id, font_mode.size, align[font_mode.align], on_off[font_mode.bold],
           on_off[font_mode.italic], on_off[font_mode.underline]);
    printf("f)change font    s)change size    a)change alignment\n");
    printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
    printf("q)quit\n");
}