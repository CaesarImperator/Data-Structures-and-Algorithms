#include <stdio.h>
#include <stdlib.h>
#define LARGE_VALUE 99999

void insert(int arr[], int *ptr, int value);
void heapifyUp(int arr[], int i);
void heapifyDownRoot(int arr[], int i, int n);
void deleteRoot(int arr[], int *ptr);

void insert(int arr[], int *ptr, int value) {

     (*ptr)++;
     arr[*ptr] = value;
     heapifyUp(arr, *ptr);

}

void heapifyUp(int arr[], int i) {

    int valueToHeapify = arr[i];

    while (arr[i/2] < valueToHeapify) {

        arr[i] = arr[i/2];
        i = i/2;

    }

    arr[i] = valueToHeapify;

}

void heapifyDownRoot(int arr[], int i, int n) {

    int lchild = 2 * i;
    int rchild = 2 * i + 1;
    int temp = 0;
    int chosenChild = 0;

    if(arr[i] > arr[rchild] && arr[i] > arr[lchild]) {

        printf("Heap property had not been satisfied previously, root was deleted without heapification...\n");
        return;

    }

    else if(arr[i] < arr[rchild] && arr[i] < arr[lchild]){

        if(lchild < n && arr[lchild] > arr[rchild]) {

            chosenChild = lchild;

            }

        else if(rchild < n)

            chosenChild = rchild;

        temp = arr[i];
        arr[i] = arr[chosenChild];
        arr[chosenChild] = temp;

        heapifyDownRoot(arr, chosenChild, n);

    }

    else if(arr[i] < arr[rchild] && arr[i] > arr[lchild]) {

            chosenChild = rchild;

            temp = arr[i];
            arr[i] = arr[chosenChild];
            arr[chosenChild] = temp;

            heapifyDownRoot(arr, chosenChild, n);

    }

    else {

            chosenChild = lchild;

            temp = arr[i];
            arr[i] = arr[chosenChild];
            arr[chosenChild] = temp;

            heapifyDownRoot(arr, chosenChild, n);

    }


}

void deleteRoot(int arr[], int *ptr) {

    arr[1] = arr[*ptr];
    (*ptr)--;
    heapifyDownRoot(arr, 1, *ptr);

}


int main()
{
    int arr[50];
    arr[0] = LARGE_VALUE;
    int n = 0;
    int choice = 0;
    int value = 0;

    while(1)
    {
        printf("1. Insert a node \n");
        printf("2. Delete root \n");
        printf("3. Display the heap \n");
        printf("4. Exit \n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter a value to insert (smaller than 99999):\n");
                scanf("%d", &value);
                insert(arr, &n, value);
                printf("Heap is now:\n");
                for(int i = 1; i <= n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                printf("Heap has %d elements\n\n", n);

                break;
            case 2:
                deleteRoot(arr, &n);
                break;
            case 3:
                for(int i = 1; i <= n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            case 4:
                exit(1);

        }
    }





    return 0;
}
