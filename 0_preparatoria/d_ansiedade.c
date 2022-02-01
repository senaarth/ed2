#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char input[4];
  int triagem = 0, positivo = 0;

  for (int i = 1; scanf(" %s", input) != EOF; i++)
  {
    if (strcmp(input, "sim") == 0)
    {
      positivo++;
    }

    if (i % 10 == 0)
    {

      if (positivo >= 2)
      {
        triagem++;
      }

      positivo = 0;
    }
  }

  printf("%d\n", triagem);

  return 0;
}
