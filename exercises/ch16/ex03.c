//
// Created by HRF on 2021/11/22.
//
#include <stdio.h>
#include <math.h>

struct polar {
    double r;
    double theta;
};

struct rect {
    double x;
    double y;
};
struct rect polar_to_rect(const struct polar * p);

int main(void) {
    struct polar input;
    struct rect result;

    printf("Enter magnitude and angle in degrees:");
    while (scanf("%lf %lf", &input.r, &input.theta) == 2) {
        result = polar_to_rect(&input);
        printf("Polar Coord: %g %f\n", input.r, input.theta);
        printf("Rectangular Coord: %g %g\n", result.x, result.y);
        printf("Enter magnitude and angle in degrees (q to quit):");
    }

    printf("Bye\n");
    return 0;
}

struct rect polar_to_rect(const struct polar * p) {
    static const double deg_rad = M_PI / 180.0;
    struct rect result;
    double ang = deg_rad * p->theta;

    result.x = p->r * cos(ang);
    result.y = p->r * sin(ang);

    return result;
}