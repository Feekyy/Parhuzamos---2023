#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genFileRandInt(char filname[], int length);

int main()
{
    char name[] = {'a', 's', 'd', '.', 't', 'x', 't'};
    genFileRandInt(name, 1000000);
}

void genFileRandInt(char filename[], int length)
{
    clock_t begin1 = clock();
    FILE *file = fopen(filename, "wr");
    srand(time(NULL));
    clock_t begin2 = clock();
    for (int i = 0; i < length; i++)
    {
        int r = rand();
        fprintf(file, "%d\n", r);
    }
    clock_t stop2 = clock();
    printf("The time i wasted for generating random numbers: %f\n", (double)(stop2 - begin2) / CLOCKS_PER_SEC);
    fclose(file);
    clock_t stop1 = clock();
    printf("The time i wasted for creating the file: %f\n", (double)(stop1 - begin1) / CLOCKS_PER_SEC);
}
