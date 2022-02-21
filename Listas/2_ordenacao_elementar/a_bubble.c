#include <stdio.h>
#include <stdlib.h>

void sort(int vector[], int size)
{
    int aux;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (vector[i] < vector[j])
            {
                aux = vector[j];
                vector[j] = vector[i];
                vector[i] = aux;
            }
        }
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

    sort(vector, i - 1);

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
