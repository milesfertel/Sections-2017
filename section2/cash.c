#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main ()
{
    float change;
    do
    {
        printf("Change: ");
        change = get_float();
    }
    while (change < 0);

    int cointypes[] = {25, 10, 5};
    int cents = round(change * 100);
    int coins = 0;

    for (int i = 0, ncointypes = sizeof(cointypes)/sizeof(int); i < ncointypes; i++)
    {

        coins += cents / cointypes[i];
        cents %= cointypes[i];
    }
    coins += cents;
    printf("%d\n", coins);
}