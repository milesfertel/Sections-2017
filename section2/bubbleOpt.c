#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void bubble(char s[], int len)
{
    bool swapped;
    do {
        swapped = false;
        for (int j = 0; j < len - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                swapped = true;
                char tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
    while (swapped ==  true);
}

int main()
{
    char arr[] = "helloworld";
    int length = strlen(arr);
    // Should print dehllloorw
    bubble(arr, length);
    printf("%s\n", arr);
}