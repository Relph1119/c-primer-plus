//
// Created by HRF on 2021/11/23.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

void init_list(int nums[], int n);

void show_list(int nums[], int n);

int list_compare(const void *p1, const void *p2);

bool inarray(const int arr[], int n, int val);

int main(void) {
    int nums[SIZE];
    init_list(nums, SIZE);
    int num;
    bool found;

    puts("There are UNSORTED numbers list :");
    show_list(nums, SIZE);

    qsort(nums, SIZE, sizeof(int), list_compare);

    puts("There are SORTED numbers list :");
    show_list(nums, SIZE);

    printf("Enter an integer to search for:");
    while (scanf("%d", &num) == 1) {
        found = inarray(nums, SIZE, num);
        printf("%d %s in the array.\n", num, found ? "is" : "isn't");
        printf("Enter next integer to search (q to quit): ");
    }
    printf("Bye.\n");

    return 0;
}

bool inarray(const int arr[], int n, int val) {
    int min = 0;
    int max = n - 1;
    int mid;
    bool found = false;

    while (min < max) {
        mid = (min + max) / 2;
        if (val < arr[mid])
            max = mid - 1;
        else if (val > arr[mid])
            min = mid + 1;
        else {
            found = true;
            break;
        }
    }

    if (arr[min] == val)
        found = true;

    return found;
}

int list_compare(const void *p1, const void *p2) {
    const int *ps1 = (const int *) p1;
    const int *ps2 = (const int *) p2;

    if (*ps1 > *ps2)
        return 1;
    else if (*ps1 == *ps2)
        return 0;
    else
        return -1;
}

void init_list(int nums[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        nums[i] = rand() % 100 + 1;
}

void show_list(int nums[], int n) {
    for (int i = 0; i < n; i++)
        printf(" %d", nums[i]);
    putchar('\n');
}
