//
// Created by HRF on 2021/11/17.
//
#include <string.h>
#include <stdio.h>

#define SEATS 12
#define LEN 20

struct plane_seat {
    // 座位编号
    int id;
    // 座位是否已被预定
    int booked_status;
    // 预订人的名
    char first_name[LEN];
    // 预订人的姓
    char last_name[LEN];
};
// 显示菜单
static void menu(void);
// 显示空座位的总数
static void get_empty(struct plane_seat list[]);
// 显示空座位
static void show_empty(struct plane_seat list[]);
// 显示已预订座位
static void show_booked(struct plane_seat list[]);
// 预订座位
static void book_seat(struct plane_seat list[]);
// 取消预订座位
static void cancel_book(struct plane_seat list[]);
// 初始化座位
static void init_seats(struct plane_seat list[]);

int main(void) {
    char selected;
    struct plane_seat seats[SEATS];

    // 初始化座位
    init_seats(seats);
    // 显示菜单
    menu();
    while ((selected = getchar()) != 'f') {
        switch (selected) {
            case 'a':
                // 显示空座位的总数
                get_empty(seats);
                break;
            case 'b':
                // 显示空座位
                show_empty(seats);
                break;
            case 'c':
                // 显示已预订座位
                show_booked(seats);
                break;
            case 'd':
                // 预订座位
                book_seat(seats);
                break;
            case 'e':
                // 取消预订座位
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

static void init_seats(struct plane_seat list[]) {
    for (int i = 0; i < SEATS; i++) {
        list[i].id = i + 1;
        list[i].booked_status = 0;
        strcpy(list[i].first_name, "");
        strcpy(list[i].last_name, "");
    }
}

static void get_empty(struct plane_seat list[]) {
    int sum = 0;
    for (int i = 0; i < SEATS; i++) {
        // 仅统计未被预订的座位
        if (list[i].booked_status == 0) {
            sum++;
        }
    }
    printf("There are %d seats empty.\n", sum);
}

static void show_empty(struct plane_seat list[]) {
    printf("Empty Seats: ");
    for (int i = 0; i < SEATS; i++) {
        // 显示未被预订的座位
        if (list[i].booked_status == 0) {
            printf("%d ", i + 1);
        }
    }
    putchar('\n');
}

static void show_booked(struct plane_seat list[]) {
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

    puts("Alphabetical list:");
    for (int i = 0; i < SEATS; ++i) {
        if (pseat[i]->booked_status == 1) {
            printf("Seat No.%d book by %s, %s\n", pseat[i]->id, pseat[i]->first_name, pseat[i]->last_name);
        }
    }
}

static void book_seat(struct plane_seat list[]) {
    int id;
    char first_name[LEN], last_name[LEN];
    // 显示空座位
    show_empty(list);
    // 提示用户选择座位
    puts("Please select the seat:");
    scanf("%d", &id);
    int seat_no = id - 1;
    if (list[seat_no].booked_status == 1) {
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
    list[seat_no].booked_status = 1;
    puts("Booked!");
}

static void cancel_book(struct plane_seat list[]) {
    show_booked(list);
    int id;
    // 提示用户选择要取消预订的座位
    puts("Please select the seat to cancel:");
    scanf("%d", &id);
    if (list[id - 1].booked_status == 0) {
        puts("Error selected.");
        return;
    }
    list[id - 1].booked_status = 0;
}

static void menu(void) {
    puts("To choose a function, enter its letter label: ");
    puts("a) Show number of empty seats ");
    puts("b) Show list of empty seats ");
    puts("c) Show alphabetical list of seats ");
    puts("d) Assign a customer to a seat assignment ");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}