#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[14] = {2, 7, 3, 4, 90, 8, 6, 11, 16, 56, 34, 87, 109, 184};

    int minIndex = 0;
    int temp = 0;

    for (int i = 0; i < 14; i++) {

        minIndex = i;

        for (int j = i + 1; j < 14; j++) {

            if(arr[j]<arr[minIndex])
                minIndex = j;

        }

    if(i != minIndex) {

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        }

    }

    for (int i = 0; i < 13; i++)
        printf("%d ", arr[i]);

    return 0;
}
