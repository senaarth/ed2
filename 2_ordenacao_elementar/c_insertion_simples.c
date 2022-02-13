#include <stdio.h>
#include <stdlib.h>

void cmp_exch(int vector[], int i)
{
    if (vector[i] < vector[i - 1])
    {
        int tmp = vector[i - 1];
        vector[i - 1] = vector[i];
        vector[i] = tmp;
    }
}

void sort(int vector[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        for (int j = i; j > l; j--)
        {
            cmp_exch(vector, j);
        }
    }
}

int main()
{
    int *vector = malloc(1000 * sizeof(int));
    int num, i = 0;

    while (scanf("%d ", &num) != EOF)
    {
        vector[i] = num;
        i++;
    }

    sort(vector, 0, i - 1);

    for (int j = 0; j < i; j++)
    {
        if (j == i - 1)
        {
            printf("%d\n", vector[j]);
            break;
        }

        printf("%d ", vector[j]);
    }

    return 0;
}
