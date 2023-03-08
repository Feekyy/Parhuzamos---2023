#include <stdio.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int r1 = rand();
  int r2 = rand();
  int end = r1 + r2;
  int n;
  clock_t begin = clock();
  printf("Count it Slave: %d + %d = ", r1, r2);
  while(scanf("%d",&n) != 1)
  {
      printf("Wrong! Count it Slave: %d + %d = ", r1, r2);
      while(getchar() != '\n' && n == end);
  }
  clock_t stop = clock();
  double time = (double)(stop - begin) / CLOCKS_PER_SEC;
  printf("Finally! You took my time: %f", time);

  return 0;
}
