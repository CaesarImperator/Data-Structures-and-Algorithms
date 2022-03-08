#include <stdio.h>
#include <stdlib.h>
#define LARGE_VALUE 99999

void heapify(int arr[], int n, int i) {

    for (int i = 1; i <= n; i++){

        int largest = i;
        int temp = 0;
        int l = 2 * i;
        int r = 2 * i + 1;

        if(l < n && arr[l] > arr[largest])
            largest = l;

        if(r < n && arr[r] > arr[largest])
            largest = r;

        if(largest != i) {

            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);

            }

        }

    }

int main()
{
    int a1[] = {LARGE_VALUE, 20, 33, 15, 6, 40, 60, 45, 16, 75, 10, 80, 12};
    //int a2[] = {LARGE_VALUE, 20, 33, 15, 6, 40, 60, 45, 16, 75, 10, 80, 12};

    int n = sizeof(a1)/sizeof(int);

    heapify(a1, n, 1);

    for (int i = 1; i <= n; i++)
        printf("%d ", a1[i]);

    return 0;
}
