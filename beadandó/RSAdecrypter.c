#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>

unsigned long long n, d, m;

void fileSearch();
void getKeys();
unsigned long long getDecrypting(unsigned long long msg);
void decryption();

int main()
{
  fileSearch();
  getKeys();
  decryption();

  return 0;
}

unsigned long long getDecrypting(unsigned long long msg)
{
  //printf("Checkpoint 1 msg = %llu\n", msg);
  m = pow(msg, d);
  printf("M1: %llu\n", m);
  m = (fmod(m, n));
  printf("M2: %llu\n", m);
  return m;
}

void decryption()
{
  unsigned long long ch;
  FILE *fps, *fpt;
  fps = fopen("decryptedText.txt", "w");
  fpt = fopen("encryptedText.txt", "r");
  //fscanf(fpt, "%llu\n", &ch);
  while(fscanf(fpt, "%llu\n", &ch) != EOF)
  {
    ch = getDecrypting(ch);
    printf("CH: %llu\n", ch);
    fprintf(fps, "%llu\n", ch);
    //fscanf(fpt, "%llu\n", &ch);
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
  printf("N: %llu D: %llu\n", n, d);
  fclose(read);
}
