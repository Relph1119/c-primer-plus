//
// Created by HRF on 2021/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL  100
#define MAXAUTL  40
#define MAXBKS   20             /* maximum number of books */
#define FIEL_PATH "exercises/ch14/files/book.dat"
char *s_gets(char *st, int n);
struct book {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    double value;
    int delete_flag;
};
void show_library(struct book library[], int count, int show_del_flag);

int main(void) {
    struct book library[MAXBKS]; /* array of structures     */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);
    char delete;

    if ((pbooks = fopen(FIEL_PATH, "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }

    rewind(pbooks);            /* go to start of file     */
    while (count < MAXBKS && fread(&library[count], size,1, pbooks) == 1) {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
               library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    printf("Do you want to modify library? (y/n):");
    scanf("%c",&delete);
    if (delete == 'y') {
        show_library(library, filecount, 1);
        printf("Which book do you want to delete? (1 to %d)", filecount);
        int book_num;
        scanf("%d", &book_num);
        library[book_num - 1].delete_flag = 1;
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0' && library[count].delete_flag != 1) {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%lf", &library[count].value);
        library[count++].delete_flag = 0;
        while (getchar() != '\n')
            continue;                /* clear input line  */
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    if (count > 0) {
        show_library(library, count, 0);
        fwrite(&library[filecount], size, count - filecount,
               pbooks);
    } else
        puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}

void show_library(struct book library[], int count, int show_del_flag) {
    int index;
    puts("Here is the list of your books:");
    if (show_del_flag != 1) {
        for (index = 0; index < count; index++) {
            if (library[index].delete_flag != 1){
                printf("%s by %s: $%.2f\n", library[index].title,
                       library[index].author, library[index].value);
            }
        }
    } else {
        for (index = 0; index < count; index++) {
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
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