#include <cs50.h>
#include <stdio.h>

// Prints out the xth fibonacci number
int fib(int x) {
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }

    return fib(x - 1) + fib(x - 2);
}

int main(int argc, string argv[])
{
    int x = atoi(argv[1]);
    printf("%d\n", fib(x));
}