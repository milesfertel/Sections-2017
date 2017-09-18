#include <cs50.h>
#include <stdio.h>

// Prints out the index of a value x in an array of length n if it exists, else -1
int linear(int x, int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, string argv[])
{
    int arr[] = {4, 6, 7, -1, 0, 5, 8};
    int x = atoi(argv[1]);
    printf("Index: %d\n", linear(x, arr, sizeof(arr)/sizeof(int)));
}