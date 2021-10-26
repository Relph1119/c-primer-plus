/* convert.c -- automatic type conversions */
#include <stdio.h>
int main(void)
{
    char ch;
    int i;
    float fl;
    
    fl = i = ch = 'C';                                  /* line 9  */
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); /* line 10 */
    ch = ch + 1;                                        /* line 11 */
    i = fl + 2 * ch;                                    /* line 12 */
    fl = 2.0 * ch + i;                                  /* line 13 */
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); /* line 14 */
    ch = 1107;                                          /* line 15 */
    printf("Now ch = %c\n", ch);                        /* line 16 */
    ch = 80.89;                                         /* line 17 */
    printf("Now ch = %c\n", ch);                        /* line 18 */
    
    return 0;
}
