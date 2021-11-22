//
// Created by HRF on 2021/11/16.
//
#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);

#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100              /* maximum number of books  */

struct book {                     /* set up book template     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void sort_title(struct book *pb[], int n);
void sort_value(struct book *pb[], int n);

/*
 * input book list (title, author, value):
 * My Life as a Budgie, Mack Zackles, 12.96
 * Thought and Unthought Rethought, Kindra Schlagmeyer, 43.50
 * Concerto for Financial Instruments, Filmore Walletz, 49.99
 * The CEO Power Diet, Buster Downsize, 19.25
 * C++ Primer Plus, Stephen Prata, 59.99
 * Fact Avoidance: Perception as Reality, Polly Bull, 19.97
 * Coping with Coping, Dr. Rubin Thonkwacker, 0.02
 * Diaphanous Frivolity, Neda McFey, 29.99
 * Murder Wore a Bikini, Mickey Splats, 18.95
 * A History of Buvania, Volume 8, Prince Nikoli Buvan, 50.04
 * Mastering Your Digital Watch, 5nd Edition, Miklos Mysz, 28.95
 * A Foregone Confusion, Phalty Reasoner, 5.99
 * Outsourcing Government: Selection vs. Election, Ima Pundit, 33.33
 */
int main(void) {
    struct book library[MAXBKS]; /* array of book structures */
    struct book *pbk[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        pbk[count] = &library[count];
        count++;
        while (getchar() != '\n')
            continue;          /* clear input line         */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0) {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);

        printf("Here is the list of your books sorted by title:\n");
        sort_title(pbk, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", pbk[index]->title,
                   pbk[index]->author, pbk[index]->value);

        printf("Here is the list of your books sorted by value:\n");
        sort_value(pbk, count);
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", pbk[index]->title,
                   pbk[index]->author, pbk[index]->value);
    } else {
        printf("No books? Too bad.\n");
    }

    return 0;
}

void sort_title(struct book *pb[], int n) {
    int top, seek;
    struct book * temp;

    for (top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (strcmp(pb[seek]->title, pb[top]->title) < 0) {
                temp = pb[seek];
                pb[seek] = pb[top];
                pb[top] = temp;
            }
        }
    }
}

void sort_value(struct book *pb[], int n) {
    int top, seek;
    struct book * temp;

    for (top = 0; top < n - 1; top++) {
        for (seek = top + 1; seek < n; seek++) {
            if (pb[seek]->value < pb[top]->value) {
                temp = pb[seek];
                pb[seek] = pb[top];
                pb[top] = temp;
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
