//
// Created by HRF on 2021/10/31.
//
#include <stdio.h>
// 1加仑大约3.785升
#define LITER_PER_GALLONS 3.785
// 1英里大约1.609千米
#define KILOMETERS_PER_MILE 1.609

int main(void) {
    float miles, oils;

    // 输入旅行的里程
    printf("Enter a mileage of journey(mile):");
    scanf("%f", &miles);
    // 输入消耗的汽油量
    printf("Enter an amount of gasoline to cost(gallon):");
    scanf("%f", &oils);
    // 计算并显示消耗每加仑汽油行驶的英里数（美国方案）
    printf("In UAS, your oil wear is %.1f M/G\n", miles / oils);
    // 计算并显示消耗每升汽油行驶的百公里数（欧洲方案）
    printf("In Europe, your oil wear is %.1f L/100KM\n",
           (oils * LITER_PER_GALLONS) / (miles * KILOMETERS_PER_MILE / 100));

    return 0;
}