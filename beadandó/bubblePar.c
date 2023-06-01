#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100000
#define ARR 500000

void generateRandoms(int array[]);
void printIntArr(int array[]);
void bubbleSorter(int array[]);

int array[ARR];

int main()
{
  generateRandoms(array);
  double start_time = omp_get_wtime();
  bubbleSorter(array);
  double end_time = omp_get_wtime();
  printf("Sorting time: %f seconds\n", (end_time - start_time));

  return 0;
}

void printIntArr(int array[])
{
  printf("\nArrays: ");
  for (int i = 0; i <ARR; i++) printf("%d ", array[i]);
  printf("\n");
}

void generateRandoms(int array[])
{
  srand(time(NULL));
  for (int i = 0; i < ARR; i++)
  {
    array[i] = rand() % MAX;
  }
}

void bubbleSorter(int array[])
{
  bool swap = true;
  int condition = 0;
  do
  {
    #pragma omp parallel if(condition % 3 == 0 && swap)
    swap = false;
    for (int i = 0; i <ARR-1; i++)
    {
      if (array[i] > array[i+1])
      {
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        swap = true;
        condition++;
      }
    }
  } while (swap);
}
