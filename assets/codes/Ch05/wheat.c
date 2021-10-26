/* wheat.c -- exponential growth */
#include <stdio.h>
#define SQUARES 64             // squares on a checkerboard
int main(void)
{
    const double CROP = 2E16;  // world wheat production in wheat grains
    double current, total;
    int count = 1;
    
    printf("square     grains       total     ");
    printf("fraction of \n");
    printf("           added        grains    ");
    printf("world total\n");
    total = current = 1.0; /* start with one grain   */
    printf("%4d %13.2e %12.2e %12.2e\n", count, current,
           total, total/CROP);
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;
        /* double grains on next square */
        total = total + current;     /* update total */
        printf("%4d %13.2e %12.2e %12.2e\n", count, current,
               total, total/CROP);
    }
    printf("That's all.\n");
    
    return 0;
}
