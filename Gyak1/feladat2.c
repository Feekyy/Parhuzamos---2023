#include <stdio.h>

int main()
{
    long long int input;
    int ok = 0;
    do
    {
        printf("Enter a number with max. 8 digits: ");
        scanf("%lld", &input);
        if (input < 100000000)
        {
            ok = 1;
        }
    } while (!ok);

    while (input > 100000000)
    {
       input /= 10;
    }
    printf("%08lld\n", input);
    printf("%8lld", input);

    return 0;
}
