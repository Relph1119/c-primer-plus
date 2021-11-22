//
// Created by HRF on 2021/11/17.
//
#include <string.h>
#include <stdio.h>

#define AIRS 4
#define SEATS 12
#define LEN 20

struct plane_seat {
    int id;
    int status;
    char first_name[LEN];
    char last_name[LEN];
};

void menu(void);
void get_empty(struct plane_seat list[], int air_no);
void show_empty(struct plane_seat list[], int air_no);
void show_booked(struct plane_seat list[], int air_no);
void book_seat(struct plane_seat list[], int air_no);
void cancel_book(struct plane_seat list[], int air_no);
void init_seats(struct plane_seat list[]);

int main(void) {
    char selected;
    int air_no;
    struct plane_seat seats[AIRS][SEATS];
    int choice_air_no;

    for (int i = 0; i < AIRS; i++) {
        init_seats(seats[i]);
    }

    printf("Please select airplane No.(choice from 102,311,444,519):");
    scanf("%d", &air_no);
    while (air_no == 102 || air_no == 311 || air_no == 444 || air_no == 519) {
        if (air_no == 102) {
            printf("Now you select Air %d:\n", air_no);
            choice_air_no = 0;
        }
        if (air_no == 311) {
            printf("Now you select Air %d:\n", air_no);
            choice_air_no = 1;
        };
        if (air_no == 444) {
            printf("Now you select Air %d:\n", air_no);
            choice_air_no = 2;
        };
        if (air_no == 519) {
            printf("Now you select Air %d:\n", air_no);
            choice_air_no = 3;
        };
        while (getchar() != '\n')
            continue;

        menu();
        while ((selected = getchar()) != 'f') {
            switch (selected) {
                case 'a':
                    get_empty(seats[choice_air_no], air_no);
                    break;
                case 'b':
                    show_empty(seats[choice_air_no], air_no);
                    break;
                case 'c':
                    show_booked(seats[choice_air_no], air_no);
                    break;
                case 'd':
                    book_seat(seats[choice_air_no], air_no);
                    break;
                case 'e':
                    cancel_book(seats[choice_air_no], air_no);
                    break;
                default:
                    break;
            }
            while (getchar() != '\n')
                continue;
            menu();
        }
        while (getchar() != '\n')
            continue;
        printf("Please select airplane No.(choice from 102,311,444,519):");
        scanf("%d", &air_no);
    }
    printf("Bye.");
    return 0;
}

void init_seats(struct plane_seat list[]) {
    for (int i = 0; i < SEATS; i++) {
        list[i].id = i + 1;
        list[i].status = 0;
        strcpy(list[i].first_name, "");
        strcpy(list[i].last_name, "");
    }
}

void get_empty(struct plane_seat list[], int air_no) {
    int sum = 0;
    for (int i = 0; i < SEATS; i++) {
        if (list[i].status == 0) {
            sum++;
        }
    }
    printf("In Air %d, There are %d seats empty.\n", air_no, sum);
}

void show_empty(struct plane_seat list[], int air_no) {
    printf("In Air %d, Empty Seats: ", air_no);
    for (int i = 0; i < SEATS; i++) {
        if (list[i].status == 0) {
            printf("%d ", i + 1);
        }
    }
    putchar('\n');
}

void show_booked(struct plane_seat list[], int air_no) {
    struct plane_seat *pseat[LEN];
    for (int i = 0; i < SEATS; i++) {
        pseat[i] = &list[i];
    }

    int top, seek;
    struct plane_seat *temp;

    for (top = 0; top < SEATS - 1; top++) {
        for (seek = top + 1; seek < SEATS; seek++) {
            if (strcmp(pseat[top]->first_name, pseat[seek]->first_name) > 0) {
                temp = pseat[top];
                pseat[top] = pseat[seek];
                pseat[seek] = temp;
            }
        }
    }

    printf("In Air %d, Alphabetical list:", air_no);
    for (int i = 0; i < SEATS; ++i) {
        if (pseat[i]->status == 1) {
            printf("Seat No.%d book by %s, %s\n", (i + 1), pseat[i]->first_name, pseat[i]->last_name);
        }
    }
}

void book_seat(struct plane_seat list[], int air_no) {
    int id;
    char first_name[LEN], last_name[LEN];
    show_empty(list, air_no);
    printf("In Air %d, Please select the seat:", air_no);
    scanf("%d", &id);
    int seat_no = id - 1;
    if (list[seat_no].status == 1) {
        puts("Error selected.");
        return;
    }
    list[seat_no].id = id;
    puts("Please input you FIRST_NAME LAST_NAME.");
    if (scanf("%s %s", first_name, last_name) != 2) {
        return;
    };
    strcpy(list[seat_no].first_name, first_name);
    strcpy(list[seat_no].last_name, last_name);
    list[seat_no].status = 1;
    printf("In Air %d, the seat booked!", air_no);
}

void cancel_book(struct plane_seat list[], int air_no) {
    show_booked(list, air_no);
    int id;
    printf("In Air %d, Please select the seat to cancel:", air_no);
    scanf("%d", &id);
    if (list[id - 1].status == 0) {
        puts("Error selected.");
        return;
    }
    list[id - 1].status = 0;
}

void menu(void) {
    puts("To choose a function, enter its letter label: ");
    puts("a) Show number of empty seats ");
    puts("b) Show list of empty seats ");
    puts("c) Show alphabetical list of seats ");
    puts("d) Assign a customer to a seat assignment ");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}