//
// Created by HRF on 2021/11/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITL  100
#define MAXAUTL  40
// 最大书籍数量
#define MAXBKS   20
// 书籍文件
#define FIEL_PATH "exercises/ch14/files/book.dat"

char *s_gets(char *st, int n);

struct book {
    // 书名
    char title[MAXTITL];
    // 作者
    char author[MAXAUTL];
    // 价格
    double value;
    // 删除标记
    int delete_flag;
};

void show_library(const struct book library[], int count, int show_del_flag);
static void clear_input(void);

int main(void) {
    struct book library[MAXBKS];
    int count = 0;
    int filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    char delete;

    // 检查文件是否打开正常，并获取文件句柄
    if ((pbooks = fopen(FIEL_PATH, "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }

    // 定位到文件开始处
    rewind(pbooks);
    // 读取文件，采用原结构体保存到数组中
    while (count < MAXBKS && fread(&library[count], sizeof(struct book), 1, pbooks) == 1) {
        if (count == 0)
            puts("Current contents of book.dat:");
        if (library[count].delete_flag != 1) {
            printf("No.%d %s by %s: $%.2f\n", count + 1, library[count].title,
                   library[count].author, library[count].value);
        }
        count++;
    }

    filecount = count;
    // 判断数量是否溢出
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    // 提示用户是否要删除书籍
    printf("\nDo you want to modify library? (y/n):");
    while (scanf("%c", &delete) == 1 && delete == 'y') {
        clear_input();
        // 提示用户选择要删除的书号
        printf("Which book do you want to delete? (1 to %d):", filecount);
        int book_num;
        scanf("%d", &book_num);
        clear_input();
        // 再次提示用户是否要删除
        printf("Do you want to delete this book [%s]? (y/n):", library[book_num - 1].title);
        scanf("%c", &delete);
        if (delete == 'y') {
            // 设置删除标记
            library[book_num - 1].delete_flag = 1;
        }
        clear_input();
        show_library(library, filecount, false);
        printf("\nDo you want to modify library? (y/n):");
    }

    clear_input();
    /*
     * input:
     * 10 Steps to Earning Awesome Grades
     * Thomas Frank
     * 19.62
     */
    // 提示用户添加新书
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0' && library[count].delete_flag != 1) {
        // 提示用户输入作者
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        // 提示用户输入价格
        puts("Now enter the value.");
        scanf("%lf", &library[count].value);
        // 设置删除状态为0
        library[count++].delete_flag = 0;
        clear_input();
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    if (count > 0) {
        // 打印所有书籍信息，包括已标记删除的书籍
        show_library(library, count, true);
        // 将数据写入到文件中
        fwrite(&library[filecount], size, count - filecount,
               pbooks);
    } else
        puts("No books? Too bad.");

    puts("Bye.");
    fclose(pbooks);

    return 0;
}

void show_library(const struct book library[], int count, int show_del_flag) {
    int index;
    puts("Here is the list of your books:");
    if (show_del_flag) {
        // 展示所有书籍
        for (index = 0; index < count; index++) {
            printf("No.%d %s by %s: $%.2f, status: %s\n", index + 1, library[index].title,
                   library[index].author, library[index].value, library[index].delete_flag == 1 ? "delete" : "exist");
        }
    } else {
        // 仅展示未删除的书籍
        for (index = 0; index < count; index++) {
            if (library[index].delete_flag != 1) {
                printf("No.%d %s by %s: $%.2f\n", index + 1, library[index].title,
                       library[index].author, library[index].value);
            }
        }
    }
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}

static void clear_input(void) {
    while (getchar() != '\n')
        continue;
}