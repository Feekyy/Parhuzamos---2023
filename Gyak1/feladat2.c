#include <stdio.h>
#include <stdbool.h>

int main ()
{
   int input, count = 0, alt, j;
   bool ok = false;
   char number1[8];
   char number2[8];
   int numberArray[count];

   do
   {
     printf("Enter A maximal 8 length number: ");
     scanf("%d", &input);
     if (input < 100000000)
        {
          ok = true;
        }
   } while (!ok);

   while (input != 0)
   {
     numberArray[count] = input % 10;
     input /= 10;
     count++;
   }
   alt = 8 - count;
   for (int i = 8; i > -1; i--)
   {
     if (i > alt)
     {
       number1[i] = numberArray[count]+'0';
       number2[i] = numberArray[count]+'0';
       count--;
     }
     else
     {
       number1[i] = ' ';
       number2[i] ='0';
     }
   }

   printf("The nubmer after scanning and start with spaces: %s\n", number1);
   printf("The nubmer after scanning and start with zeros: %s\n", number2);
   return(0);
}
