#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genFileRandInt(char filname[], int length);

int main()
{
    char name[] = {'a', 's', 'd', '.', 't', 'x', 't'};
    genFileRandInt(name, 13);
}

void genFileRandInt(char filename[], int length)
{
    FILE *file = fopen(filename, "wr");
    srand(time(NULL));
    clock_t begin = clock()
    for (int i = 0; i < length; i++)
    {
        int r = rand();
        fprintf(file, "%d\n", r);
    }
    clock_t begin = clock()
    close(file)
}
