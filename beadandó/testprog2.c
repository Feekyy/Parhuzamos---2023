#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
  FILE *file;
  file = fopen("testfile.txt", "w+");
      srand(time(NULL));
  for (int i = 0; i < 1500000; i++)
  {
    int r = (rand()%10)+1;
    fprintf(file, "%d\n", r);
  }

  return 0;
}
