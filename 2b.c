#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if key is at mid
        if (arr[mid] == key)
        {
            return mid;
        }

        // If key is greater, ignore left half
        if (arr[mid] < key)
        {
            low = mid + 1;
        }

        // If key is smaller, ignore right half
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Key not found
}

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Main function
int main()
{
    // Sorted array
    int arr[] = {2, 4, 10, 15, 18, 23, 32};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 15;

    printf("Array:\n");
    printArray(arr, n);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
    {
        printf("Element %d found at index %d.\n", key, result);
    }
    else
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}