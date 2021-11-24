//
// Created by HRF on 2021/10/27.
//
#include <stdio.h>
int main(void){
    // 1品脱等于2杯
    float cup_per_pint = 2;
    // 1杯等于8盎司
    float oz_per_cup = 8;
    // 1盎司等于2大汤勺
    float tbs_per_oz = 2;
    // 1大汤勺等于3茶勺
    float tsp_per_tbs = 3;

    float num_cup;
    // 提示用户输入杯数
    printf("Enter the num of Cup:");
    scanf("%f", &num_cup);
    // 以品脱显示容量
    printf("%g(cup) of pint is %g.\n", num_cup, num_cup / cup_per_pint);
    // 以盎司显示容量
    printf("%g(cup) of ounce is %g.\n", num_cup, num_cup * oz_per_cup);
    // 以汤勺显示容量
    printf("%g(cup) of tablespoon is %g.\n", num_cup, num_cup * oz_per_cup * tbs_per_oz);
    // 以茶勺显示容量
    printf("%g(cup) of teaspoon is %g.\n", num_cup, num_cup * oz_per_cup * tbs_per_oz * tsp_per_tbs);

    return 0;
}
