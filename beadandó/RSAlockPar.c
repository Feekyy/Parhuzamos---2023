#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>

#ifdef _WIN32
#include <io.h>
#define access _access
#else
#include <unistd.h>
#endif

#define MAX 100

char filename[MAX];
unsigned long long c, n, d, e = 2;
bool keyMakingDone = false;

void filetest();
void encryption();
unsigned long long genPrime(unsigned long long cap);
void* keyMakingForThread(void* arg);
void* keysToFileForThread(void* arg);
void keyMaking(unsigned long long prime1, unsigned long long prime2);
unsigned long long getCloseDiv(unsigned long long numb1, unsigned long long numb2);
unsigned long long getEncryption(unsigned long long msg);
unsigned long long modDivision(char dividend[], unsigned long long divisor);

int main(int argc, char *argv[])
{
  filetest();

  pthread_t keyMakingThread, keysToFileThread;

  pthread_create(&keyMakingThread, NULL, keyMakingForThread, NULL);

  clock_t begin = clock();
  encryption();
  clock_t stop = clock();

  pthread_create(&keysToFileThread, NULL, keysToFileForThread, NULL);

  pthread_join(keyMakingThread, NULL);
  pthread_join(keysToFileThread, NULL);

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

void* keysToFileForThread(void* arg)
{
  while (!keyMakingDone)
  {
  }

  FILE *file;
  file = fopen("keys.txt", "w");
  fprintf(file, "%llu\n", n);
  fprintf(file, "%llu\n", d);
  fclose(file);

  pthread_exit(NULL);
}

void* keyMakingForThread(void* arg)
{
  keyMaking(2, 5);
  keyMakingDone = true;

  pthread_exit(NULL);
}

void filetest()
{
  bool test = false;
  do
  {
      printf("Give me the name of the file: ");
      scanf("%s", &filename);
      strcat(filename, ".txt");
      if (access(filename, 0) == 0)
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
  unsigned long long ch;
  FILE *fps, *fpt;
  fps = fopen(filename, "r");
  fpt = fopen("encryptedText.txt", "w");

  double start_time = omp_get_wtime();

  #pragma omp parallel private(ch)
  {
    while (fscanf(fps, "%llu\n", &ch) != EOF)
    {
      ch = getEncryption(ch);
      #pragma omp critical
      {
        fprintf(fpt, "%llu\n", ch);
      }
    }
  }

  double end_time = omp_get_wtime();
  double execution_time = end_time - start_time;

  fclose(fps);
  fclose(fpt);
  printf("%s got encryption!\n", filename);
  printf("Encryption execution time: %f seconds\n", execution_time);
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
  msg = pow(msg, e);
  char tempch[MAX] = {0};
  ltoa(msg, tempch, 10);
  return modDivision(tempch, n);
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
