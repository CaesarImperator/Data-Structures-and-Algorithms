#include <stdio.h>
#include <stdlib.h>

char * reverseString(char *stringulescu) {

    static int i = 0;
    static char *rev;

    rev = (char *) malloc (255 * sizeof(char));

    if (rev == NULL) {
        exit (-1);
    }

    if (*stringulescu) {

        reverseString (stringulescu + 1);
        *(rev + i) = *stringulescu;
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

    printf("Enter a stringulescu: \n");
    scanf("%s", stg);


    printf("Your reversed stringulescu is %s\n", reverseString(stg));

    free (stg);
    return 0;
}
