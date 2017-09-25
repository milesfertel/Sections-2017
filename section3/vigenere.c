#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_ALPHA 26

char shift(char base, int off);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You bad\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);
    int keyindex = 0;
    for (int i = 0; i < keylen; i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
        }
    }

    printf("plaintext: ");
    string name = get_string();

    printf("ciphertext: ");
    for (int i = 0, len = strlen(name); i < len; i++)
    {
        char cipherchar = key[keyindex % keylen];
        if (isupper(cipherchar))
        {
            cipherchar = shift(name[i], cipherchar - 'A');
        }
        else
        {
            cipherchar = shift(name[i], cipherchar - 'a');
        }

        printf("%c", cipherchar);
        keyindex++;
    }
    printf("\n");
}

char shift(char base, int off)
{
    if (isalpha(base))
    {
        if (isupper(base))
        {
            return 'A' + ((base - 'A' + off) % LEN_ALPHA);
        }
        else
        {
            return 'a' + ((base - 'a' + off) % LEN_ALPHA);
        }
    }
    else
    {
        return base;
    }
}
