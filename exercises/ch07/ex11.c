//
// Created by HRF on 2021/11/3.
//
#include "stdio.h"
#include "ctype.h"

#define PRICE_ARTICHOKES 2.05
#define PRICE_BEETS 1.15
#define PRICE_CARROTS 1.09
#define DISCOUNT_RATE 0.05
#define UNDER_5 6.50
#define UNDER_20 14.00
#define BASE_20 14.00
#define EXTRAL 0.50

int main(void) {
    char ch;
    double lb_artichokes = 0;
    double lb_beets = 0;
    double lb_carrots = 0;
    double lb_temp;
    double lb_total;

    double cost_artichokes;
    double cost_beets;
    double cost_carrots;
    double cost_total;
    double final_total;
    double discount;
    double shipping;

    while ((ch = getchar()) != 'q' && ch != 'Q') {
        if (ch == '\n')
            continue;
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);

        switch (ch) {
            case 'a' :
                printf("Enter pounds of artichokes: ");
                scanf("%lf", &lb_temp);
                lb_artichokes += lb_temp;
                break;
            case 'b' :
                printf("Enter pounds of beets: ");
                scanf("%lf", &lb_temp);
                lb_beets += lb_temp;
                break;
            case 'c' :
                printf("Enter pounds of carrots: ");
                scanf("%lf", &lb_temp);
                lb_carrots += lb_temp;
                break;
            default :
                printf("%c is not a valid choice.\n", ch);
        }
        printf("Enter a to buy artichokes, b for beets, ");
        printf("c for carrots, q to quit:");
    }

    cost_artichokes = PRICE_ARTICHOKES * lb_artichokes;
    cost_beets = PRICE_BEETS * lb_beets;
    cost_carrots = PRICE_CARROTS * lb_carrots;
    cost_total = cost_artichokes + cost_beets + cost_carrots;
    lb_total = lb_artichokes + lb_beets + lb_carrots;
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

    final_total = cost_total + shipping - discount;

    printf("Your order:\n");
    printf("%.2f lbs of artichokes at $%.2f per pound: $%.2f\n",
           lb_artichokes, PRICE_ARTICHOKES, cost_artichokes);
    printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n",
           lb_beets, PRICE_BEETS, cost_beets);
    printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n",
           lb_carrots, PRICE_CARROTS, cost_carrots);
    printf("Total cost of vegetables: $%.2f\n", cost_total);
    if (cost_total > 100)
        printf("Volume discount: $%.2f\n", discount);
    printf("Shipping: $%.2f\n", shipping);
    printf("Total charges: $%.2f\n", final_total);

    return 0;
}