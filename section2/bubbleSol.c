#include <cs50.h>
#include <stdio.h>
#include <string.h>

// How can we optimize this?
void bubble(char s[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                char tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    char arr[] = "helloworld";
    int length = strlen(arr);
    // Should print dehllloorw
    bubble(arr, length);
    printf("%s\n", arr);
}