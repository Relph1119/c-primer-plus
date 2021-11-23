// mall.c -- use the Queue interface
// compile with queue.c
#include <stdio.h>
#include <stdlib.h>    // for rand() and srand()
#include <time.h>      // for time()
#include "queue.h"     // change Item typedef

#define MIN_PER_HR 60.0

bool newcustomer(double x);   // is there a new customer?
Item customertime(long when); // set customer parameters


struct Booth {
    Queue line;
    int hours, perhour, wait_time;
    long cycle, cyclelimit, turnaways;
    long customers, served, sum_line, line_wait;
    double min_per_cust;
};

void init_booth_list(struct Booth list[], int n);

int main(void) {
    Item temp;
    struct Booth booth_list[2];

    init_booth_list(booth_list, 2);
    srand((unsigned int) time(0)); // random initializing of rand()

    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours for Queue1:");
    scanf("%d", &booth_list[0].hours);
    booth_list[0].cyclelimit = MIN_PER_HR * booth_list[0].hours;

    puts("Enter the number of simulation hours for Queue2:");
    scanf("%d", &booth_list[1].hours);
    booth_list[1].cyclelimit = MIN_PER_HR * booth_list[1].hours;

    puts("Enter the average number of customers per hour for Queue1:");
    scanf("%d", &booth_list[0].perhour);
    booth_list[0].min_per_cust = MIN_PER_HR / booth_list[0].perhour;

    puts("Enter the average number of customers per hour for Queue2:");
    scanf("%d", &booth_list[1].perhour);
    booth_list[1].min_per_cust = MIN_PER_HR / booth_list[1].perhour;

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

// x = average time, in minutes, between customers 
// return value is true if customer shows up this minute
bool newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when) {
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
