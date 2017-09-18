#include <stdio.h>
#include <string.h>

#define _XOPEN_SOURCE
#include <unistd.h>

int main()
{
    char rewrite[] = "AAAAAAAAAAAAAAAAAAAAAAAAA";
    int len = strlen(rewrite);
    for (int i = 0; i <= len * ('z' - 'A'); i++)
    {
        printf("%s\n", rewrite);
        usleep(10000);
        rewrite[i % len] += 1;
    }

}