#include <stdio.h>
#include <stdlib.h>

int main()
{
  int ints[] = {1, 2, 3, 4, 5, 10 ,7, 8, 9, 10};
  long longs[] ={1, 2, 3, 4, 5, 6, 7, 80, 9, 10};
  float floats[] ={0.1, 0.2, 0.3, 0.43, 0.5, 0.6, 0.7, 0.8, 0.9, 1};
  intWrite(ints);
  longWrite(longs);
  floatWrite(floats);
  
  
}

void intWrite(int ints[])
{
  FILE *fp = fopen("ints.txt", "wr");
  for (int i = 0; i < 10; i++)
  {
      fprintf(fp, "%d\n", ints[i]);
  }
  fseek(fp, 0L, SEEK_END);
  long int res = ftell(fp);
  printf("The size of the int's file is %d byte!\n", res);
  fclose(fp);
}

void longWrite(long longs[])
{
  FILE *fp = fopen("longs.txt", "wr");
  for (int i = 0; i < 10; i++)
  {
      fprintf(fp, "%ld\n", longs[i]);
  }
  fseek(fp, 0L, SEEK_END);
  long int res = ftell(fp);
  printf("The size of the long's file is %d byte!\n", res);
  fclose(fp);
}

void floatWrite(float floats[])
{
  FILE *fp = fopen("floats.txt", "wr");
  for (int i = 0; i < 10; i++)
  {
      fprintf(fp, "%.2f\n", floats[i]);
  }
  fseek(fp, 0L, SEEK_END);
  long int res = ftell(fp);
  printf("The size of the float's file is %d byte!\n", res);
  fclose(fp);
}

int[] intRead()
{
    int ints2[10];
    File *fp = fopen("ints.txt", "r+");
    for (int i = 0; i < 10; i++)
    {
        fscanf(fp, "%d", &ints2[i]);
    }
    fprintf("READED");
    fclose(fp);
}
