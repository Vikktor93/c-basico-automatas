#include <stdio.h>
#include <stdbool.h>

bool es_par(int n);

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        bool par = es_par(i);
        if (par)
            printf("%d es par\n", i);
        else
            printf("%d es impar\n", i);
    }

    return 0;
}

bool es_par(int n) 
{
    if (n % 2 == 0)
        return true;
    else
        return false;
}