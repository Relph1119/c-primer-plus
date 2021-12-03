//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <math.h>

// 定义极坐标的结构
struct polar {
    double r;
    double theta;
};
// 定义直角坐标的结构
struct rect {
    double x;
    double y;
};

// 极坐标转直角坐标
struct rect polar_to_rect(const struct polar * p);

int main(void) {
    struct polar input;
    struct rect result;

    // 提示用户输入向量的模和角度
    printf("Enter magnitude and angle in degrees:");
    while (scanf("%lf %lf", &input.r, &input.theta) == 2) {
        // 将极坐标转换成直角坐标
        result = polar_to_rect(&input);
        // 打印结果
        printf("Polar Coord: %g %g\n", input.r, input.theta);
        printf("Rectangular Coord: %g %g\n", result.x, result.y);
        printf("Enter magnitude and angle in degrees (q to quit):");
    }

    printf("Bye\n");
    return 0;
}

struct rect polar_to_rect(const struct polar * p) {
    static const double deg_rad = M_PI / 180.0;
    struct rect result;
    // 得到弧度
    double ang = deg_rad * p->theta;

    // 计算直角坐标的两个值
    result.x = p->r * cos(ang);
    result.y = p->r * sin(ang);

    return result;
}