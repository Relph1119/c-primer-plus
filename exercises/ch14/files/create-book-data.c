//
// Created by HRF on 2021/11/17.
//
//
// Created by HRF on 2021/11/16.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXTITL   200
#define MAXAUTL   40
#define FILE_PATH "exercises/ch14/files/book.dat"
#define LEN 13
struct book {                     /* set up book template     */
    char title[MAXTITL];
    char author[MAXAUTL];
    double value;
};
void create_book(void);
void read_book (void);

int main(void) {
    create_book();
//    read_book();
    return 0;
}

void create_book(void) {
    struct book library[LEN] = {
            {"My Life as a Budgie", "Mack Zackles",12.96},
            {"Thought and Unthought Rethought", "Kindra Schlagmeyer", 43.50},
            {"Concerto for Financial Instruments", "Filmore Walletz", 49.99},
            {"The CEO Power Diet", "Buster Downsize", 19.25},
            {"C++ Primer Plus", "Stephen Prata", 59.99},
            {"Fact Avoidance: Perception as Reality", "Polly Bull", 19.97},
            {"Coping with Coping", "Dr. Rubin Thonkwacker", 0.02},
            {"Diaphanous Frivolity", "Neda McFey", 29.99},
            {"Murder Wore a Bikini", "Mickey Splats", 18.95},
            {"A History of Buvania, Volume 8", "Prince Nikoli Buvan", 50.04},
            {"Mastering Your Digital Watch, 5nd Edition", "Miklos Mysz", 28.95},
            {"A Foregone Confusion", "Phalty Reasoner", 5.99},
            {"Outsourcing Government: Selection vs. Election", "Ima Pundit", 33.33},
            };

    int count = LEN;
    int index;
    FILE * save_pbooks;
    int size = sizeof(struct book);

    if ((save_pbooks = fopen(FILE_PATH, "w+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }

    printf("Here is the list of your books:\n");
    for (index = 0; index < count; index++){
        printf("%s by %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
    }

    printf("Start write to file...\n");
    if(fwrite(&library[count], size, count, save_pbooks) != 0) {
        printf("File write correct!\n");
    } else {
        fprintf(stderr, "Can't write file %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }

    if (fclose(save_pbooks) != 0) {
        fprintf(stderr, "Can't close file %s\n", FILE_PATH);
    }
}

void read_book (void) {
    FILE * read_pbooks;
    struct book read_library[LEN];
    int size = sizeof(struct book);

    if ((read_pbooks = fopen(FILE_PATH, "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }

    printf("Start read file...\n");

    putchar('\n');
    int read_count = 0;
    while (fread(&read_library[read_count], size,1, read_pbooks) == 1) {
        if (read_count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2lf\n", read_library[read_count].title,
               read_library[read_count].author, read_library[read_count].value);
        read_count++;
    }
    fclose(read_pbooks);
}

