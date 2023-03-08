#include <stdio.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int r = rand()%1000 + 500;
  printf("asdasd %d", r);

  return 0;
}
