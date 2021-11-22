//
// Created by HRF on 2021/11/16.
//
#include <stdio.h>
#include <string.h>

#define LEN 14
#define SCORES 3
#define CSIZE 4

struct name {
    char first_name[LEN];
    char last_name[LEN];
};

struct student {
    struct name person;
    float grade[SCORES];
    float avg;
};

void get_scores(struct student arr[], int n);
void find_avg(struct student arr[], int n);
void show_students(const struct student arr[], int n);
void show_ave(const struct student arr[], int n);

int main(void) {
    struct student students[CSIZE] = {
            {"Flip",  "Snide"},
            {"Clare", "Voyans"},
            {"Bingo", "Higgs"},
            {"Fawn",  "Hunter"}
    };

    get_scores(students, CSIZE);
    find_avg(students, CSIZE);
    show_students(students, CSIZE);
    show_ave(students, CSIZE);
    return 0;
}

void get_scores(struct student arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("Please enter %d scores for %s %s:\n",
               SCORES, arr[i].person.first_name, arr[i].person.last_name);

        for (j = 0; j < SCORES; j++) {
            while (scanf("%f", &arr[i].grade[j]) != 1) {
                scanf("%*s");
                puts("Please use numeric input.");
            }
        }
    }
}

void find_avg(struct student arr[], int n) {
    int i, j;
    float sum;

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < SCORES; j++) {
            sum += arr[i].grade[j];
        }
        arr[i].avg = sum / SCORES;
    }
}

void show_students(const struct student arr[], int n) {
    int i, j;
    char full_name[2*LEN];

    for (i = 0; i < n; i++) {
        strcpy(full_name, arr[i].person.first_name);
        strcat(full_name, " ");
        strcpy(full_name, arr[i].person.last_name);
        printf("%15s: ", full_name);
        for (j = 0; j < SCORES; j++) {
            printf("%6.1f ", arr[i].grade[j]);
        }
        printf(" Average = %5.2f\n", arr[i].avg);
    }
}
void show_ave(const struct student arr[], int n) {
    int i, j;
    float total;

    printf("\n%15s: ", "QUIZ AVERAGES");
    for (j = 0; j < SCORES; j++) {
        total = 0;
        for (i = 0; i < n; i++) {
            total += arr[i].grade[j];
        }
        printf("%6.2f ", total / (float) n);
    }

    total = 0;
    for (i = 0; i < n; i++) {
        total += arr[i].avg;
    }
    printf("     All = %5.2f\n", total / (float) n);
}