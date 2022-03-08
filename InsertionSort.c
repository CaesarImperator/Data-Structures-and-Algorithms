#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[14] = {2, 7, 3, 4, 90, 8, 6, 11, 16, 56, 34, 87, 109, 184};

    int temp = 0;

    for (int i = 1; i < 14; i++) {

        temp = arr[i];
        int j = 0;

        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
                arr[j + 1] = arr[j];

        arr[j + 1] = temp;

    }

    for (int i = 0; i <= 13; i++)
        printf("%d ", arr[i]);

    return 0;
}
