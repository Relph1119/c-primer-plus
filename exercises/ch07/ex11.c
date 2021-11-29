//
// Created by HRF on 2021/11/3.
//
#include <stdio.h>
#include <ctype.h>

// 洋蓟的售价
#define PRICE_ARTICHOKES 2.05
// 甜菜的售价
#define PRICE_BEETS 1.15
// 胡萝卜的售价
#define PRICE_CARROTS 1.09
// 打折优惠
#define DISCOUNT_RATE 0.05
// 少于或等于5磅订单的运费和包装费
#define UNDER_5 6.50
// 5~20磅订单的运费和包装费
#define UNDER_20 14.00
#define BASE_20 14.00
// 超过20磅订单徐总每磅增加的运费和包装费
#define EXTRAL 0.50

int main(void) {
    int ch;
    // 洋蓟的数量
    double lb_artichokes = 0;
    // 甜菜的数量
    double lb_beets = 0;
    // 胡萝卜的数量
    double lb_carrots = 0;
    double lb_temp;
    // 订购的总重量
    double lb_total;

    // 洋蓟的费用
    double cost_artichokes;
    // 甜菜的费用
    double cost_beets;
    // 胡萝卜的费用
    double cost_carrots;
    // 订单总费用
    double cost_total;
    // 最终的费用
    double final_total;
    // 折扣
    double discount = 0;
    // 运费和包装费
    double shipping = 0;

    printf("Enter a to buy artichokes, b for beets, c for carrots, q to quit:");
    while ((ch = getchar()) != 'q' && ch != 'Q') {
        if (ch == '\n')
            continue;
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);

        switch (ch) {
            case 'a' :
                // 输入洋蓟的数量
                printf("Enter pounds of artichokes: ");
                scanf("%lf", &lb_temp);
                lb_artichokes += lb_temp;
                break;
            case 'b' :
                // 输入甜菜的数量
                printf("Enter pounds of beets: ");
                scanf("%lf", &lb_temp);
                lb_beets += lb_temp;
                break;
            case 'c' :
                // 输入胡萝卜的数量
                printf("Enter pounds of carrots: ");
                scanf("%lf", &lb_temp);
                lb_carrots += lb_temp;
                break;
            default :
                printf("%c is not a valid choice.\n", ch);
        }
        printf("Enter a to buy artichokes, b for beets, c for carrots, q to quit:");
    }

    // 计算各类蔬菜的费用
    cost_artichokes = PRICE_ARTICHOKES * lb_artichokes;
    cost_beets = PRICE_BEETS * lb_beets;
    cost_carrots = PRICE_CARROTS * lb_carrots;
    // 计算订购的总费用
    cost_total = cost_artichokes + cost_beets + cost_carrots;
    // 计算订购的总重量
    lb_total = lb_artichokes + lb_beets + lb_carrots;
    // 根据总重量进行运费分类
    if (lb_total <= 0)
        shipping = 0.0;
    else if (lb_total <= 5.0)
        shipping = UNDER_5;
    else if (lb_total < 20)
        shipping = UNDER_20;
    else
        shipping = BASE_20 + EXTRAL * lb_total;

    if (cost_total > 100)
        discount = DISCOUNT_RATE * cost_total;

    // 计算最终的费用
    final_total = cost_total + shipping - discount;

    printf("Your order:\n");
    // 打印洋蓟的购买信息
    printf("%.2f lbs of artichokes at $%.2f per pound: $%.2f\n",
           lb_artichokes, PRICE_ARTICHOKES, cost_artichokes);
    // 打印甜菜的购买信息
    printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n",
           lb_beets, PRICE_BEETS, cost_beets);
    // 打印胡萝卜的购买信息
    printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n",
           lb_carrots, PRICE_CARROTS, cost_carrots);
    // 打印蔬菜的总费用
    printf("Total cost of vegetables: $%.2f\n", cost_total);
    if (cost_total > 100)
        // 打印折扣
        printf("Volume discount: $%.2f\n", discount);
    // 打印运费和包装费
    printf("Shipping: $%.2f\n", shipping);
    // 打印所有的费用总额
    printf("Total charges: $%.2f\n", final_total);

    return 0;
}