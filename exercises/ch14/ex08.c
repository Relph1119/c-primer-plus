//
// Created by HRF on 2021/11/17.
//
#include <string.h>
#include "stdio.h"

#define SEATS 12
#define LEN 20

struct plane_seat {
    int id;
    int status;
    char first_name[LEN];
    char last_name[LEN];
};

void menu(void);

void get_empty(struct plane_seat list[]);
void show_empty(struct plane_seat list[]);
void show_booked(struct plane_seat list[]);
void book_seat(struct plane_seat list[]);
void cancel_book(struct plane_seat list[]);
void init_seats(struct plane_seat list[]);

int main(void) {
    char selected;
    struct plane_seat seats[SEATS];

    init_seats(seats);
    menu();
    while ((selected = getchar()) != 'f') {
        switch (selected) {
            case 'a':
                get_empty(seats);
                break;
            case 'b':
                show_empty(seats);
                break;
            case 'c':
                show_booked(seats);
                break;
            case 'd':
                book_seat(seats);
                break;
            case 'e':
                cancel_book(seats);
                break;
            default:
                break;
        }
        while (getchar() != '\n')
            continue;
        menu();
    }

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

void get_empty(struct plane_seat list[]) {
    int sum = 0;
    for (int i = 0; i < SEATS; i++) {
        if (list[i].status == 0) {
            sum++;
        }
    }
    printf("There are %d seats empty.\n", sum);
}

void show_empty(struct plane_seat list[]) {
    printf("Empty Seats: ");
    for (int i = 0; i < SEATS; i++) {
        if (list[i].status == 0) {
            printf("%d ", i + 1);
        }
    }
    putchar('\n');
}

void show_booked(struct plane_seat list[]) {
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

    puts("Alphabetical list:");
    for (int i = 0; i < SEATS; ++i) {
        if (pseat[i]->status == 1) {
            printf("Seat No.%d book by %s, %s\n", (i + 1), pseat[i]->first_name, pseat[i]->last_name);
        }
    }
}

void book_seat(struct plane_seat list[]) {
    int id;
    char first_name[LEN], last_name[LEN];
    show_empty(list);
    puts("Please select the seat:");
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
    puts("Booked!");
}

void cancel_book(struct plane_seat list[]) {
    show_booked(list);
    int id;
    puts("Please select the seat to cancel:");
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