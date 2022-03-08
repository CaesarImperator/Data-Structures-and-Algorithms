#include <stdio.h>
#include <stdlib.h>

struct myArray {

    int arraySize;
    int arr[];

};

int inputSize () {

    size_t size = 0;
    printf("Give me the size: ");
    scanf ("%zu", &size);
    while (getchar() != '\n');
    return size;

}


int main() {

    int size = inputSize();
    struct myArray *ptr = NULL;

    ptr = malloc (sizeof (struct myArray) + size * sizeof(int));

    ptr -> arraySize = size;



    for (int i = 0; i < (ptr -> arraySize); i++) {
        ptr -> arr[i] = 0;
    }


    for (int j = 0; j < (ptr -> arraySize); j++) {

        printf("%d\n", ptr -> arr[j]);

    }


    return 0;
}
