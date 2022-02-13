#include <stdio.h>
#include <stdlib.h>

void exchange(int vector[], int min_index, int l)
{
    int tmp = vector[l];
    vector[l] = vector[min_index];
    vector[min_index] = tmp;
}

void sort(int vector[], int l, int r)
{

    for (int i = l; i < r; i++)
    {
        int min = i;

        for (int j = i; j < r; j ++)
        {
            if (vector[j] < vector[min]) min = j;
        }

        exchange(vector, min, i);
    }
}

int main()
{
    int *vector = malloc(sizeof(int));
    int num, i = 1;

    while (scanf("%d ", &num) != EOF)
    {
        vector = realloc(vector, i * sizeof(int));
        vector[i - 1] = num;
        i++;
    }

    sort(vector, 0, i - 1);

    for (int j = 0; j < i - 1; j++)
    {
        if (j == i - 2)
        {
            printf("%d\n", vector[j]);
            break;
        }

        printf("%d ", vector[j]);
    }

    return 0;
}
