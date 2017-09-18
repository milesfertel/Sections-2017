#include <cs50.h>
#include <stdio.h>

long factorial(long x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}

int main (int argc, string argv[])
{
    long x = (long)atoi(argv[1]);
    printf("%lu\n", factorial(x));
}