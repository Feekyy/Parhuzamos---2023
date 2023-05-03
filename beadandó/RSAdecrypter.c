#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>

unsigned long long n, d;

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
  printf("Checkpoint 1 msg = %llu\n", msg);
  unsigned long long m = pow(msg, d);
  printf("M: %llu\n", m);
  return (fmod(m, n));
}

void decryption()
{
  char ch;
  FILE *fps, *fpt;
  fps = fopen("decryptedText.txt", "w");
  fpt = fopen("encryptedText.txt", "r");
  ch = fgetc(fpt);
  while(ch != EOF)
  {
    ch = getDecrypting(ch);
    printf("CH: %s\n", ch);
    fputc(ch, fps);
    ch = fgetc(fpt);
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
