bool binarysearch(int value, int arr[], int first, int last)
{
    // if the "last" comes before the "first" then the element can't be in the array
    if (last < first)
    {
        return false;
    }

    // calculate the mid of the current array
    int mid = (first + last) / 2;

    // if we found what we're looking for in the middle, return true
    if (value == arr[mid])
    {
        return true;
    }

    // if the element at the mid is too large, repeat with the left half of the array
    else if (value < arr[mid])
    {
        return binarysearch(value, arr, first, mid - 1);
    }

    // otherwise, repeat with the right half of the array
    else
    {
        return binarysearch(value, arr, mid + 1, last);
    }
}