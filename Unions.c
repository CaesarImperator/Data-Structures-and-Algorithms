#include <stdio.h>
#include <stdlib.h>

union marks {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

int main()
{
    union marks myMarks1;
    union marks myMarks2;

    myMarks1.letterGrade = 'B';
    myMarks1.roundedGrade = 8;
    myMarks1.exactGrade = 8.25;

    printf ("Letter Grade: %c\n", myMarks1.letterGrade);
    printf ("Rounded Grade: %d\n", myMarks1.roundedGrade);
    printf ("Exact Grade: %.2f\n\n", myMarks1.exactGrade);


    myMarks2.letterGrade = 'B';
    printf ("Letter Grade: %c\n", myMarks2.letterGrade);

    myMarks2.roundedGrade = 8;
    printf ("Rounded Grade: %d\n", myMarks2.roundedGrade);

    myMarks2.exactGrade = 8.25;
    printf ("Exact Grade: %.2f\n", myMarks2.exactGrade);

    return 0;
}
