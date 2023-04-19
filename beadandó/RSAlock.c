#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include <time.h>

char filename[100];
double c, m, e = 2;

void filetest();
void encryption();
int genPrime(int cap);
void keyMaking(int primes1, int prime2);
int leastComMul(int numb1, int numb2);
int modMulInv(int numb1, int numb2);
int getCloseDiv(int numb1, int numb2);

int main()
{
  printf("Random prime: %d", genPrime(1000));

  return 0;
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
    ch += 100;
    fputc(ch, fpt);
    ch = fgetc(fps);
  }
  fclose(fps);
  fclose(fpt);
  printf("%s got encryption!", filename);
}

int genPrime(int cap)
{
  srand(time(NULL));
  bool test = true;
  int random;
  do
  {
    random = rand()+2 % cap;
    test = true;
    for (int i = 2; i < random/2; i++)
    {
      if (random % i == 0)
      {
        test = false;
      }
    }
  } while(!test);
  return random;
}

int leastComMul(int numb1, int numb2)
{
  int max = (numb1 > numb2)? numb1:numb2;
  while(1)
  {
    if (max % numb1 == 0 && max % numb2 == 0)
    {
      return max;
    }
    max++;
  }
}

int modMulInv(int numb1, int numb2)
{
  if (numb1 > numb2)
  {
    for (int i = 1; i < numb1; i++
      {
        if (((numb1 % numb2) * (i * numb1)) % numb1 == 1) return i;
      }
  }
  else
  {
    for (int i = 1; i < numb2; i++
      {
        if (((numb1 % numb2) * (i * numb2)) % numb2 == 1) return i;
      }
  }
}

int getCloseDiv(int numb1, int numb2)
{
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
    int temp;
    while(1)
    {
      temp = numb2 % numb1;
      if (temp == 0) return numb1;
      numb2 = numb1;
      numb1 = temp;
    }
  }
}

void keyMaking(double prime1, double prime2)
{
  srand(time(NULL));
  dobule k = 2;

  double n = prime1 * prime2;
  double f = (prime1-1, prime2-1);

  count = getCloseDiv()
  while (e < f)
  {
    double count = getCloseDiv(e, f);
    if(count = 1) break;
    else e++;
  }

  double d = (1 + (k*f))/e;
  c = pow(msg, e);
  m = pow(c, d);
  c = fmod(c, n);
  m = fmod(m, n)
}
