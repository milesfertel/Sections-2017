#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

char shift(char base, int off);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You bad\n");
        return 1;
    }
    int off = atoi(argv[1]);
    
    printf("plaintext: ");
    string name = get_string();
    
    printf("ciphertext: ");
    for (int i = 0, len = strlen(name); i < len; i++)
    {
        char cipherchar = shift(name[i], off);
        printf("%c", cipherchar);
    }
    printf("\n");
}

char shift(char base, int off)
{
    if (isalpha(base))
    {
        if (isupper(base))
        {
            return 'A' + ((base - 'A' + off) % ALPHABET);
        }
        else
        {
            return 'a' + ((base - 'a' + off) % ALPHABET);
        }
    }
    else
    {
        return base;
    }
}
