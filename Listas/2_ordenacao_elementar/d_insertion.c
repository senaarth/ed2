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
    for (int i = r; i > l; i--)
    {
        cmp_exch(vector, i);
    }

    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        int tmp = vector[j];

        while (tmp < vector[j - 1])
        {
            vector[j] = vector[j - 1];
            j--;
        }

        vector[j] = tmp;
    }
}

int main()
{
    int *vector = malloc(50000 * sizeof(int));
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
