#include <stdio.h>
#include <stdbool.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }

    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        int checked = values[mid];
        if (checked == value)
        {
            return true;
        }
        else if (checked < value)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}