#include <stdio.h>

int main() {
  int a, n;

  for (n = 0; scanf("%d", &a) != EOF; n++);

  printf("%d\n", n);

  return 0;
}
