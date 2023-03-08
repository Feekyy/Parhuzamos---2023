#include <stdio.h>
#include <stdlib.h>

int main()
{
  int ints[] = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
  long longs[] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  float floats[] ={0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
  intWrite(ints);
}

void intWrite(int ints[])
{
  FILE *fp;
  fp = fopen("ints.txt", "w");
  fwrite(ints, sizeof(int), sizeof(ints), fp);
  fclose(fp);
  return;
}
//void longWrite()
//void floatWrite()
