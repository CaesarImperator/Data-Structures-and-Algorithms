#include <stdio.h>
#include <stdlib.h>

#define MAX 64


int binarySearch(int arr[], int first, int last, int value) {

    if(first <= last) {

        int mid = (first + last)/2;

        if(value == arr[mid])
            return mid;

        else if(value < arr[mid])
            return binarySearch(arr, first, mid - 1, value);

        else
            return binarySearch(arr, mid + 1
                                , last, value);

    }

    return -1;

}

int main()
{
    int n = 0;
    int value = 0;
    int arr[MAX];

    printf("Enter number of elements of the array:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d (all elements in sorted order):\n", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter a value to search for:\n");
    scanf("%d", &value);

    binarySearch(arr, 0, n - 1, value);

    printf("Element you searched for is at index %d\n", binarySearch(arr, 0, n - 1, value));

    return 0;
}
