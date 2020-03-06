//
// Tomás Oliveira e Silva, AED, September 2014, September 2017
//
// program to print a table of the squares and square roots of some integers
//
// on GNU/Linux, run the command
//   man 3 printf
// to see how the manual page of the printf function
//

#include <math.h>
#include <stdio.h>

void do_it(int N)
{
  int i;
  FILE *f = fopen("table.txt", "w");

  fprintf(f, " cos(n)  sin(n)\n");
  fprintf(f, "-- --- -----------------\n");
  for(i = 1;i <= N;i++)
    fprintf(f, "%4f %4f \n",cos((double)(i*M_PI/180.0)),sin((double)(i*M_PI/180.0)));

    fclose(f);
}

int main(void)
{
  do_it(90);
  return 0;
}
