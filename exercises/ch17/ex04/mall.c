// mall.c -- use the Queue interface
// compile with queue.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

// 是否有新顾客到来
bool newcustomer(double x);
// 设置顾客的参数
Item customertime(long when);

struct Booth {
    Queue line;
    // 模拟的小时数
    int hours;
    // 每小时平均多少位顾客
    int perhour;
    // 从当前到Sigmund空闲所需的时间
    int wait_time;
    // 循环计数器、计数器的上限
    long cycle, cyclelimit;
    // 因队列已满被拒的顾客数量
    long turnaways;
    // 加入队列的顾客数量
    long customers;
    // 在模拟期间咨询过Sigmund的顾客数量
    long served;
    // 累计的队列总长
    long sum_line;
    // 队列累计的等待时间
    long line_wait;
    // 顾客到来的平均时间
    double min_per_cust;
};

// 初始化摊位
void init_booth_list(struct Booth list[], int n);

int main(void) {
    Item temp;
    struct Booth booth_list[2];

    // 初始化2个摊位
    init_booth_list(booth_list, 2);
    srand((unsigned int) time(0));

    // 对摊位进行初始化
    puts("Case Study: Sigmund Lander's Advice Booth");
    for(int i = 0; i < 2; i++) {
        printf("Enter the number of simulation hours for Queue%d:", i + 1);
        scanf("%d", &booth_list[i].hours);
        booth_list[i].cyclelimit = MIN_PER_HR * booth_list[i].hours;

        printf("Enter the average number of customers per hour for Queue%d:", i + 1);
        scanf("%d", &booth_list[i].perhour);
        booth_list[i].min_per_cust = MIN_PER_HR / booth_list[i].perhour;
    }

    // for循环
    for (int i = 0; i < 2; i++) {
        for (booth_list[i].cycle = 0; booth_list[i].cycle < booth_list[i].cyclelimit; booth_list[i].cycle++) {
            if (newcustomer(booth_list[i].min_per_cust)) {
                if (QueueIsFull(&booth_list[i].line))
                    booth_list[i].turnaways++;
                else {
                    booth_list[i].customers++;
                    temp = customertime(booth_list[i].cycle);
                    EnQueue(temp, &booth_list[i].line);
                }
            }
            if (booth_list[i].wait_time <= 0 && !QueueIsEmpty(&booth_list[i].line)) {
                DeQueue(&temp, &booth_list[i].line);
                booth_list[i].wait_time = temp.processtime;
                booth_list[i].line_wait += booth_list[i].cycle - temp.arrive;
                booth_list[i].served++;
            }
            if (booth_list[i].wait_time > 0)
                booth_list[i].wait_time--;
            booth_list[i].sum_line += QueueItemCount(&booth_list[i].line);
        }

        if (booth_list[i].customers > 0) {
            printf("customers accepted for Queue%d: %ld\n", i + 1, booth_list[i].customers);
            printf("  customers served for Queue%d: %ld\n", i + 1, booth_list[i].served);
            printf("       turnaways for Queue%d: %ld\n", i + 1, booth_list[i].turnaways);
            printf("average queue size for Queue%d: %.2f\n",
                   i + 1, (double) booth_list[i].sum_line / booth_list[i].cyclelimit);
            printf(" average wait time for Queue%d: %.2f minutes\n",
                   i + 1, (double) booth_list[i].line_wait / booth_list[i].served);
            printf("\n");
        } else
            printf("No customers for Queue%d!", i + 1);
        EmptyTheQueue(&booth_list[i].line);
    }

    puts("Bye!");

    return 0;
}

void init_booth_list(struct Booth list[], int n) {
    for (int i = 0; i < n; i++) {
        InitializeQueue(&list[i].line);
        list[i].turnaways = 0;
        list[i].customers = 0;
        list[i].served = 0;
        list[i].sum_line = 0;
        list[i].wait_time = 0;
        list[i].line_wait = 0;
    }
}

/*
 * x是顾客到来的平均时间（单位：分钟）
 * 如果1分钟内有顾客到来，则返回true
 */
bool newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

/*
 * when是顾客到来的时间
 * 该函数返回一个Item结构，该顾客到来的时间设置为when，咨询时间设置为1~3的随机值
 */
Item customertime(long when) {
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
