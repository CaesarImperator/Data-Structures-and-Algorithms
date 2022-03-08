#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int addingNumbers (int count, ...) {

    int sum = 0;

    va_list parg;
    va_start(parg, count);

    for (int i = 0; i < count; i++) {
        int num = va_arg(parg, int);
        sum += num;
    }

    va_end(parg);
    return sum;
}

int main()
{
    printf("%d\n", addingNumbers(4, 40, 50, 60, 500));

    return 0;
}
