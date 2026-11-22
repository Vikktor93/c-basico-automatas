#include <stdio.h>
#include <stdbool.h>

bool es_par(int n);    /* prototipo, antes de main */

int main(void)
{
    for (int i = 1; i <= 10; i++) {
        if (es_par(i)) {
            printf("%d es par\n", i);
        } else {
            printf("%d es impar\n", i);
        }
    }
    return 0;
}

bool es_par(int n)     /* definición, después de main */
{
    return n % 2 == 0;
}