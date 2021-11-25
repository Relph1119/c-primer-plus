//
// Created by HRF on 2021/11/2.
//
#include <stdio.h>

int main(void) {
    int first_oper, second_oper;

    printf("This program computes moduli.\n");
    // 提示用户输入求模运算的第2个运算对象
    printf("Enter an integer to serve as the second operand:");
    scanf("%d", &second_oper);

    // 提示用户输入第1个运算对象
    printf("Now enter the first operand:");
    scanf("%d", &first_oper);
    // 循环判断第1个运算对象是否大于0
    while (first_oper > 0) {
        // 计算并打印求模结果
        printf("%d %% %d is %d\n", first_oper, second_oper, first_oper % second_oper);
        // 提示用户再次输入第1个运算对象
        printf("Enter next number for first operand (<= 0 to quit):");
        scanf("%d", &first_oper);
    }
    printf("Done\n");

    return 0;
}