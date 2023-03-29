#include <stdio.h>

void sumArraysInts(int array[], int n);
void minCount(int array[], int n);
void maxCount(int array[], int n);
int minCountREC(int array[], int n);
int maxCountREC(int array[], int n);

int main()
{
    int size = 0;
    
    printf("Please enter an array size: ");
    while(scanf("%d",&size) != 1)
    {
        printf("Please enter an integer: ");
        while(getchar() != '\n');
    }
    
    int array[size];
    
    printf("Now please, give me %d number!\n", size);
    for (int i = 0; i < size; i++)
    {
        while(scanf("%d", &array[i]) != 1)
        {
            printf("Please enter an integer: ");
            while(getchar() != '\n');
        }
    }
    
    sumArraysInts(array, size);
    minCount(array, size);
    maxCount(array, size);
    printf("Minimal interger is %d!\n", minCountREC(array, size));
    printf("Maximal interger is %d!\n", maxCountREC(array, size));
    
    
    return 0;
}

void sumArraysInts(int array[], int n)
{
    int sum = array[0];
    for (int i = 1; i < n; i++)
    {
        sum += array[i];
    }
    printf("Summary is %d!\n", sum);
}

void minCount(int array[], int n)
{
    int min = array[0];
    for (int i = 1; i < n; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    printf("Minimum integer in the array is %d!\n", min);
}

void maxCount(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    printf("Maximal integer in the array is %d!\n", max);
}

int minCountREC(int array[], int n)
{
    if (n > 1)
    {
        int m = minCountREC(array, n-1);
        if (array[n-1] < m)
        {
            return array[n-1];
        }
        else return m;
    }
    else
    {
       return array[0];
    }
}

int maxCountREC(int array[], int n)
{
    if (n > 1)
    {
        int m = maxCountREC(array, n-1);
        if (array[n-1] > m)
        {
            return array[n-1];
        }
        else return m;
    }
    else
    {
       return array[0];
    }
}