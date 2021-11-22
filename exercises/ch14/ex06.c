//
// Created by HRF on 2021/11/17.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define FIEL_PATH "exercises/ch14/files/baseball_team.dat"
#define LEN 15

struct player {
    int id;
    char first_name[20];
    char last_name[20];
    int game_times;
    int hit_num;
    int base_num;
    int RBI;
    float BABIP;
};
void read_data(struct player list[], FILE * fp);
void set_babip(struct player list[], int n);
void get_info(struct player list[], int n);
int get_list_index(struct player list[], int n, int id, int cur_index);

struct player players[LEN];

int main(void) {
    FILE *fp;

    if ((fp = fopen(FIEL_PATH, "r")) == NULL) {
        printf("Can't open the file %s\n", FIEL_PATH);
        exit(EXIT_FAILURE);
    }
    read_data(players, fp);
    set_babip(players, LEN);
    get_info(players, LEN);

    fclose(fp);
    return 0;
}

void read_data(struct player list[], FILE * fp) {
    int id, game_times, hit_num, base_num, RBI;
    char first_name[20], last_name[20];
    int list_index;
    int list_length = 0;
    while ((fscanf(fp,
                   "%d %s %s %d %d %d %d",
                   &id, first_name, last_name, &game_times, &hit_num, &base_num, &RBI)) == 7) {
        list_index = get_list_index(list, LEN, id, list_length);
        if (list_index == list_length) {
            list_length++;
        }
        strcpy(list[list_index].first_name, first_name);
        strcpy(list[list_index].last_name, last_name);
        list[list_index].id = id;
        list[list_index].game_times += game_times;
        list[list_index].hit_num += hit_num;
        list[list_index].base_num += base_num;
        list[list_index].RBI += RBI;
    }
}

int get_list_index(struct player list[], int n, int id, int cur_index) {
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            return i;
        }
    }

    return cur_index;
}

void set_babip(struct player list[], int n) {
    for (int i = 0; i < n; i++) {
        list[i].BABIP = (float) list[i].hit_num / (float) list[i].game_times;
    }
}

void get_info(struct player list[], int n) {
    printf("ID: First_Name.Last_Name Game_Times Hit_Num Base_Num RBI BABIP\n");
    for (int i = 0; i < n; i++) {
        printf("%2d %10s.%-10s %5d %10d %7d %5d %5.2f\n",
               list[i].id, list[i].first_name, list[i].last_name,
               list[i].game_times, list[i].hit_num, list[i].base_num, list[i].RBI, list[i].BABIP);
    }
}