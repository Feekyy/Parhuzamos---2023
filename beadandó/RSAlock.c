#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include <time.h>

char filename[100];
unsigned long long c, n, d, e = 2;

void filetest();
void encryption();
unsigned long long genPrime(unsigned long long cap);
void keyMaking(unsigned long long primes1, unsigned long long prime2);
unsigned long long getCloseDiv(unsigned long long numb1, unsigned long long numb2);
unsigned long long getEncryption(unsigned long long msg);
void keysToFile();

int main()
{
  filetest();
  keyMaking(3, 4);
  encryption();
  keysToFile();

  return 0;
}

void keysToFile()
{
  FILE *file;
  file = fopen("keys.txt", "w");
  fprintf(file, "%llu\n", n);
  fprintf(file, "%llu\n", d);
  fclose(file);
}

void filetest()
{
  bool test = false;
  do
  {
      printf("Give me the name of the file: ");
      scanf("%s", &filename);
      strcat(filename, ".txt");
      if (access(filename, F_OK) == 0)
      {
        printf("I found the file!\n");
        test = true;
      }
      else
      {
        printf("I cannot find the file!\n");
      }
  } while(!test);
}

void encryption()
{
  char ch;
  FILE *fps, *fpt;
  fps = fopen(filename, "r");
  fpt = fopen("encryptedText.txt", "w");
  ch = fgetc(fps);
  while (ch != EOF)
  {
    ch = getEncryption(ch);
    fputc(ch, fpt);
    ch = fgetc(fps);
  }
  fclose(fps);
  fclose(fpt);
  printf("%s got encryption!", filename);
}

unsigned long long genPrime(unsigned long long cap)
{
  srand(time(NULL));
  bool test = true;
  unsigned long long random;
  do
  {
    random = rand()+2 % cap;
    test = true;
    for (unsigned long long i = 2; i < random/2; i++)
    {
      if (random % i == 0)
      {
        test = false;
      }
    }
  } while(!test);
  return random;
}

unsigned long long getCloseDiv(unsigned long long numb1, unsigned long long numb2)
{
  int temp;
  if (numb1 > numb2)
  {
    while(1)
    {
      temp = numb1 % numb2;
      if (temp == 0) return numb2;
      numb1 = numb2;
      numb2 = temp;
    }
  }
  else
  {
    while(1)
    {
      temp = numb2 % numb1;
      if (temp == 0) return numb1;
      numb2 = numb1;
      numb1 = temp;
    }
  }
}

unsigned long long getEncryption(unsigned long long msg)
{
  c = pow(msg, e);
  return fmod(c, n);
}

void keyMaking(unsigned long long prime1, unsigned long long prime2)
{
  unsigned long long count, k = 2;

  n = prime1 * prime2;
  unsigned long long f = ((prime1-1)*(prime2-1));

  while (e < f)
  {
    count = getCloseDiv(e, f);
    if(count == 1)
      break;
    else
      e++;
  }

  d = (1 + (k*f))/e;
}
