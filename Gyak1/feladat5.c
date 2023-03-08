#include <stdio.h>
#include <time.h>

int main()
{
  int r, top, bot;
  top = input();
  do
  {
    bot = input();
    printf("Wrong input!");
  } while(bot > top+1);

  srand(time(NULL));
  r = rand() % top + bot;

  printf("Your random number is %d beetwin %d and %d!", r, bot, top);

  return 0;
}

int input()
{
    int n;
    printf("Please enter an integer: ");
    while(scanf("%d",&n) != 1)
    {
        printf("Please enter an integer: ");
        while(getchar() != '\n');
    }
    return n;
}
