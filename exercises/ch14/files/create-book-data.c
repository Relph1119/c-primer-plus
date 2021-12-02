//
// Created by HRF on 2021/11/17.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXTITL   100
#define MAXAUTL   40
#define FILE_PATH "exercises/ch14/files/book.dat"
#define LEN 13
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
void create_book(void);
void read_book (void);

int main(void) {
    // 创建book.dat文件
    create_book();
    // 读取book.dat文件，检查文件是否正确
    read_book();
    return 0;
}

void create_book(void) {
    struct book library[LEN] = {
            {"My Life as a Budgie", "Mack Zackles",12.96, 0},
            {"Thought and Unthought Rethought", "Kindra Schlagmeyer", 43.50, 0},
            {"Concerto for Financial Instruments", "Filmore Walletz", 49.99, 0},
            {"The CEO Power Diet", "Buster Downsize", 19.25, 0},
            {"C++ Primer Plus", "Stephen Prata", 59.99, 0},
            {"Fact Avoidance: Perception as Reality", "Polly Bull", 19.97, 0},
            {"Coping with Coping", "Dr. Rubin Thonkwacker", 0.02, 0},
            {"Diaphanous Frivolity", "Neda McFey", 29.99, 0},
            {"Murder Wore a Bikini", "Mickey Splats", 18.95, 0},
            {"A History of Buvania, Volume 8", "Prince Nikoli Buvan", 50.04, 0},
            {"Mastering Your Digital Watch, 5nd Edition", "Miklos Mysz", 28.95, 0},
            {"A Foregone Confusion", "Phalty Reasoner", 5.99, 0},
            {"Outsourcing Government: Selection vs. Election", "Ima Pundit", 33.33, 0},
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
        printf("%s by %s: $%.2f, status: %s\n", library[index].title,
               library[index].author, library[index].value, library[index].delete_flag == 1 ? "delete" : "exist");
    }

    printf("Start write to file...\n");
    if(fwrite(library, size, count, save_pbooks) != 0) {
        printf("File %s write correct!\n", FILE_PATH);
    } else {
        fprintf(stderr, "Can't write file %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }

    if (fclose(save_pbooks) != 0) {
        fprintf(stderr, "Can't close file %s\n", FILE_PATH);
    }
    printf("\n");
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

    rewind(read_pbooks);
    if (fread(read_library, size,LEN, read_pbooks)) {
        puts("Current contents of book.dat:");
        for (int i = 0; i < LEN; i++) {
            printf("%s by %s: $%.2f, status: %s\n", read_library[i].title,
                   read_library[i].author, read_library[i].value, read_library[i].delete_flag == 1 ? "delete" : "exist");
        }
    }
    fclose(read_pbooks);
}