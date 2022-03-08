#include <stdio.h>
#include <stdlib.h>

char * reverseString(char *str) {

    static int i = 0;
    static char *rev;

    rev = (char *) malloc (255 * sizeof(char));

    if (rev == NULL) {
        exit (-1);
    }

    if (*str) {

        reverseString (str + 1);
        *(rev + i) = *str;
        i++;


    }

    return rev;

}

int main()
{
    char *stg = NULL;

    stg = (char *) malloc (255 * sizeof(char));

    if (stg == NULL) {
        exit (-1);
    }

    printf("Enter a string: \n");
    scanf("%s", stg);


    printf("Your reversed string is %s\n", reverseString(stg));

    free (stg);
    return 0;
}
