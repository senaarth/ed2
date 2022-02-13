#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vet[1000000];

int main()
{
    int n, total = 0;

    scanf("%d", &n);

    int list[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (vet[list[i]] != 1)
        {
            vet[list[i]] = 1;
            total++;
        }
    }

    printf("%d\n", total);

    return 0;
}