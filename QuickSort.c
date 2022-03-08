#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64


int partition(int arr[], int lower, int upper) {

    int pivot = arr[lower];
    int i = lower + 1;
    int j = upper;
    int temp = 0;

    while (i < j) {

        while(arr[i] < pivot && i < upper)
            i++;
        while(arr[j] > pivot && j > lower)
            j--;

        if(i < j) {

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;

        }

    }

    arr[lower] = arr[j];
    arr[j] = pivot;

    return j;

}

void quickSort(int arr[], int lower, int upper) {

    int p = 0;

    if(lower >= upper)
        return;

    p = partition(arr, lower, upper);

    quickSort(arr, lower, p - 1);
    quickSort(arr, p + 1, upper);

}

int main()
{
    int n = 0;
    int arr[MAX];

    printf("Enter number of elements of the array:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d:\n", i+1);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted list is: \n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
