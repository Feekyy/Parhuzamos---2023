#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool Equlity(int array[], int n);

int main()
{
    printf("i was here!");
    
    srand(time(NULL));
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand();
        int r = rand()%10;
        if (r > 5)
        {
            array[i] = array[i]*2;
        }
    }
    
    printf("I was here!");
    
    if (Equlity(array, 10))
    {
        printf("All element are different!\n");
    }
    else
    {
        printf("There is some equlity!\n");
    }
    
    return 0;
}

bool Equlity(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; i++)
        {
            if (i != k)
            {
                if (array[i] == array[k]) return false; 
            }
        }
    }
    
    return true;
}
