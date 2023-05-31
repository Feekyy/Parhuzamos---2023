#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

#define MAX 100

unsigned long long n, d, m;

void fileSearch();
void getKeys();
unsigned long long getDecrypting(unsigned long long msg);
void decryption();
unsigned long long modDivision(char dividend[], unsigned long long divisor);

int main()
{
  fileSearch();
  getKeys();
  clock_t begin = clock();
  decryption();
  clock_t stop = clock();
  printf("Time taken by decryption: %f\n", (double)(stop - begin) / CLOCKS_PER_SEC);

  return 0;
}

unsigned long long modDivision(char dividend[], unsigned long long divisor)
{
   unsigned long long temp=0;
   int i=0;

   while(dividend[i])
   {
        temp = temp*10 + (dividend[i] -48);
        if(temp>=divisor)
        {
            temp = temp % divisor;
        }

        i++;
   }

   return temp;
}

unsigned long long getDecrypting(unsigned long long msg)
{
  msg = pow(msg, d);
  char tempch[MAX] = {0};
  ltoa(msg, tempch, 10);
  return modDivision(tempch, n);
}

void decryption()
{
  unsigned long long ch;
  FILE *fps, *fpt;
  fps = fopen("decryptedText.txt", "w");
  fpt = fopen("encryptedText.txt", "r");
  while(fscanf(fpt, "%llu\n", &ch) != EOF)
  {
    ch = getDecrypting(ch);
    if (ch == 0) ch = n;
    fprintf(fps, "%llu\n", ch);
  }
  fclose(fps);
  fclose(fpt);
}

void fileSearch()
{
  if (access("encryptedText.txt", F_OK) == 0 && access("keys.txt", F_OK) == 0)
  {
    printf("I found the files!\n");
  }
  else
  {
    printf("I cannot find the encryted file or the keys!\n");
    exit(0);
  }
}

void getKeys()
{
  FILE *read;
  read = fopen("keys.txt", "r");
  fscanf(read, "%llu\n", &n);
  fscanf(read, "%llu", &d);
  fclose(read);
}
