#include <stdio.h>

int main() {
  int a, n, s = 0;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    s += a;
  }

  printf("%d\n", s);

  return 0;
}
