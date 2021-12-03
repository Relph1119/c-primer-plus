/* petclub.c -- use a binary search tree */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

// 显示菜单
char menu(void);
// 新增宠物
void addpet(Tree *pt);
// 删除一个宠物
void droppet(Tree *pt);
// 显示宠物列表
void showpets(const Tree *pt);
// 查找一个宠物
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

/*
 * input
 * Quincy, pig
 * Bennie Haha, parrot
 * Hiram Jinx, domestic cat
 * Hiram Jinx, pig
 */
int main(void) {
    Tree pets;
    char choice;

    // 初始化二叉查找树
    InitializeTree(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a' :
                // 新增宠物
                addpet(&pets);
                break;
            case 'l' :
                // 显示宠物列表
                showpets(&pets);
                break;
            case 'f' :
                // 查找一个宠物
                findpet(&pets);
                break;
            case 'n' :
                // 统计宠物个数
                printf("%d pets in club\n",
                       TreeItemCount(&pets));
                break;
            case 'd' :
                // 删除宠物
                droppet(&pets);
                break;
            default  :
                puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu(void) {
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n')  /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF)       /* make EOF cause program to quit */
        ch = 'q';

    return ch;
}

void addpet(Tree *pt) {
    Item temp;

    // 初始化temp，防止同名宠物的宠物类型是乱的数据
    for (int i = 0; i < SLEN; i++) {
        strcpy(temp.petkind[i], "\0");
    }

    if (TreeIsFull(pt))
        puts("No room in the club!");
    else {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind[0], SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind[0]);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree *pt) {
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item) {
    int i = 0;
    while (strlen(item.petkind[i]) > 0) {
        printf("Pet: %-19s  Kind: %-19s\n", item.petname,
               item.petkind[i]);
        i++;
    }
}

void findpet(const Tree *pt) {
    Item temp;

    if (TreeIsEmpty(pt)) {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind[0], SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind[0]);
    printf("%s the %s ", temp.petname, temp.petkind[0]);
    if (InTree(&temp, pt))
        printf("is a member.\n");
    else
        printf("is not a member.\n");
}

void droppet(Tree *pt) {
    Item temp;

    if (TreeIsEmpty(pt)) {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind[0], SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind[0]);
    printf("%s the %s ", temp.petname, temp.petkind[0]);
    if (DeleteItem(&temp, pt))
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
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