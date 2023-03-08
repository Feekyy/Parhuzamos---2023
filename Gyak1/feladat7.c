#include <stdio.h>
#include <time.h>

int main()
{
    int n;
    printf("Please enter an integer: ");
    while(scanf("%d",&n) != 1)
    {
        printf("Please enter an integer: ");
        while(getchar() != '\n');
    }
    clock_t begin = clock();
    printf("We have %d piece prime number between 1 and %d!\n", countPrime(n), n);
    clock_t stop = clock();
    printf("The time i wasted for this: %f\n", (double)(stop - begin) / CLOCKS_PER_SEC);

    return 0;
}

int countPrime(int N)
{
  int counts = 0;
  for (int i = 2; i < N+1; i++)
  {
    for (int j = 2; j < i/2+1; j++)
    {
      if (i%j == 0)
      {
        counts++;
        break;
      }
    }
  }
  return N-counts-1;
}
