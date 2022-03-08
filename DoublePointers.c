#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a; // *p1 = a - malloc required?;
    p2 = &p1; // *p2 = p1 - malloc required?;

    //all possible ways to find the value of a:
    printf ("The value of a is %d\n", a);
    printf ("The dereferenced value of pointer p1 is %d\n", *p1);
    printf ("The dereferenced value of pointer p2 is %d\n\n", **p2);

    //all possible ways to find the address of a:
    printf ("The adress of a is %p\n", &a);
    printf ("The address of a pointed to by the first pointer is %p\n", p1);
    printf ("The address of a pointed to by the first pointer (but using the second pointer) is %p\n\n", *p2);

    //all possible ways to find the value of p1:
    printf ("The value of p1 is %p\n", p1);
    printf ("The dereferenced value of pointer p2 is %p\n\n", *p2);

    //all possible ways to find the address of p1:
    printf ("The adress of p1 is %p\n", &p1);
    printf ("The address of p1 pointed to by the second pointer is %p\n\n", p2);

    //all possible ways to find the value of p2:
    printf ("The value of p2 is %p\n\n", p2);

    //all possible ways to find the address of p2:
    printf ("The adress of p2 is %p\n\n", &p2);


    return 0;

}
