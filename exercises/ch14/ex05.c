//
// Created by HRF on 2021/11/16.
//
#include <stdio.h>
#include <string.h>

#define LEN 21
#define SCORES 3
#define CSIZE 4

// 姓名
struct name {
    char first_name[LEN];
    char last_name[LEN];
};

// 学生
struct student {
    struct name person;
    // 分数
    float grade[SCORES];
    // 平均值
    float avg;
};

void input_scores(struct student arr[], int n);

void calc_avg(struct student arr[], int n);

void show_students(const struct student arr[], int n);

void show_ave(const struct student arr[], int n);

int main(void) {
    // 初始化人员信息
    struct student students[CSIZE] = {
            {"Flip",  "Snide"},
            {"Clare", "Voyans"},
            {"Bingo", "Higgs"},
            {"Fawn",  "Hunter"}
    };
    // d.输入学生成绩
    input_scores(students, CSIZE);
    // e.计算平均值
    calc_avg(students, CSIZE);
    // f. 打印每个学生的信息
    show_students(students, CSIZE);
    // g. 打印所有学生的平均值
    show_ave(students, CSIZE);
    return 0;
}

void input_scores(struct student arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        // 提示用户输入学生成绩
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

void calc_avg(struct student arr[], int n) {
    int i, j;
    float sum;

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < SCORES; j++) {
            sum += arr[i].grade[j];
        }
        // 计算平均值
        arr[i].avg = sum / SCORES;
    }
}

void show_students(const struct student arr[], int n) {
    int i, j;
    // 全名
    char full_name[2 * LEN];

    printf("\nHere is student's score list:\n");
    for (i = 0; i < n; i++) {
        strcpy(full_name, arr[i].person.first_name);
        strcat(full_name, " ");
        strcat(full_name, arr[i].person.last_name);
        // 打印全名
        printf("%15s: ", full_name);
        for (j = 0; j < SCORES; j++) {
            printf("%6.1f ", arr[i].grade[j]);
        }
        // 打印平均分
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
            // 计算总成绩
            total += arr[i].grade[j];
        }
        // 打印该科总平均分
        printf("%6.2f ", total / (float) n);
    }

    total = 0;
    for (i = 0; i < n; i++) {
        total += arr[i].avg;
    }
    // 打印所有成绩的平均分
    printf("     All = %5.2f\n", total / (float) n);
}