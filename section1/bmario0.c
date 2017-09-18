#include <stdio.h>

int main()
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 && height > 23);

    for (int row = 0; row < height; row++)
    {
        for (int i = 0; i < height - row; i++)
        {
            printf(" ");
        }
        for (int i = 0; i < row + 2; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}