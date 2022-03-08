#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[14] = {2, 7, 3, 4, 90, 8, 6, 11, 16, 56, 34, 87, 109, 184};

    int sizeArr = 14;
    int temp = 0;
    int swaps = 0;

    for (int i = 0; i < sizeArr - 1; sizeArr--) {

        for (int j = 0; j < sizeArr; j++) {

            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }

        }

        if (swaps == 0)
                break;

    }

    for (int i = 0; i < 13; i++)
        printf("%d ", arr[i]);

    return 0;
}
