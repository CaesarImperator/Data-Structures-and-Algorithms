#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

void merge(int arr[], int temp[], int a1Lower, int a1Upper, int a2Lower, int a2Upper);
void copy(int arr[], int temp[], int lower, int upper);
void divideAndMerge(int arr[], int lower, int upper);

void merge(int arr[], int temp[], int a1Lower, int a1Upper, int a2Lower, int a2Upper) {

    int i = a1Lower;
    int j = a2Lower;
    int k = a1Lower;

    while ((i <= a1Upper) && (j <= a2Upper)) {

        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];

    }

    while (i <= a1Upper) {

        temp[k++] = arr[i++];

    }

    while (j <= a2Upper) {

        temp[k++] = arr[j++];

    }

}

void copy(int arr[], int temp[], int lower, int upper) {

    int i = 0;
    for(i = lower; i <= upper; i++)
        arr[i] = temp[i];

}

void divideAndMerge(int arr[], int lower, int upper) {

    int mid = 0;
    int temp[MAX];

    if(lower >= upper)
        return;

    mid = (lower + upper)/2;

    divideAndMerge(arr, lower, mid);
    divideAndMerge(arr, mid + 1, upper);

    merge(arr, temp, lower, mid, mid + 1, upper);

    copy(arr, temp, lower, upper);

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

    divideAndMerge(arr, 0, n - 1);

    printf("Sorted list is: \n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
