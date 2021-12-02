//
// Created by HRF on 2021/11/17.
//
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define AIRS 4
#define SEATS 12
#define LEN 20

struct plane_seat {
    // 座位编号
    int id;
    // 座位是否已被预定
    bool booked_status;
    // 预订人的名
    char first_name[LEN];
    // 预订人的姓
    char last_name[LEN];
    // 座位确认状态
    bool confirmed_status;
};
// 显示菜单
void menu(void);
// 显示空座位的总数
void get_empty(struct plane_seat list[], int air_no);
// 显示空座位
void show_empty(struct plane_seat list[], int air_no);
// 显示已预订座位
void show_booked(struct plane_seat list[], int air_no);
// 预订座位
void book_seat(struct plane_seat list[], int air_no);
// 确认座位分配
void confirm_seat(struct plane_seat list[], int air_no);
// 取消预订座位
void cancel_book(struct plane_seat list[], int air_no);
// 初始化座位
void init_seats(struct plane_seat list[]);

int main(void) {
    char selected;
    int air_no;
    struct plane_seat seats[AIRS][SEATS];
    int choice_air_no;

    // 初始化座位
    for (int i = 0; i < AIRS; i++) {
        init_seats(seats[i]);
    }

    // 显示顶层菜单
    printf("Please select airplane No.(choice from 102,311,444,519):");
    while (scanf("%d", &air_no)== 1 && (air_no == 102 || air_no == 311 || air_no == 444 || air_no == 519)) {
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

        // 显示菜单
        menu();
        while ((selected = getchar()) != 'g') {
            switch (selected) {
                case 'a':
                    // 显示空座位的总数
                    get_empty(seats[choice_air_no], air_no);
                    break;
                case 'b':
                    // 显示空座位
                    show_empty(seats[choice_air_no], air_no);
                    break;
                case 'c':
                    // 显示已预订座位
                    show_booked(seats[choice_air_no], air_no);
                    break;
                case 'd':
                    // 预订座位
                    book_seat(seats[choice_air_no], air_no);
                    break;
                case 'e':
                    // 确认座位分配
                    confirm_seat(seats[choice_air_no], air_no);
                    break;
                case 'f':
                    // 取消预订座位
                    cancel_book(seats[choice_air_no], air_no);
                    break;
                default:
                    break;
            }
            while (getchar() != '\n')
                continue;
            putchar('\n');
            menu();
        }
        while (getchar() != '\n')
            continue;
        printf("\nPlease select airplane No.(choice from 102,311,444,519, q to quit):");
    }
    printf("Bye.");
    return 0;
}

void init_seats(struct plane_seat list[]) {
    for (int i = 0; i < SEATS; i++) {
        list[i].id = i + 1;
        list[i].booked_status = false;
        strcpy(list[i].first_name, "");
        strcpy(list[i].last_name, "");
        list[i].confirmed_status = false;
    }
}

void get_empty(struct plane_seat list[], int air_no) {
    int sum = 0;
    for (int i = 0; i < SEATS; i++) {
        // 仅统计未被预订的座位
        if (list[i].booked_status == false) {
            sum++;
        }
    }
    printf("In Air %d, There are %d seats empty.\n", air_no, sum);
}

void show_empty(struct plane_seat list[], int air_no) {
    printf("In Air %d, Empty Seats: ", air_no);
    for (int i = 0; i < SEATS; i++) {
        // 显示未被预订的座位
        if (list[i].booked_status == false) {
            printf("%d ", i + 1);
        }
    }
    putchar('\n');
}

void show_booked(struct plane_seat list[], int air_no) {
    struct plane_seat *pseat[LEN];
    // 拷贝结构数组
    for (int i = 0; i < SEATS; i++) {
        pseat[i] = &list[i];
    }

    int top, seek;
    struct plane_seat *temp;

    for (top = 0; top < SEATS - 1; top++) {
        for (seek = top + 1; seek < SEATS; seek++) {
            // 比较预定人名的首字母
            if (strcmp(pseat[top]->first_name, pseat[seek]->first_name) > 0) {
                temp = pseat[top];
                pseat[top] = pseat[seek];
                pseat[seek] = temp;
            }
        }
    }

    printf("In Air %d, Alphabetical list:", air_no);
    for (int i = 0; i < SEATS; ++i) {
        if (pseat[i]->booked_status == true) {
            printf("In Air %d, Seat No.%d book by %s, %s\n", air_no, pseat[i]->id, pseat[i]->first_name, pseat[i]->last_name);
        }
    }
}

void book_seat(struct plane_seat list[], int air_no) {
    int id;
    char first_name[LEN], last_name[LEN];
    // 显示空座位
    show_empty(list, air_no);
    // 提示用户选择座位
    printf("In Air %d, Please select the seat:", air_no);
    scanf("%d", &id);
    int seat_no = id - 1;
    if (list[seat_no].booked_status == true) {
        puts("Error selected.");
        return;
    }
    list[seat_no].id = id;
    // 提示用户输入预订人的姓名
    puts("Please input you FIRST_NAME LAST_NAME.");
    if (scanf("%s %s", first_name, last_name) != 2) {
        return;
    };
    strcpy(list[seat_no].first_name, first_name);
    strcpy(list[seat_no].last_name, last_name);
    // 设置座位预订状态
    list[seat_no].booked_status = true;
    printf("In Air %d, the seat No.%d booked!\n", air_no, id);
}

void confirm_seat(struct plane_seat list[], int air_no) {
    int id;
    // 显示已预订的座位
    printf("In Air %d, Alphabetical list:\n", air_no);
    for (int i = 0; i < SEATS; ++i) {
        if (list[i].booked_status == true) {
            printf("Seat No.%d book by %s, %s\n", air_no, list[i].id, list[i].first_name, list[i].last_name);
        }
    }

    // 提示用户选择座位
    printf("In Air %d, Please select the seat to confirm:", air_no);
    scanf("%d", &id);
    int seat_no = id - 1;
    if (list[seat_no].booked_status != true) {
        puts("Error selected.");
        return;
    }
    // 设置座位确认状态
    list[seat_no].confirmed_status = true;
    printf("In Air %d, the seat No.%d confirmed!\n", air_no, id);
}

void cancel_book(struct plane_seat list[], int air_no) {
    show_booked(list, air_no);
    int id;
    // 提示用户选择要取消预订的座位
    printf("In Air %d, Please select the seat to cancel:", air_no);
    scanf("%d", &id);
    if (list[id - 1].booked_status == false) {
        puts("Error selected.");
        return;
    }
    list[id - 1].booked_status = false;
}

void menu(void) {
    puts("To choose a function, enter its letter label: ");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Confirm a seat assigment");
    puts("f) Delete a seat assignment");
    puts("g) Quit");
}